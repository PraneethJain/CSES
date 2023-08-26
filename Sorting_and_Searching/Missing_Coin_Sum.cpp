#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n{};
  cin >> n;
  vector<ll> X(n);
  for (int i{0}; i < n; ++i)
    cin >> X[i];
  sort(X.begin(), X.end());
  ll res{0};
  for (const auto &x : X)
  {
    if (x > res + 1)
      break;
    res += x;
  }

  cout << res + 1 << '\n';

  return 0;
}
