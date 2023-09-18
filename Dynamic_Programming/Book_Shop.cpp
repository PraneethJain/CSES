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

  vector<ll> prices(n);
  for (auto &price : prices)
    cin >> price;

  vector<ll> pages(n);
  for (auto &page : pages)
    cin >> page;

  vector<ll> dp(x + 1, 0);
  for (int j{0}; j < n; ++j)
    for (int i{x}; i >= 0; --i)
      if (i - prices[j] >= 0)
        dp[i] = max(dp[i], pages[j] + dp[i - prices[j]]);

  cout << dp[x] << '\n';

  return 0;
}