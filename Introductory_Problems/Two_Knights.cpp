#include <iostream>

using ll = long long;

int main()
{
  ll n{};
  std::cin >> n;

  for (ll i{0}; i < n; ++i)
  {
    std::cout << (i) * (i + 5) * (i * i - i + 2) / 2 << '\n';
  }

  return 0;
}
