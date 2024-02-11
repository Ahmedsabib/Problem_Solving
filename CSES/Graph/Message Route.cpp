#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 5;
vector<int> adj[maxn];
bool visited[maxn];
queue<int> q;
vector<int> distances(maxn + 1, -1);
vector<int> parent(maxn + 1);
void bfs(int node) {
  visited[node] = true;
  distances[node] = 0;
  q.push(node);
  while (!q.empty()) {
    int s = q.front();
    q.pop();
    for (auto& x: adj[s]) {
      if (!visited[x]) {
        visited[x] = true;
        distances[x] = distances[s] + 1;
        parent[x] = s;
        q.push(x);
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  bfs(1);
  if (distances[n] == -1) {
    cout << "IMPOSSIBLE\n";
  }
  else {
    cout << distances[n] + 1 << '\n';
    vector<int> v = {n};
    while (v.back() != 1) {
      v.push_back(parent[v.back()]);
    }
    reverse(v.begin(), v.end());
    for (auto& x: v) {
      cout << x << ' ';
    }
    cout << '\n';
  }
  return 0;
}
