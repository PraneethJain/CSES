#include <iostream>

using ll = long long;

int main()
{
  ll n{};
  std::cin >> n;
  std::cout << n << ' ';
  while (n != 1)
  {
    if (n % 2 == 1)
    {
      n = 3 * n + 1;
    }
    else
    {
      n = n / 2;
    }
    std::cout << n << ' ';
  }
  std::cout << '\n';

  return 0;
}
