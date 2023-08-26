#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n{}, q{};
  cin >> n >> q;
  vector<ll> X(n);
  for (int i{0}; i < n; ++i)
    cin >> X[i];

  vector<ll> pre(n + 1, 0);
  for (int i{1}; i <= n; ++i)
    pre[i] = pre[i - 1] + X[i - 1];

  while (q--)
  {
    int a{}, b{};
    cin >> a >> b;
    --a;
    cout << pre[b] - pre[a] << '\n';
  }

  return 0;
}
