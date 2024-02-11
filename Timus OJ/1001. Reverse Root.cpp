#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  signed long long N;
  vector<long long> A;
  while (cin >> N) {
    A.push_back(N);
  }
  for (int i = (int)A.size() - 1; i >= 0; --i) {
    cout << fixed << setprecision(4) << sqrt(A[i]) << '\n';
  }
  return 0;
}
