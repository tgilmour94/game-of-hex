/*
Created: Jan 20 2019
Author: Thomas Gilmour
*/

#pragma once

#include <HumanPlayer.hpp>
#include <MCPlayer.hpp>
#include <memory>

class HexGame
{
public:
	HexGame(const std::shared_ptr<HexGameBoard> board, std::shared_ptr<HexPlayer> player1, std::shared_ptr<HexPlayer> player2) : _board(board),
																																																															 _players{player1, player2}
	{
	}

	/// continues with the next_player turn
	void next_turn(void);

	/// @return true if the game is finished
	bool is_finished(void);

	/// requests input from the user in order to initialize the game
	/// @return instance of HexGame with parameters set by the user
	static HexGame hex_game_init(void);

private:
	const std::shared_ptr<HexGameBoard> _board;

	const std::vector<std::shared_ptr<HexPlayer>> _players;

	OwnerID next_player = OwnerID::PLAYER1;
};
