/*
Created: Jan 20 2019
Author: Thomas Gilmour
*/

#include <HexGame.hpp>

void HexGame::next_turn()
{
	std::cout << *_board;
	if (next_player == OwnerID::PLAYER1)
	{
		_players[0]->generate_move();
		next_player = OwnerID::PLAYER2;
	}
	else
	{
		_players[1]->generate_move();
		next_player = OwnerID::PLAYER1;
	}
}

bool HexGame::is_finished()
{
	for (auto p : _players)
	{
		if (_board->is_winner(p->get_id()))
		{
			std::cout << *_board;
			std::cout << "Congratulations ";
			p->print_name();
			std::cout << " you win!" << std::endl;

			std::cout << "GAMEOVER" << std::endl;
			return true;
		}
	}
	return false;
}

HexGame HexGame::hex_game_init(void)
{

	int size;
	std::shared_ptr<HexPlayer> p1, p2;

	std::cout << "Welcome to a game of Hex!\n";
	std::cout << "The board will be NxN in size, what would you like N to be?\n";
	user_input::read_input(size);
	std::shared_ptr<HexGameBoard> board(new HexGameBoard(size));
	std::cout << "Time for Player 1 to register...\n";
	std::cout << "AI? (y/n)\n";
	char answer;
	user_input::read_input(answer);
	if (answer == 'y')
	{
		std::cout << "Player 1: Jeremy\n";
		p1 = std::make_shared<MCPlayer>(board, OwnerID::PLAYER1, "Jeremy");
	}
	else
	{
		std::cout << "what's your name?\n";
		std::string name;
		user_input::read_input(name);
		p1 = std::make_shared<HumanPlayer>(board, OwnerID::PLAYER1, name);
	}
	std::cout << "Time for Player 2 to register...\n";
	std::cout << "AI? (y/n)\n";
	user_input::read_input(answer);
	if (answer == 'y')
	{
		std::cout << "Player 2: Barry\n";
		p2 = std::make_shared<MCPlayer>(board, OwnerID::PLAYER2, "Barry");
	}
	else
	{
		std::cout << "what's your name?\n";
		std::string name;
		user_input::read_input(name);
		p2 = std::make_shared<HumanPlayer>(board, OwnerID::PLAYER2, name);
	}
	HexGame hex(board, p1, p2);
	return hex;
}
//} // namespace game