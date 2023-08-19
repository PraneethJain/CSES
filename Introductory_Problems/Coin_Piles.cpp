#include <iostream>

using ll = long long;

void solve()
{
  ll a{}, b{};
  std::cin >> a >> b;
  if (a > 2 * b || b > 2 * a || ((a + b) % 3))
    std::cout << "NO";
  else
    std::cout << "YES";

  std::cout << '\n';
}

int main()
{
  ll t{};
  std::cin >> t;
  while (t--)
  {
    solve();
  }

  return 0;
}
