#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int maxn = 25;
vector<int> adj[maxn];
vector<int> color;
vector<int> parent[maxn];
set<pair<int, int>> ara;
set<int> ans;
void dfs(int node) {
  color[node] = 1;
  for (auto& x: adj[node]) {
    if (color[x] == 0) {
      parent[x].push_back(node);
      dfs(x);
    }
    else if (color[x] == 1) {
      ara.insert({x, node});
    }
  }
  color[node] = 2;
}
void dfs_again(int x, int  y) {
  ans.insert(x);
  if (x == y) {
    return;
  }
  for (auto& iter: parent[x]) {
    dfs_again(iter, y);
  }
}
int main() {
  int n, k;
  cin >> n >> k;
  color.assign(n+1, 0);
  for (int i = 0; i < k; ++i) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (x > y) {
      adj[a].push_back(b);
    }
    else {
      adj[b].push_back(a);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (color[i] == 0) {
      dfs(i);
      for (auto& iter: ara) {
        dfs_again(iter.second, iter.first);
      }
    }
  }
  cout << ans.size() << '\n';
  return 0;
}
