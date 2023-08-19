#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n{};
  cin >> n;
  vector<ll> p(n);
  ll total{0};
  for (int i{0}; i < n; ++i)
  {
    cin >> p[i];
    total += p[i];
  }

  ll res{LONG_LONG_MAX};
  for (ll i{0}; i < (1 << n); ++i)
  {
    ll s{0};
    for (ll j{0}; j < n; ++j)
    {
      if (i & (1 << j))
        s += p[j];
    }
    res = min(res, llabs(total - 2 * s));
  }

  cout << res << '\n';

  return 0;
}
