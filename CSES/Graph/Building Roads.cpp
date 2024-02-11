#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e5+7;
int n, m, ans = 0;
vector<int> adj[maxn];
bool visited[maxn];
vector<int> ans_list;
void dfs(int node) {
  visited[node] = true;
  for (auto& iter: adj[node]) {
    if (!visited[iter]) {
      dfs(iter);
    }
  }
  return;
}
void connected_component() {
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      ++ans;
      ans_list.push_back(i);
      dfs(i);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  connected_component();
  cout << ans-1 << '\n';
  if (ans > 1) {
    int a = ans_list[0], b;
    for (int i = 1; i < ans; ++i) {
      b = ans_list[i];
      cout << a << ' ' << b << '\n';
      b = a;
    }
  }
  return 0;
}
