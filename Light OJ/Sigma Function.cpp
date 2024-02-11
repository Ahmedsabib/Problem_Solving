#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    long long n;
    cin >> n;
    long long sum = n;
    sum -= (long long)sqrt(n) + (long long)sqrt(n/2);
    cout << sum << '\n';
  }
  return 0;
}
