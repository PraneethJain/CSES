#include <iostream>

using ll = long long;

int main()
{
  int n{};
  std::cin >> n;
  int cur{};
  int prev{};
  ll ans{0};
  for (int i{0}; i < n; ++i)
  {
    if (i == 0)
    {
      std::cin >> prev;
    }
    else
    {
      std::cin >> cur;
      if (prev > cur)
      {
        ans += prev - cur;
        cur = prev;
      }

      prev = cur;
    }
  }
  std::cout << ans << '\n';

  return 0;
}
