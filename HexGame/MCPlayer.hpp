/*
Created: Jan 29 2019
Author: Thomas Gilmour
*/
#pragma once
#include <HexPlayer.hpp>
#include <chrono>
#include <random>
#include <future>
#include <thread>

class MCPlayer : public HexPlayer
{
  public:
    MCPlayer(const std::shared_ptr<HexGameBoard> board, const OwnerID id, const std::string name)
        : HexPlayer(board, id, name),
          size(board->board_size()),
          _engine(std::chrono::system_clock::now().time_since_epoch().count())
    {
        if (_id == OwnerID::PLAYER1)
            _opp_id = OwnerID::PLAYER2;
        else
            _opp_id = OwnerID::PLAYER1;
    }

    /// AI will generate a target location and then occupy the location
    void generate_move(void) override;

  private:
    /// simulates NUMSIMS games with the first move being location loc
    /// @param[in] loc , the MCPlayer will choose this location as its first
    /// move in the simulation
    /// @param[in] shuffled_locations , a list of the next moves to be made by
    /// each player in the simulated game - all locations are available
    /// @return double, win percentage of NUMSIMS simulations where MCPlayer
    /// makes its first move at location loc
    double sim_game(int loc, std::vector<int> shuffled_locations);

    /// returns a list of available locations represented by their index
    /// @return list of available locations
    std::vector<int> get_available_spaces(void);

    static constexpr int NUMSIMS = 10000;

    const int size;

    std::default_random_engine _engine;

    OwnerID _opp_id;
};
