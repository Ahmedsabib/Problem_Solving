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
    for (int i = 0; i < 9; ++i) {
      if ((n - i)%9 == 0) {
        if (i == 0) {
          cout << n + (n - 9)/9 << ' ' << n + n/9 << ' ';
        }
        else {
          cout << n + (n - i)/9 << ' ';
        }
      }
    }
    cout << '\n';
  }
  return 0;
}
