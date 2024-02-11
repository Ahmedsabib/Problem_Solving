#include <bits/stdc++.h>

using namespace std;

const int maxn = 30005;

vector<pair<int, int>> adj[maxn];
int visited[maxn] = {0};
int diff[maxn];
int maxi = 0, max_node;

void dfs(int node, int child) {
  visited[node] = 1;
  diff[node] = max(child, diff[node]);
  if (child > maxi) {
    maxi = child;
    max_node = node;
  }
  for (int i = 0; i < (int)adj[node].size(); ++i) {
    if (visited[adj[node][i].first] == 0) {
      dfs(adj[node][i].first, child + adj[node][i].second);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
    int p, q;
    vector<int> p_diff(n + 1), q_diff(n + 1);
    maxi = 0;
    dfs(0, 0);
    p = max_node;
    memset(visited, 0, sizeof(visited));
    maxi = 0;
    dfs(p, 0);
    q = max_node;
    for (int i = 0; i < n; ++i) {
      p_diff[i] = diff[i];
    }
    memset(diff, 0, sizeof(diff));
    memset(visited, 0, sizeof(visited));
    dfs(q, 0);
    for (int i = 0; i < n; ++i) {
      q_diff[i] = diff[i];
    }
    cout << "Case " << cases + 1 << ":\n";
    for (int i = 0; i < n; ++i) {
      cout << max(p_diff[i], q_diff[i]) << '\n';
    }
    memset(adj, 0, sizeof(adj));
    memset(visited, 0, sizeof(visited));
    memset(diff, 0, sizeof(diff));
  }
  return 0;
}
