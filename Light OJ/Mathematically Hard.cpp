#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000000;
int phi[maxn + 2];
unsigned long long phi_sum[maxn + 2];
// Time Complexity - O(n log log n)
void phi_1_to_n() {
  for (int i = 2; i <= maxn; ++i) {
    phi[i] = i;
  }
  for (int i = 2; i <= maxn; ++i) {
    if (phi[i] == i) {
      for (int j = i; j <= maxn; j += i) {
        phi[j] -= phi[j]/i;
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  phi_1_to_n();
  phi_sum[1] = 0;
  for (int i = 2; i <= maxn; ++i) {
    phi_sum[i] = ((unsigned long long)phi[i] * (unsigned long long)phi[i]) + phi_sum[i - 1];
  }
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    long long a, b;
    cin >> a >> b;
    unsigned long long x = phi_sum[b] - phi_sum[a - 1];
    cout << "Case " << cs + 1 << ": " << x << '\n';
  }
  return 0;
}
