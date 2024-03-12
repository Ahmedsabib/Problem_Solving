#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long

const int maxn = 2e5 + 5;
 
int n, q, timer = 0, a[maxn];
vector<int> start, ending, graph[maxn];
 
void euler_tour(int pos, int prev) {
  start[pos] = timer++;
  for (auto& edges: graph[pos]) {
    if (edges != prev) euler_tour(edges, pos);
  }
  ending[pos] = timer;
}

template <class T>
class BIT {
  private:
  int size;
  vector<T> bit;
  vector<T> arr;

  public:
  BIT(int size) : size(size), bit(size + 1), arr(size) {}

  void set(int ind, int val) { add(ind, val - arr[ind]); }

  void add(int ind, int val) {
    arr[ind] += val;
    ind++;
    for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
  }

  T pref_sum(int ind) {
    ind++;
    T total = 0;
    for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
    return total;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
 
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  start.resize(n);
  ending.resize(n);
  euler_tour(0, -1);
  BIT<int> bit(n);
  for (int i = 0; i < n; ++i) bit.set(start[i], a[i]);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int node, val;
      cin >> node >> val;
      node--;
      bit.set(start[node], val);
    }
    else {
      int node;
      cin >> node;
      node--;
      int end_time = bit.pref_sum(ending[node] - 1);
      int start_time = 0;
      if (start[node] == 0) start_time = 0;
      else start_time = bit.pref_sum(start[node] - 1);
      cout << end_time - start_time << '\n';
    }
  }
  return 0;
}
