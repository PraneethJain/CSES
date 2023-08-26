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
  vector<ll> blocks(n, 0);
  for (int i{0}; i < n; ++i)
    blocks[i / blocksize] += X[i];

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
      blocks[k / blocksize] += u - X[k];
      X[k] = u;
    }
    else if (t == 2)
    {
      int a{}, b{};
      cin >> a >> b;
      --a;
      --b;
      int cur{a};
      ll res{0};
      while (cur <= b)
      {
        if (cur + blocksize < b)
        {
          if (cur % blocksize == 0)
          {
            res += blocks[cur / blocksize];
            cur += blocksize;
          }
          else
          {
            while (cur <= b && cur % blocksize != 0)
            {
              res += X[cur];
              ++cur;
            }
          }
        }
        else
        {
          res += X[cur];
          ++cur;
        }
      }
      cout << res << '\n';
    }
  }

  return 0;
}
