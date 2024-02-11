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
    long long root = sqrt(n), ans = 0;
    for (int i = 2; i <= root; ++i) {
      long long x = n/i;
      ans += ((i + x) * (x - i + 1))/2;
      ans += i * (x - i);  
    }
    cout << ans << '\n';
  }
  return 0;
}
