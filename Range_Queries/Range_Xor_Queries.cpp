#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n{}, q{};
  cin >> n >> q;
  vector<int> X(n);
  for (int i{0}; i < n; ++i)
    cin >> X[i];

  int blocksize{static_cast<int>(sqrt(n)) + 1};
  vector<int> blocks(n, 0);
  for (int i{0}; i < n; ++i)
    blocks[i / blocksize] ^= X[i];

  for (int i{0}; i < q; ++i)
  {

    int a{}, b{};
    cin >> a >> b;
    --a;
    --b;
    int cur{a};
    int res{0};
    while (cur <= b)
    {
      if (cur + blocksize < b && cur % blocksize == 0)
      {
        res ^= blocks[cur / blocksize];
        cur += blocksize;
      }
      else
      {
        res ^= X[cur];
        ++cur;
      }
    }
    cout << res << '\n';
  }

  return 0;
}
