#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T, typename F> struct SegTree
{
  ll n;
  vector<T> t;
  const T id;
  F f;
  SegTree(const vector<T> &a, T _id, F _f) : n(static_cast<ll>(a.size())), t(2 * n), id(_id), f(_f)
  {
    for (ll i = 0; i < n; i++)
      t[n + i] = a[i];
    for (ll i = n - 1; i >= 1; i--)
      t[i] = f(t[2 * i], t[2 * i + 1]);
  }

  T query(ll l, ll r)
  {
    T resl(id), resr(id);
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1)
    {
      if (l == r)
      {
        resl = f(resl, t[l]);
        break;
      }
      if (l & 1)
        resl = f(resl, t[l++]);
      if (!(r & 1))
        resr = f(t[r--], resr);
    }
    return f(resl, resr);
  }

  void update(ll v, T value)
  {
    for (t[v += n] = value; v >>= 1;)
      t[v] = f(t[2 * v], t[2 * v + 1]);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ll n{}, q{};
  cin >> n >> q;
  vector<ll> X(n);
  for (auto &x : X)
    cin >> x;

  auto merge = [](const ll x, const ll y) { return x + y; };
  SegTree<ll, decltype(merge)> seg(vector<ll>(2 * n, 0), 0, merge);

  while (q--)
  {
    ll t{};
    cin >> t;
    if (t == 1)
    {
      ll a{}, b{}, u{};
      cin >> a >> b >> u;
      --a;
      --b;
      ll temp{seg.query(b + 1, b + 1)};
      seg.update(a, seg.query(a, a) + u);
      seg.update(b + 1, temp - u);
    }
    else if (t == 2)
    {
      ll k{};
      cin >> k;
      --k;
      cout << X[k] + seg.query(0, k) << '\n';
    }
  }

  return 0;
}