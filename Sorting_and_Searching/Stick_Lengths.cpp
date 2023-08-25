#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n{};
  cin >> n;
  vector<ll> P(n);
  for (int i{0}; i < n; ++i)
    cin >> P[i];
  sort(P.begin(), P.end());

  ll res{0};
  for (int i{0}; i < n; ++i)
    res += llabs(P[i] - P[n / 2]);

  cout << res << '\n';

  return 0;
}
