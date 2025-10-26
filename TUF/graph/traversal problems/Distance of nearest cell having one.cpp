// distance calculation is given by |i1 - i2| + |j1 - j2|,
/*
  1 <= N, M <= 500
  grid[i][j] == 0 or 1
There is atleast one 1 in the grid
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  vector<int> delRow = {-1, 0, 1, 0};
  vector<int> delCol = {0, 1, 0, -1};

  bool isValid(int &i, int &j, int &n, int &m)
  {

    if (i < 0 || i >= n)
      return false;
    if (j < 0 || j >= m)
      return false;

    return true;
  }

public:
  vector<vector<int>> nearest(vector<vector<int>> grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));

    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 1)
        {
          q.push({{i, j}, 0});
          vis[i][j] = 1;
        }
        else
        {
          vis[i][j] = 0;
        }
      }
    }
    // traverse till queue become empty
    while (!q.empty())
    {
      auto it = q.front();
      q.pop();
      // FIFO: get the earliest inserted element.
      // That guarantees BFS processes cells in non-decreasing order of distance
      int row = it.first.first;
      int col = it.first.second;
      /*

      FIFO: get the earliest inserted element.
     That guarantees BFS processes cells in non-decreasing order of distance*/
      int steps = it.second;
      dist[row][col] = steps;

      for (int i = 0; i < 4; i++)
      {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if (isValid(nRow, nCol, n, m) &&
            vis[nRow][nCol] == 0)
        {
          vis[nRow][nCol] = 1;
          q.push({{nRow, nCol}, steps + 1});
        }
      }
    }
    return dist;
  }
};