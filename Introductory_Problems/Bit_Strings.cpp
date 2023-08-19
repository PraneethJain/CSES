#include <iostream>

using ll = long long;
const ll MOD = 1000000007;

int main()
{
  ll n{};
  std::cin >> n;
  ll res{1};
  for (ll i{0}; i < n; ++i)
  {
    res = (res * 2) % MOD;
  }
  std::cout << res << '\n';
  return 0;
}
