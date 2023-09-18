#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int max_digit(int num)
{
  int res{0};
  while (num)
  {
   res = max(res, num % 10);
   num /= 10; 
  }

  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n{};
  cin >> n;

  int res{0};
  while (n)
  {
    ++res;
    n -= max_digit(n);
  }

  cout << res << '\n';

  return 0;
}