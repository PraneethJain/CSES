#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s{};
  cin >> s;

  sort(s.begin(), s.end());

  vector<string> v{};
  do
  {
    v.push_back(s);
  } while (next_permutation(s.begin(), s.end()));

  cout << v.size() << '\n';
  for (const auto &el : v)
    cout << el << '\n';

  return 0;
}
