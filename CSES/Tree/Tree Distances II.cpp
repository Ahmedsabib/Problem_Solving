#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 2e5 + 5;

int n;
vector<int> graph[maxn];
int dp[maxn], ans[maxn];

void dfs1(int node, int parent, int depth) {
  ans[1] += depth;
  dp[node] = 1;
  for (auto& edges: graph[node]) {
    if (edges != parent) {
      dfs1(edges, node, depth + 1);
      dp[node] += dp[edges];
    }
  }
}

void dfs2(int node, int parent) {
  for (auto& edges: graph[node]) {
    if (edges != parent) {
      ans[edges] = ans[node] + n - 2 * dp[edges];
      dfs2(edges, node);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dfs1(1, 0, 0);
  dfs2(1, 0);
  for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
  return 0;
}
