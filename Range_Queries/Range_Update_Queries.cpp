#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n{}, q{};
  cin >> n >> q;
  vector<ll> X(n);
  for (int i{0}; i < n; ++i)
    cin >> X[i];

  int blocksize{static_cast<int>(sqrt(n)) + 1};
  vector<ll> blocks(blocksize, 0);

  while (q--)
  {
    int t{};
    cin >> t;
    if (t == 1)
    {
      int a{}, b{};
      ll u{};
      cin >> a >> b >> u;
      --a;
      --b;
      ll cur{a};
      while (cur <= b)
      {
        if (cur + blocksize < b && cur % blocksize == 0)
        {
          int ok{static_cast<int>(cur / blocksize)};
          while (cur + blocksize < b)
          {
            blocks[ok] += u;
            ++ok;
            cur += blocksize;
          }
        }
        else
        {
          X[cur] += u;
          ++cur;
        }
      }
    }
    else if (t == 2)
    {
      int k{};
      cin >> k;
      --k;
      cout << X[k] + blocks[k / blocksize] << '\n';
    }
  }

  return 0;
}
