#include <iostream>

int main()
{
  std::string inp{};
  std::getline(std::cin, inp);

  char cur{inp[0]};
  int count{0};
  int max_count{0};
  for (const auto &c : inp)
  {
    if (c == cur)
    {
      count += 1;
    }
    else
    {
      max_count = std::max(count, max_count);
      count = 1;
      cur = c;
    }
  }

  std::cout << std::max(count, max_count) << '\n';

  return 0;
}
