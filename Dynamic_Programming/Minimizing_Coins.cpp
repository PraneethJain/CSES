#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n{}, x{};
  cin >> n >> x;

  vector<int> coins(n);
  for (auto &coin : coins)
    cin >> coin;

  vector<int> dp(x + 1, numeric_limits<int>::max() - 1);
  dp[0] = 0;
  for (int i{1}; i <= x; ++i)
    for (const auto &coin : coins)
      if (i - coin >= 0)
        dp[i] = min(dp[i], dp[i - coin] + 1);

  cout << (dp[x] == numeric_limits<int>::max() - 1 ? -1 : dp[x]) << '\n';

  return 0;
}