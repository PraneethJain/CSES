#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n{};
  cin >> n;
  vector<int> X(n);
  vector<int> indices(n);
  for (int i{0}; i < n; ++i)
  {
    cin >> X[i];
    --X[i];
    indices[X[i]] = i;
  }

  int res{0};
  for (int i{0}; i < n - 1; ++i)
    res += indices[i] > indices[i + 1];

  cout << res + 1 << '\n';

  return 0;
}
