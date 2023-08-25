#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N{9};
bool vis[N][N];
string s{};

int dfs(int x, int y, int count)
{
  if ((vis[x + 1][y] && vis[x - 1][y] && !vis[x][y + 1] && !vis[x][y - 1]) ||
      (vis[x][y + 1] && vis[x][y - 1] && !vis[x + 1][y] && !vis[x - 1][y]))
    return 0;

  if ((count == (N - 2) * (N - 2) - 1) && (x == N - 2 && y == 1))
    return 1;
  else if ((count == (N - 2) * (N - 2) - 1) || (x == N - 2 && y == 1))
    return 0;

  vis[x][y] = true;
  int res{0};
  if (s[count] == 'L' && !vis[x][y - 1])
    res += dfs(x, y - 1, count + 1);
  else if (s[count] == 'D' && !vis[x + 1][y])
    res += dfs(x + 1, y, count + 1);
  else if (s[count] == 'R' && !vis[x][y + 1])
    res += dfs(x, y + 1, count + 1);
  else if (s[count] == 'U' && !vis[x - 1][y])
    res += dfs(x - 1, y, count + 1);
  else if (s[count] == '?')
  {
    for (auto [dx, dy] : {pair{0, -1}, pair{1, 0}, pair{0, 1}, pair{-1, 0}})
    {
      if (vis[x + dx][y + dy])
        continue;
      res += dfs(x + dx, y + dy, count + 1);
    }
  }
  vis[x][y] = false;

  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int i{0}; i < N; ++i)
    for (int j{0}; j < N; ++j)
      vis[i][j] = false;

  for (int i{0}; i < N; ++i)
    vis[i][N - 1] = vis[N - 1][i] = vis[0][i] = vis[i][0] = true;

  cin >> s;
  int res{dfs(1, 1, 0)};

  cout << res << '\n';

  return 0;
}
