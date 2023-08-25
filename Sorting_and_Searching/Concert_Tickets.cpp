#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n{}, m{};
  cin >> n >> m;
  multiset<int, greater<int>> H{};
  int x{};
  for (int i{0}; i < n; ++i)
  {
    cin >> x;
    H.insert(x);
  }

  vector<int> T(m);
  for (int i{0}; i < m; ++i)
    cin >> T[i];

  for (const auto &t : T)
  {
    auto res = H.lower_bound(t);
    if (res == H.end())
      cout << -1;
    else
    {
      cout << *res;
      H.erase(res);
    }
    cout << '\n';
  }

  return 0;
}
