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
    for (int i = 0; i < n; i++)
      t[n + i] = a[i];
    for (int i = n - 1; i >= 1; i--)
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

  ll n{}, q{};
  cin >> n >> q;
  vector<ll> X(n);
  for (ll i{0}; i < n; ++i)
    cin >> X[i];

  auto merge = [](const ll x, const ll y) { return x + y; };
  SegTree<ll, decltype(merge)> seg{X, 0, merge};

  for (ll i{0}; i < q; ++i)
  {
    ll t{};
    cin >> t;
    if (t == 1)
    {
      ll k{};
      ll u{};
      cin >> k >> u;
      --k;
      seg.update(k, u);
    }
    else if (t == 2)
    {
      ll a{}, b{};
      cin >> a >> b;
      --a;
      --b;
      cout << seg.query(a, b) << '\n';
    }
  }

  return 0;
}
