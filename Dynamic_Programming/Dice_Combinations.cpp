#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <ll MOD> struct Modular
{
  ll value;
  static const ll MOD_value = MOD;

  Modular(long long v = 0)
  {
    value = v % MOD;
    if (value < 0)
      value += MOD;
  }
  Modular(long long a, long long b) : value(0)
  {
    *this += a;
    *this /= b;
  }

  Modular &operator+=(Modular const &b)
  {
    value += b.value;
    if (value >= MOD)
      value -= MOD;
    return *this;
  }
  Modular &operator-=(Modular const &b)
  {
    value -= b.value;
    if (value < 0)
      value += MOD;
    return *this;
  }
  Modular &operator*=(Modular const &b)
  {
    value = (long long)value * b.value % MOD;
    return *this;
  }

  friend Modular mexp(Modular a, long long e)
  {
    Modular res = 1;
    while (e)
    {
      if (e & 1)
        res *= a;
      a *= a;
      e >>= 1;
    }
    return res;
  }
  friend Modular inverse(Modular a)
  {
    return mexp(a, MOD - 2);
  }

  Modular &operator/=(Modular const &b)
  {
    return *this *= inverse(b);
  }
  friend Modular operator+(Modular a, Modular const b)
  {
    return a += b;
  }
  friend Modular operator-(Modular a, Modular const b)
  {
    return a -= b;
  }
  friend Modular operator-(Modular const a)
  {
    return 0 - a;
  }
  friend Modular operator*(Modular a, Modular const b)
  {
    return a *= b;
  }
  friend Modular operator/(Modular a, Modular const b)
  {
    return a /= b;
  }
  friend std::ostream &operator<<(std::ostream &os, Modular const &a)
  {
    return os << a.value;
  }
  friend bool operator==(Modular const &a, Modular const &b)
  {
    return a.value == b.value;
  }
  friend bool operator!=(Modular const &a, Modular const &b)
  {
    return a.value != b.value;
  }
};

int main()
{
  int n{};
  cin >> n;

  vector<Modular<1'000'000'007>> dp(n + 1, 0);
  dp[0] = 1;
  for (int i{1}; i <= n; ++i)
    for (int j{1}; j <= 6; ++j)
      if (i - j >= 0)
        dp[i] += dp[i-j];

  cout << dp[n] << '\n';

  return 0;
}
