#include <iostream>
#include <unordered_map>

struct default_zero
{
  int i = 0;
};

int main()
{
  std::string word{};
  std::cin >> word;
  std::unordered_map<char, default_zero> freq;
  for (const auto &letter : word)
  {
    freq[letter].i += 1;
  }
  int odd_count{0};
  char odd_char{};
  for (const auto &x : freq)
  {
    if (x.second.i % 2 == 1)
    {
      odd_char = x.first;
      odd_count += 1;
    }
  }
  if (odd_count == 0)
  {
    std::string ans{};
    for (const auto &x : freq)
    {
      for (int i{0}; i < x.second.i / 2; ++i)
      {
        ans += x.first;
      }
    }
    ans += std::string(ans.rbegin(), ans.rend());
    std::cout << ans << '\n';
  }
  else if (odd_count == 1)
  {
    std::string ans{};
    for (const auto &x : freq)
    {
      if (x.first == odd_char)
      {
        continue;
      }
      for (int i{0}; i < x.second.i / 2; ++i)
      {
        ans += x.first;
      }
    }
    std::string temp = ans;
    for (int i{0}; i < freq[odd_char].i; ++i)
    {
      ans += odd_char;
    }
    ans += std::string(temp.rbegin(), temp.rend());
    std::cout << ans << '\n';
  }
  else
  {
    std::cout << "NO SOLUTION\n";
  }
  return 0;
}
