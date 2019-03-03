/*
Created: Feb 3 2019
Author: Thomas Gilmour
Description: Union find with path compression
*/

#pragma once

#include <vector>

class UnionFind
{

  public:
    UnionFind(const int size) : id(size),
                                sz(size, 1)
    {
        for (int i = 0; i < size; i++)
            id[i] = i;
    };

    /// @param[in] s , source vertice
    /// @param[in] p , target vertice
    /// @return true if vertices s and p are connected
    bool is_connected(const int s, const int p);

  protected:
    /// connects vertice s and p
    /// @param[in] s , source vertice
    /// @param[in] p , target vertice
    void connect(const int s, const int p);

  private:
    /// returns the root vertice of the tree that holds vertice s
    /// @param[in] s , source vertice
    /// @return root vertice of s
    int find(int s);

    /// parent vertices of each node
    std::vector<int> id;

    /// size of subtree including itself
    std::vector<int> sz;
};
