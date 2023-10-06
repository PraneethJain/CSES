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

  void upset(ll v, T value)
  {
    for (t[v += n] = value; v >>= 1;)
      t[v] = f(t[2 * v], t[2 * v + 1]);
  }

  void update(ll v, T delta)
  {
    for (t[v += n] += delta; v >>= 1;)
      t[v] = f(t[2 * v], t[2 * v + 1]);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ll n{}, m{};
  cin >> n >> m;
  vector<ll> H(n);
  for (auto &h : H)
    cin >> h;

  auto merge = [](const ll x, const ll y) { return max(x, y); };
  SegTree<ll, decltype(merge)> seg{H, 0, merge};

  vector<ll> rooms(m);
  for (auto &room : rooms)
    cin >> room;

  for (const auto &room : rooms)
  {
    ll l{0}, r{n - 1}, res{-1};
    while (l <= r)
    {
      ll mid{(l + r) / 2};
      if (seg.query(0, mid) >= room)
      {
        res = mid;
        r = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }

    if (res == -1)
    {
      cout << "0 ";
    }
    else
    {
      cout << res + 1 << ' ';
      seg.update(res, -room);
    }
  }
  cout << '\n';

  return 0;
}
