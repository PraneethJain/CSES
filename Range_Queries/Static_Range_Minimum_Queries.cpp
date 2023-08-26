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
  vector<int> blocks(n, numeric_limits<int>::max());
  for (int i{0}; i < n; ++i)
    blocks[i / blocksize] = min(blocks[i / blocksize], X[i]);

  for (int i{0}; i < q; ++i)
  {

    int a{}, b{};
    cin >> a >> b;
    --a;
    --b;
    int cur{a};
    int res{numeric_limits<int>::max()};
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

  return 0;
}
