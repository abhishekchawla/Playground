#pragma once
#include "Header.h"
/*Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3*/

class numOfIslands {

	int rowCount = 0, colCount = 0;
	vector<vector<bool>> visited;
	void spanIsland(const int i, const int j,  vector<vector<char>>& grid)
	{
		if (i >= 0 && i < rowCount && j >= 0 && j < colCount && grid[i][j] - '0')
		{
			grid[i][j] = '0';
			spanIsland(i + 1, j, grid);
			spanIsland(i, j + 1, grid);
			spanIsland(i - 1, j, grid);
			spanIsland(i, j - 1, grid);
		}
	}

public:

	int numIslands(vector<vector<char>>& grid)
	{
		int numOfislands = 0;

		if (!grid.size())
			return numOfislands;

		rowCount = grid.size();
		colCount = grid[0].size();

		visited.resize(rowCount, vector<bool>(colCount, false));

		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				if (grid[i][j] - '0')
				{
					++numOfislands;
					grid[i][j] = '0';
					spanIsland(i + 1, j, grid);
					spanIsland(i, j + 1, grid);
					spanIsland(i - 1, j, grid);
					spanIsland(i, j - 1, grid);
				}
			}
		}

		return numOfislands;
	}
};



