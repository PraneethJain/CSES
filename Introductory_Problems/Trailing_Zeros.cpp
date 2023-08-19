#include <iostream>

using ll = long long;

int main()
{
  ll n{};
  std::cin >> n;
  ll ans{0};
  while (n)
  {
    n /= 5;
    ans += n;
  }

  std::cout << ans;

  return 0;
}
