/*
Created: Feb 3 2019
Author: Thomas Gilmour
*/

#include <UnionFind.hpp>
#include <iostream>

bool UnionFind::is_connected(const int s, const int p)
{
    return find(s) == find(p);
}

void UnionFind::connect(const int s, const int p)
{
    int i = find(s);
    int j = find(p);
    if (i == j)
        return;
    if (sz[i] < sz[j])
    {
        id[i] = j;
        sz[j] += sz[i];
    }
    else
    {
        id[j] = i;
        sz[i] += sz[j];
    }
}

int UnionFind::find(int s)
{
    int first = s;
    while (id[s] != s)
    {
        s = id[s];
    }
    while (id[first] != s)
    {
        /// tree flattening
        int temp = first;
        first = id[first];
        id[temp] = s;
        sz[temp] = 1;
    }
    return s;
}