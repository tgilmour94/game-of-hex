/*
Created: Jan 29 2019
Author: Thomas Gilmour
*/

#include <MCPlayer.hpp>
#include <algorithm>

void MCPlayer::generate_move(void)
{
    double max_win_rate = -1.0;
    int max_x, max_y;
    auto free_spaces = std::move(get_available_spaces());

    std::vector<std::future<double>> win_rate(free_spaces.size());

    /// start asynchronous simulations at each free space on the board
    int i = 0;
    for (auto &rate : win_rate)
    {
        rate = std::async(std::launch::async, &MCPlayer::sim_game, this, free_spaces[i++], free_spaces);
    }

    for (int j = 0; j < win_rate.size(); j++)
    {
        double probability = win_rate[j].get();
        if (probability > max_win_rate)
        {
            max_win_rate = probability;
            max_x = free_spaces[j] % size;
            max_y = free_spaces[j] / size;
        }
    }

    _board->take_hexagon(max_x, max_y, _id);
}

double MCPlayer::sim_game(int loc, std::vector<int> shuffled_locations)
{
    int start_x = loc % size;
    int start_y = loc / size;
    int wins = 0;
    for (int i = 0; i < NUMSIMS; i++)
    {
        HexGameBoard temp_board(*_board);
        bool my_turn = false;
        temp_board.take_hexagon(start_x, start_y, _id);
        std::shuffle(shuffled_locations.begin(), shuffled_locations.end(), _engine);
        for (int space : shuffled_locations)
        {
            if (space != loc)
            {
                int x = space % size;
                int y = space / size;
                if (my_turn)
                {
                    temp_board.take_hexagon(x, y, _id);
                    my_turn = !my_turn;
                }
                else
                {
                    temp_board.take_hexagon(x, y, _opp_id);
                    my_turn = !my_turn;
                }
            }
        }
        if (temp_board.is_winner(_id))
            wins++;
    }
    return static_cast<double>(wins) / NUMSIMS;
}

std::vector<int> MCPlayer::get_available_spaces(void)
{
    std::vector<int> available;
    int i = 0;
    auto temp_board = std::move(_board->get_board_occupancy());
    for (auto id : temp_board)
    {
        if (id == OwnerID::NONE)
            available.push_back(i);
        i++;
    }
    return available;
}