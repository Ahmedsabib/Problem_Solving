#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9 + 7;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 1; cs <= tc; ++cs) {
    long long n, m;
    cin >> n >> m;
    long long graph[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        graph[i][j] = inf;
      }
    }
    for (int i = 0; i < n; ++i) {
      graph[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
      long long a, b;
      cin >> a >> b;
      graph[a][b] = 1;
      graph[b][a] = 1;
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
      }
    }
    long long s, d;
    cin >> s >> d;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, graph[s][i] + graph[i][d]);
    }
    cout << "Case " << cs << ": " << ans << '\n';
  }
  return 0;
}
