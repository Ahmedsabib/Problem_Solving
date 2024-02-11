#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 0;
vector<vector<bool>> visited;
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool is_valid(int a, int b) {
  if (a < 0 || a >= n || b < 0 || b >= m) {
    return false;
  }
  if (visited[a][b]) {
    return false;
  }
  return true;
}
void dfs(int i, int j) {
  visited[i][j] = true;
  for (auto& x: moves) {
    if (is_valid(i+x.first, j+x.second)) {
      dfs(i+x.first, j+x.second);
    }
  }
}
void connected_components() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!visited[i][j]) {
        dfs(i, j);
        ++ans;
      }
    }
  }
}
int main() {
  cin >> n >> m;
  visited.resize(n);
  for (int i = 0; i < n; ++i) {
    visited[i].resize(m);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      if (c == '#') {
        visited[i][j] = true;
      }
    }
  }
  connected_components();
  cout << ans << '\n';
  return 0;
}
