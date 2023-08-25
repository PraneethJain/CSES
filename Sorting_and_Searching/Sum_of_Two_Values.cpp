#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n{};
  ll x{};
  cin >> n >> x;
  vector<int> A(n + 1);
  for (int i{1}; i <= n; ++i)
    cin >> A[i];

  map<ll, int> m{};
  for (int i{1}; i <= n; ++i)
  {
    if (m[x - A[i]] > 0)
    {
      cout << m[x - A[i]] << ' ' << i << '\n';
      return 0;
    }
    m[A[i]] = i;
  }

  cout << "IMPOSSIBLE\n";
  return 0;
}
