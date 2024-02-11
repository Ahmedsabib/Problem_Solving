#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 2e5+7;
int n, m;
vector<int> adj_front_to_back[maxn];
vector<int> adj_back_to_front[maxn];
bool visited[maxn];
void DFS_front_to_back(int node) {
  if (visited[node]) {
    return;
  }
  visited[node] = true;
  for (auto& iter: adj_front_to_back[node]) {
    DFS_front_to_back(iter);
  }
}
void DFS_back_to_front(int node) {
  if (visited[node]) {
    return;
  }
  visited[node] = true;
  for (auto& iter: adj_back_to_front[node]) {
    DFS_back_to_front(iter);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj_front_to_back[a].push_back(b);
    adj_back_to_front[b].push_back(a);
  }
  memset(visited, false, sizeof(visited));
  DFS_front_to_back(1);
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      cout << "NO" << '\n';
      cout << 1 << ' ' << i << '\n';
      return 0;
    }
  }
  memset(visited, false, sizeof(visited));
  DFS_back_to_front(1);
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      cout << "NO" << '\n';
      cout << i << ' ' << 1 << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  return 0;
}
