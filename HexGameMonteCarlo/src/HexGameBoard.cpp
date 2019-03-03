/*
Created: Jan 20 2019
Author: Thomas Gilmour
*/

#include <HexGameBoard.hpp>
#include <string>

const bool HexGameBoard::take_hexagon(const int x, const int y, const OwnerID id)
{
	if (!range_check(x, y))
	{
		std::cout << "The coordinates you have chosen are not valid" << std::endl;
		return false;
	}
	if (id == OwnerID::NONE)
		return false;

	if (owns_hexagon(x, y, OwnerID::NONE))
	{
		hexagons[convert_coords(x, y)] = id;
		connect_neighbour_hexagons(x, y, id);
		return true;
	}
	std::cout << "This coordinate is occupied x,y " << x << "," << y << std::endl;
	return false;
}

std::vector<OwnerID> HexGameBoard::get_board_occupancy(void) const
{
	std::vector<OwnerID> occupancy(hexagons);
	return occupancy;
}

const bool HexGameBoard::is_winner(const OwnerID id)
{
	if (id == OwnerID::PLAYER1)
		return is_connected(player_one_domains.first, player_one_domains.second);
	else if (id == OwnerID::PLAYER2)
		return is_connected(player_two_domains.first, player_two_domains.second);
	else
		return false;
}

const bool HexGameBoard::owns_hexagon(const int x, const int y, const OwnerID id) const
{
	if (range_check(x, y))
	{
		return hexagons[convert_coords(x, y)] == id;
	}
	return false;
}

const int HexGameBoard::convert_coords(const int x, const int y) const
{
	return x + (y * size);
}

const bool HexGameBoard::range_check(const int x, const int y) const
{
	if (x >= size || y >= size || x < 0 || y < 0)
	{
		return false;
	}
	return true;
}

void HexGameBoard::connect_neighbour_hexagons(const int x, const int y, const OwnerID id)
{
	//check surrounding valid game hexagons to see if owned by id, if true connect the two
	if (owns_hexagon(x, y + 1, id))
		connect(convert_coords(x, y), convert_coords(x, y + 1));
	if (owns_hexagon(x, y - 1, id))
		connect(convert_coords(x, y), convert_coords(x, y - 1));
	if (owns_hexagon(x + 1, y, id))
		connect(convert_coords(x, y), convert_coords(x + 1, y));
	if (owns_hexagon(x - 1, y, id))
		connect(convert_coords(x, y), convert_coords(x - 1, y));
	if (owns_hexagon(x + 1, y + 1, id))
		connect(convert_coords(x, y), convert_coords(x + 1, y + 1));
	if (owns_hexagon(x - 1, y - 1, id))
		connect(convert_coords(x, y), convert_coords(x - 1, y - 1));

	//connect any border hexagon to the ids start/end domain ie) top border connects to player1 domain
	if (id == OwnerID::PLAYER1)
	{
		if (y == 0)
			connect(convert_coords(x, y), player_one_domains.first);
		if (y == size - 1)
			connect(convert_coords(x, y), player_one_domains.second);
	}
	if (id == OwnerID::PLAYER2)
	{
		if (x == 0)
			connect(convert_coords(x, y), player_two_domains.first);
		if (x == size - 1)
			connect(convert_coords(x, y), player_two_domains.second);
	}
}

std::ostream &operator<<(std::ostream &os, const HexGameBoard &board)
{
	std::vector<std::string> print_stack;
	for (int i = 0; i < board.size; i++)
	{
		std::string s;
		//setting the space indentation
		for (int r = 0; r < 2 * (board.size - i); r++)
		{
			s.append(" ");
		}

		//appending characters
		for (int j = 0; j < board.size; j++)
		{

			int coord = (i * board.size) + j;
			OwnerID temp = board.hexagons[coord];
			if (temp == OwnerID::NONE)
			{
				if (j == board.size - 1)
				{
					s.append(".");
				}
				else
				{
					s.append(". - ");
				}
			}
			else if (temp == OwnerID::PLAYER1)
			{
				if (j == board.size - 1)
				{
					s.append("X");
				}
				else
				{
					s.append("X - ");
				}
			}
			else
			{
				if (j == board.size - 1)
				{
					s.append("O");
				}
				else
				{
					s.append("O - ");
				}
			}
		}
		s.append("\n");
		print_stack.push_back(s);
		s.erase();

		if (i != board.size - 1)
		{

			for (int r = 0; r < 2 * (board.size - i) - 1; r++)
			{
				s.append(" ");
			}
			for (int k = 0; k < board.size; k++)
			{
				if (k == board.size - 1)
				{
					s.append("\\");
				}
				else
				{
					s.append("\\ /");
					s.append(" ");
				}
			}
			s.append("\n");
			print_stack.push_back(s);
		}
	}
	while (!print_stack.empty())
	{
		os << print_stack.back();
		print_stack.pop_back();
	}
	os << "(x=0,y=0)  <.....>  (x=N,y=0)\n";
	return os;
}