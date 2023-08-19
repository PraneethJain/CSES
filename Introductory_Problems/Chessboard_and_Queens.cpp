#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool grid[8][8];
ll ans{0};
set<pair<int, int>> placed{};

void print_grid()
{
  cout << "Current grid status" << '\n';
  for (int i{0}; i < 8; ++i)
  {
    for (int j{0}; j < 8; ++j)
      cout << grid[i][j];
    cout << '\n';
  }
}

bool can_place(int i, int j)
{
  for (const auto &coord : placed)
  {
    auto [x, y] = coord;
    if (x == i || y == j)
      return false;

    if (abs(x - i) == abs(y - j))
      return false;
  }

  return true;
}

void dfs(int num_queens)
{
  if (num_queens == 8)
  {
    ++ans;
    return;
  }

  for (int i{0}; i < 8; ++i)
  {
    bool found{false};
    for (int j{0}; j < 8; ++j)
    {
      if (grid[i][j] && can_place(i, j))
      {
        found = true;
        placed.emplace(i, j);
        dfs(num_queens + 1);
        placed.erase({i, j});
      }
    }
    if (not found)
      return;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  char c;
  for (int i{0}; i < 8; ++i)
    for (int j{0}; j < 8; ++j)
    {
      cin >> c;
      grid[i][j] = c == '.';
    }

  dfs(0);
  cout << ans << '\n';

  return 0;
}
