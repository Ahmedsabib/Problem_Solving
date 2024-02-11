#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e5+7;
int n, m;
vector<int> adj[maxn]; // graph represented as an adjacency list 
bool visited[maxn]; //to find the visited nodes
int parent[maxn]; //to find the edges wich are not in the graph tree
vector<int> root_nodes; //to list the new nodes that should connect
vector<pair<int, int>> free_edges; //to list all the edges which are not in graph tree
//simple implementation
//Complexity O(m+n) 
//where n is the number of vertices and m is the number of edges
void dfs(int node) {
  visited[node] = true;
  for (auto& x: adj[node]) {
    if (x == parent[node]) {
      continue;
    }
    if (!visited[x]) {
      parent[x] = node;
      dfs(x);
    }
    else {
      if (x < node) {
        free_edges.push_back({node, x});
      }
    }
  }
  return;
}
void connected_component() {
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      root_nodes.push_back(i);
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
  if ((int)root_nodes.size()-1 > (int)free_edges.size()) {
    cout << -1 << '\n';
  }
  else {
    while ((int)root_nodes.size() > 1) {
      int a = root_nodes.front();
      int b = root_nodes.back();
      root_nodes.pop_back();
      auto deleted_edge = free_edges.back();
      free_edges.pop_back();
      cout << deleted_edge.first << ' ' << deleted_edge.second << ' ' << a  << ' ' << b << '\n';
    }
  }
  return 0;
}
