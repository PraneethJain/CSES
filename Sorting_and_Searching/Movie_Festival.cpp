#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n{};
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i{0}; i < n; ++i)
  {
    int a{}, b{};
    cin >> a >> b;
    v[i] = {a, b};
  }
  sort(v.begin(), v.end(), [](const auto &left, const auto &right) { return left.second < right.second; });

  int latest{0};
  int res{0};
  for (const auto &[a, b] : v)
  {
    if (a < latest)
      continue;

    ++res;
    latest = b;
  }

  cout << res << '\n';

  return 0;
}
