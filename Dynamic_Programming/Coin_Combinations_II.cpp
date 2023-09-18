#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll mod{1'000'000'007};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n{}, x{};
  cin >> n >> x;

  vector<ll> coins(n);
  for (auto &coin : coins)
    cin >> coin;

  vector<ll> dp(x + 1, 0);
  dp[0] = 1;
  for (const auto &coin : coins)
    for (int i{1}; i <= x; ++i)
      if (i - coin >= 0)
        dp[i] = (dp[i] + dp[i - coin]) % mod;

  cout << dp[x] << '\n';

  return 0;
}