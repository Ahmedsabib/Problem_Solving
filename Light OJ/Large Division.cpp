#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    string n;
    long long m;
    cin >> n >> m;
    if (m < 0) {
      m = abs(m);
    }
    int j = 0;
    if (n[0] == '-') {
      j = 1;
    }
    long long res = 0;
    for ( ; j < (int)n.size(); ++j) {
      res = res * 10 + (n[j] - '0');
      res %= m;
    }
    if (res == 0) {
      cout << "divisible\n";
    }
    else {
      cout << "not divisible\n";
    }
  }
  return 0;
}
