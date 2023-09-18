#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll mod{1'000'000'007};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n{};
  cin >> n;

  vector<vector<char>> grid(n, vector<char>(n));
  for (auto &row : grid)
    for (auto &cell : row)
      cin >> cell;

  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  dp[0][0] = grid[0][0] == '.';
  for (int i{0}; i < n; ++i)
  {
    for (int j{0}; j < n; ++j)
    {
      if (grid[i][j] == '*')
        continue;
      if (i != 0)
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
      if (j != 0)
        dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
    }
  }

  cout << dp[n-1][n-1] << '\n';

  return 0;
}