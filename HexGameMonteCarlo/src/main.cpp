/*
Created: Jan 20 2019
Author: Thomas Gilmour
*/

#include <HexGame.hpp>
#include <iostream>
#include <limits>

int main()
{
	/*	int size;
	std::shared_ptr<HexPlayer> p1, p2;

	std::cout << "Welcome to a game of Hex!\n";
	std::cout << "The board will be NxN in size, what would you like N to be?\n";
	read_input(size);
	std::shared_ptr<HexGameBoard> board(new HexGameBoard(size));
	std::cout << "Time for Player 1 to register...\n";
	std::cout << "AI? (y/n)\n";
	char answer;
	read_input(answer);
	if(answer == 'y'){
		std::cout << "Player 1: Jeremy\n";
		p1 = std::make_shared<MCPlayer>(board,OwnerID::PLAYER1,"Jeremy");
	}
	else{
		std::cout << "what's your name?\n";
		std::string name;
			read_input(name);
		p1 = std::make_shared<HumanPlayer>(board,OwnerID::PLAYER1,name);
	}
	std::cout << "Time for Player 2 to register...\n";
	std::cout << "AI? (y/n)\n";
	read_input(answer);
	if(answer == 'y'){
		std::cout << "Player 2: Barry\n";
		p2 = std::make_shared<MCPlayer>(board,OwnerID::PLAYER2,"Barry");
	}
	else{
		std::cout << "what's your name?\n";
		std::string name;
		read_input(name);
		p2 = std::make_shared<HumanPlayer>(board,OwnerID::PLAYER2,name);
	}
	HexGame hex(board,p1,p2); */
	HexGame hex = HexGame::hex_game_init();

	while (!hex.is_finished())
	{
		hex.next_turn();
	}

	return 0;
}
