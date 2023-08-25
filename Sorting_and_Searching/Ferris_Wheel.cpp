#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n{}, x{};
  cin >> n >> x;
  vector<int> P(n);
  for (int i{0}; i < n; ++i)
    cin >> P[i];
  sort(P.begin(), P.end());

  int left{0}, right{n - 1};
  int res{0};
  while (left < right)
  {
    if (P[left] + P[right] <= x)
    {
      ++left;
      --right;
      ++res;
    }
    else
    {
      ++res;
      --right;
    }
  }

  res += left == right;

  cout << res << '\n';

  return 0;
}
