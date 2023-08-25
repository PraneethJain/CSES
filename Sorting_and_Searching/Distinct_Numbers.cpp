#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n{};
  cin >> n;
  set<ll> s{};
  ll x{};

  while (n--)
  {
    cin >> x;
    s.insert(x);
  }

  cout << s.size() << '\n';

  return 0;
}
