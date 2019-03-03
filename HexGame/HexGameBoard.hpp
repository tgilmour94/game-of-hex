/*
Created: Jan 20 2019
Author: Thomas Gilmour
*/

#pragma once

#include <UnionFind.hpp>
#include <iostream>

///enumeration class for all owner types
enum class OwnerID
{
	NONE,
	PLAYER1,
	PLAYER2,
};

class HexGameBoard : public UnionFind
{
  public:
	HexGameBoard(const int n) : UnionFind((n * n) + 4), //4 extra spots for left, right, top, and bottom domains of the board
								size(n),
								hexagons(n * n, OwnerID::NONE),
								player_one_domains((n * n), (n * n) + 1),
								player_two_domains((n * n) + 2, (n * n) + 3)
	{
	}
	/// attempts to claim hexagon (x,y) for OwnerID id
	/// @param[in] x , x coordinate of hexagon
	/// @param[in] y , y coordinate of hexagon
	/// @param[in] id , OwnerID of the hexagon
	/// @return true if hexagon(x,y) was successfully taken by owner id
	const bool take_hexagon(const int x, const int y, const OwnerID id);

	/// prints a ASCII representation of the gameboard to std output
	friend std::ostream &operator<<(std::ostream &os, const HexGameBoard &board);

	/// returns the current status of each location on the game board
	/// @return a vector representation of the boards hexagons and their owners
	std::vector<OwnerID> get_board_occupancy(void) const;

	/// checks to see if OwnerID id id has won the game
	/// @param[in] id , OwnerID of the hexagon
	/// @return true if OwnerID id has won the game
	const bool is_winner(OwnerID id);

	/// @return the # of columns/rows of the board
	const int board_size(void)
	{
		return size;
	}

	/// checks if hexagon(x,y) is owned by id
	/// @param[in] x , x coordinate of hexagon
	/// @param[in] y , y coordinate of hexagon
	/// @param[in] id , OwnerID of the hexagon
	/// @return true if id is the OwnerID corresponding to hexagon(x,y)
	const bool owns_hexagon(int x, int y, OwnerID id) const;

	/// converts x,y to vector index
	/// @param[in] x , x coordinate of hexagon
	/// @param[in] y , y coordinate of hexagon
	/// @return integer value of vector index that corresponds to (x,y)
	const int convert_coords(int x, int y) const;

  private:
	/// connects hexagon(x,y) to surrounding hexagons owned by id
	/// @param[in] x , x coordinate of hexagon
	/// @param[in] y , y coordinate of hexagon
	/// @param[in] id , OwnerID of the hexagon
	void connect_neighbour_hexagons(const int x, const int y, const OwnerID id);

	/// checks if coordinate(x,y) is in range
	/// @param[in] x , x coordinate of hexagon
	/// @param[in] y , y coordinate of hexagon
	/// @return true if (x,y) is in range
	const bool range_check(const int x, const int y) const;

	/// number of columns/rows of gameboard
	const int size;

	/// each players sides of the board are indexed within the UnionFind
	const std::pair<const int, const int> player_two_domains;
	const std::pair<const int, const int> player_one_domains;

	/// ownership of each hexagon on the board
	std::vector<OwnerID> hexagons;
};
