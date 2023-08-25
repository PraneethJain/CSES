#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n{}, m{}, k{};
  cin >> n >> m >> k;

  vector<int> A(n);
  for (int i{0}; i < n; ++i)
    cin >> A[i];

  vector<int> B(m);
  for (int i{0}; i < m; ++i)
    cin >> B[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int a{0}, b{0};
  int res{0};
  while (a < n && b < m)
  {
    if (abs(A[a] - B[b]) <= k)
    {
      ++a;
      ++b;
      ++res;
      continue;
    }

    A[a] > B[b] ? ++b : ++a;
  }

  cout << res << '\n';

  return 0;
}
