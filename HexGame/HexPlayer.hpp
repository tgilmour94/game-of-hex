/*
Created: Jan 20 2019
Author: Thomas Gilmour
*/
#pragma once

#include <HexGameBoard.hpp>
#include <memory>
#include <string>
#include <iostream>

class HexPlayer
{
public:
	HexPlayer(const std::shared_ptr<HexGameBoard> board, const OwnerID id, const std::string name)
			: _board(board),
				_id(id),
				_name(name) {}

	virtual ~HexPlayer(void){};

	///@return id of Player (NONE, PLAYER1, or PLAYER2)
	const OwnerID get_id(void)
	{
		return _id;
	}

	void print_name(void)
	{
		std::cout << _name;
	}

	/// Player will generate a target location and then occupy the location
	virtual void generate_move(void) = 0;

protected:
	const std::string _name;
	const OwnerID _id;
	const std::shared_ptr<HexGameBoard> _board;
};
