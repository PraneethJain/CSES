#include <iostream>

using ll = long long;

int main()
{
  int n{};
  std::cin >> n;

  if (n % 4 == 0)
  {
    std::cout << "YES\n";
    std::cout << n / 2 << '\n';
    for (int i{1}; i <= n / 4; ++i)
    {
      std::cout << i << ' ';
    }
    for (int i{3 * n / 4 + 1}; i <= n; ++i)
    {
      std::cout << i << ' ';
    }
    std::cout << '\n' << n / 2 << '\n';
    for (int i{n / 4 + 1}; i <= 3 * n / 4; ++i)
    {
      std::cout << i << ' ';
    }
  }
  else if ((n + 1) % 4 == 0)
  {
    std::cout << "YES\n";
    std::cout << (n + 1) / 2 << '\n';
    for (int i{1}; i <= (n + 1) / 4; ++i)
    {
      std::cout << i << ' ';
    }
    for (int i{(3 * n - 1) / 4}; i <= n - 1; ++i)
    {
      std::cout << i << ' ';
    }
    std::cout << '\n' << (n - 1) / 2 << '\n';
    for (int i{(n + 1) / 4 + 1}; i <= (3 * n - 1) / 4 - 1; ++i)
    {
      std::cout << i << ' ';
    }
    std::cout << n << '\n';
  }
  else
  {
    std::cout << "NO\n";
  }

  return 0;
}
