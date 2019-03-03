/*
Created: Jan 20 2019
Author: Thomas Gilmour
*/
#pragma once

#include <HexPlayer.hpp>
#include <limits>

class HumanPlayer : public HexPlayer
{
public:
	HumanPlayer(const std::shared_ptr<HexGameBoard> board, const OwnerID id, const std::string name)
			: HexPlayer(board, id, name) {}

	void generate_move(void) override;
};

namespace user_input
{
template <class T>
void read_input(T &u)
{
	while (!(std::cin >> u))
	{
		std::cin.clear();																										//clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input; please re-enter.\n";
	}
}
} // namespace user_input