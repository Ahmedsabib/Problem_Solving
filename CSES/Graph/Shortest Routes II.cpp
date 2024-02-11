#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long n, m, q;
  cin >> n >> m >> q;
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
    long long a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    if (c < graph[a][b]) {
      graph[a][b] = c;
      graph[b][a] = c;
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }
  while (q--) {
    long long a, b;
    cin >> a >> b;
    --a, --b;
    long long ans = graph[a][b];
    if (ans == inf) {
      cout << -1 << '\n';
    }
    else {
      cout << ans << '\n';
    }
  }
  return 0;
}
