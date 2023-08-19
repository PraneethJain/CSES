#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll bpow(ll a, ll b)
{
  ll res = 1;
  while (b > 0)
  {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int q{};
  ll k{};
  cin >> q;
  while (q--)
  {
    cin >> k;
    ll n{1};
    ll uplim{9};
    while (k > uplim)
    {
      ++n;
      uplim += n * 9 * bpow(10, n - 1);
    }

    cout << ((bpow(10, n) - 1 - (uplim - k) / n) / bpow(10, ((uplim - k) % n))) % 10 << '\n';
  }

  return 0;
}
