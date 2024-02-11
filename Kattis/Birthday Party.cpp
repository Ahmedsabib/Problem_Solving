#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 105;
int n, m;
bool adj[maxn][maxn];
bool visited[maxn];
void dfs(int node) {
  visited[node] = true;
  for (int i = 0; i < n; ++i) {
    if (adj[node][i] && !visited[i]) {
      dfs(i);
    }
  }
}
int main() {
  while (cin >> n >> m && (n || m)) {
    memset(adj, false, sizeof(adj));
    vector<pair<int, int>> edge;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      adj[a][b] = true;
      adj[b][a] = true;
      edge.push_back({a, b});
    }
    int ok = 0;
    for (int i = 0; i < (int)edge.size(); ++i) {
      adj[edge[i].first][edge[i].second] = false;
      adj[edge[i].second][edge[i].first] = false;
      memset(visited, false, sizeof(visited));
      dfs(0);
      for (int j = 0; j < n; ++j) {
        if (!visited[j]) {
          ok = 1;
          break;
        }
      }
      if (ok) {
        break;
      }
      adj[edge[i].first][edge[i].second] = true;
      adj[edge[i].second][edge[i].first] = true;
    }
    if (ok) {
      cout << "Yes" << '\n';
    }
    else {
      cout << "No" << '\n';
    }
  }
  return 0;
}
