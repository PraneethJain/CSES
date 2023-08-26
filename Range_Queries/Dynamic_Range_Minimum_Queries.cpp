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

  int blocksize{static_cast<int>(sqrt(n)) + 1};
  vector<ll> blocks(n, numeric_limits<ll>::max());
  for (int i{0}; i < n; ++i)
    blocks[i / blocksize] = min(blocks[i / blocksize], X[i]);

  for (int i{0}; i < q; ++i)
  {
    int t{};
    cin >> t;
    if (t == 1)
    {
      int k{};
      ll u{};
      cin >> k >> u;
      --k;
      X[k] = u;
      int blockidx = k / blocksize;
      blocks[blockidx] = numeric_limits<ll>::max();
      for (int j{blockidx * blocksize}; j < (blockidx + 1) * blocksize; ++j)
        blocks[blockidx] = min(blocks[blockidx], X[j]);
    }
    else if (t == 2)
    {
      int a{}, b{};
      cin >> a >> b;
      --a;
      --b;
      int cur{a};
      ll res{numeric_limits<ll>::max()};
      while (cur <= b)
      {
        if (cur + blocksize < b && cur % blocksize == 0)
        {
          res = min(res, blocks[cur / blocksize]);
          cur += blocksize;
        }
        else
        {
          res = min(res, X[cur]);
          ++cur;
        }
      }
      cout << res << '\n';
    }
  }

  return 0;
}
