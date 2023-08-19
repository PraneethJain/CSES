#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n{};
  cin >> n;

  for (int i{0}; i < (1 << n); ++i)
  {
    bitset<16> bs(i ^ (i >> 1));
    cout << bs.to_string().substr(16 - n, 16) << '\n';
  }

  return 0;
}
