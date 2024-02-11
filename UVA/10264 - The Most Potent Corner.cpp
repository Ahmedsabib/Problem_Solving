#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  while (cin >> n) {
    int node_edge = (1 << n);
    vector<int> edges;
    for (int i = 0; i < node_edge; ++i) {
      int x;
      cin >> x;
      edges.push_back(x);
    }
    vector<int> sum;
    for (int i = 0; i < node_edge; ++i) {
      int edge_sum = 0;
      for (int j = 0; j < n; ++j) {
        edge_sum += edges[i^(1 << j)];
      }
      sum.push_back(edge_sum);
    }
    int maxi_ans = 0;
    for (int i = 0; i < node_edge; ++i) {
      for (int j = 0; j < n; ++j) {
        maxi_ans = max(maxi_ans, sum[i] + sum[i^(1 << j)]);
      }
    }
    cout << maxi_ans << '\n';
  }
  return 0;
}
