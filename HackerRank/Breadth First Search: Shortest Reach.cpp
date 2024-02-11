#include <bits/stdc++.h>
using namespace std;
const int maxn = 1009;
vector<int> adj[maxn];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + 3; ++i) {
      adj[i].clear();
    }
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int s;
    cin >> s;
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));
    int distances[n + 1];
    memset(distances, 0, sizeof(distances));
    queue<int> q;
    visited[s] = true;
    distances[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto& edges: adj[u]) {
        if (!visited[edges]) {
          visited[edges] = true;
          distances[edges] = distances[u] + 6;
          q.push(edges);
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (i != s) {
        if (distances[i] == 0) {
          cout << -1 << ' ';
        }
        else {
          cout << distances[i] << ' ';
        }
      }
    }
    cout << '\n';
  }
  return 0;
}
