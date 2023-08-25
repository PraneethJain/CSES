#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n{};
  cin >> n;
  vector<pair<int, bool>> v;
  for (int i{0}; i < n; ++i)
  {
    int a{}, b{};
    cin >> a >> b;
    v.emplace_back(a, true);
    v.emplace_back(b, false);
  }

  sort(v.begin(), v.end());

  int cur{0}, res{0};
  for (const auto &[x, arriving] : v)
  {
    arriving ? ++cur : --cur;
    res = max(res, cur);
  }

  cout << res << '\n';

  return 0;
}
