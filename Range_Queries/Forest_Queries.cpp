#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ll n{}, q{};
  cin >> n >> q;
  vector<vector<bool>> grid(n, vector<bool>(n, false));
  for (int i{0}; i < n; ++i)
    for (int j{0}; j < n; ++j)
    {
      char c{};
      cin >> c;
      grid[i][j] = c == '*';
    }

  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  for (int i{0}; i < n; ++i)
  {
    for (int j{0}; j < n; ++j)
    {
      if (i == 0 && j == 0)
        dp[i][j] = grid[i][j];
      else if (i == 0)
        dp[i][j] = grid[i][j] + dp[i][j - 1];
      else if (j == 0)
        dp[i][j] = grid[i][j] + dp[i - 1][j];
      else
        dp[i][j] = grid[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
    }
  }

  while (q--)
  {
    ll y1{}, x1{}, y2{}, x2{};
    cin >> y1 >> x1 >> y2 >> x2;
    --y1;
    --x1;
    --y2;
    --x2;
    if (y1 == 0 && x1 == 0)
      cout << dp[y2][x2] << '\n';
    else if (y1 == 0)
      cout << dp[y2][x2] - dp[y2][x1 - 1] << '\n';
    else if (x1 == 0)
      cout << dp[y2][x2] - dp[y1 - 1][x2] << '\n';
    else
      cout << dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1] << '\n';
  }

  return 0;
}