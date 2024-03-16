#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 2e5 + 5;

int n, q, timer = 1;
int upper_level[maxn][20];
vector<int> starting, ending, graph[maxn];

void dfs(int node, int parent) {
  starting[node] = timer++;
  upper_level[node][0] = parent;
  for (int i = 1; i < 20; ++i) upper_level[node][i] = upper_level[upper_level[node][i - 1]][i - 1];
  for (auto& edges: graph[node]) {
    if (edges != parent) dfs(edges, node);
  }
  ending[node] = timer - 1;
}

int ancestors(int a, int b) { return starting[a] <= starting[b] && ending[a] >= ending[b]; }

int lca(int a, int b) {
  if (ancestors(a, b)) return a;
  if (ancestors(b, a)) return b;
  for (int i = 19; i >= 0; --i) {
    if (!ancestors(upper_level[a][i], b)) a = upper_level[a][i];
  }
  return upper_level[a][0];
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n >> q;
  starting.resize(n);
  ending.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int x;
    cin >> x;
    x--;
    graph[x].push_back(i + 1);
  }
  dfs(0, 0);
  while (q--) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    cout << (lca(a, b) + 1) << '\n';
  }
  return 0;
}
