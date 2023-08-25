#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n{};
  cin >> n;
  vector<ll> x(n);
  for (int i{0}; i < n; ++i)
    cin >> x[i];

  ll maxi{*max_element(x.begin(), x.end())};
  if (maxi <= 0)
  {
    cout << maxi << '\n';
    return 0;
  }

  ll cur{0};
  ll res{0};
  for (const auto &el : x)
  {
    cur += el;
    cur = max(cur, 0ll);
    res = max(res, cur);
  }

  cout << res << '\n';

  return 0;
}
