#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int maxn = 2e5 + 5;
 
int n, q;
vector<int> graph[maxn];
 
template<class T>
struct LCA_Binary_Lifting {
  int n, timer, l;
  vector<vector<T>> upper_level;
  vector<T> starting, ending, depth;
 
  LCA_Binary_Lifting(int len, int root) {
    n = len;
    starting.resize(n);
    ending.resize(n);
    depth.resize(n);
    timer = 1;
    l = ceil(log2(n));
    upper_level.assign(n, vector<int> (l + 1));
    dfs(root, root);
  }
 
  void dfs(int node, int parent) {
    starting[node] = timer++;
    upper_level[node][0] = parent;
    for (int i = 1; i <= l; ++i) {
      upper_level[node][i] = upper_level[upper_level[node][i - 1]][i - 1];
    }
    for (auto& edges: graph[node]) {
      if (edges != parent) {
        depth[edges] = depth[node] + 1;
        dfs(edges, node);
      }
    }
    ending[node] = timer - 1;
  }
 
  T ancestors(int a, int b) { return starting[a] <= starting[b] && ending[a] >= ending[b]; }
 
  T lca(int a, int b) {
    if (ancestors(a, b)) return a;
    if (ancestors(b, a)) return b;
    for (int i = l; i >= 0; --i) {
      if (!ancestors(upper_level[a][i], b)) a = upper_level[a][i];
    }
    return upper_level[a][0];
  }
};
 
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
 
  cin >> n >> q;
  for (int i = 0; i < n - 1; ++i) {
    int x;
    cin >> x;
    x--;
    graph[x].push_back(i + 1);
  }
  LCA_Binary_Lifting<int> lca_binary_lifting(n, 0);
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    cout << lca_binary_lifting.lca(a, b) + 1 << '\n';
  }
  return 0;
}
