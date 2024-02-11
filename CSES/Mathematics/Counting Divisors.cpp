#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6 + 5;
vector<long long> a(maxn, 0);
void precalcuation() {
  for (int i = 1; i < maxn; ++i) {
    for (int j = i; j < maxn; j += i) {
      a[j]++;
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  precalcuation();
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    long long n;
    cin >> n;
    cout << a[n] << '\n';
  }
  return 0;
}
