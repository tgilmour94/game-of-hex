//HumanPlayer.cpp
#include <HumanPlayer.hpp>
#include <iostream>

void HumanPlayer::generate_move()
{
	int x;
	int y;
	print_name();
	std::cout << ", please enter the coordinates of your next move (x,y)" << std::endl;
	user_input::read_input(x);
	user_input::read_input(y);
	while (!_board->take_hexagon(x, y, _id))
	{
		print_name();
		std::cout << ", please enter the coordinates of your next move (x,y)" << std::endl;
		user_input::read_input(x);
		user_input::read_input(y);
	}
}
