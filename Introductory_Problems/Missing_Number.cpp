#include <iostream>

using ll = long long;

int main()
{
  ll n;
  std::cin >> n;
  ll sum{0};
  ll temp{};
  for (int i{1}; i < n; ++i)
  {
    std::cin >> temp;
    sum += temp;
  }

  std::cout << n * (n + 1) / 2 - sum << '\n';

  return 0;
}
