#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int MAX_N = 105;

int N, M, S, D;
int visited[MAX_N], dist_D[MAX_N], dist_S[MAX_N];
vi graph[MAX_N];

void BFS(int node, int dist[]) {
  visited[node] = 1;
  queue<int> Q;
  Q.push(node);
  while (!Q.empty()) {
    int U = Q.front();
    Q.pop();
    rep(i, 0, sz(graph[U])) {
      int V = graph[U][i];
      if (!visited[V]) {
        visited[V] = 1;
        dist[V] = dist[U] + 1;
        Q.push(V);
      }
    }
  }
}

void test_case(int cases) {
  cin >> N >> M;
  rep(i, 0, N) {
    visited[i] = 0;
    dist_D[i] = 0;
    dist_S[i] = 0;
  }
  rep(i, 0, MAX_N) {
    graph[i].clear();
  }
  rep(i, 0, M) {
    int U, V;
    cin >> U >> V;
    graph[U].push_back(V);
    graph[V].push_back(U);
  }
  cin >> S >> D;
  BFS(S, dist_S);
  rep(i, 0, N) {
    visited[i] = 0;
  }
  BFS(D, dist_D);
  int ans = 0;
  rep(i, 0, N) {
    ans = max(ans, dist_S[i] + dist_D[i]);
  }
  cout << "Case " << cases << ": " << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int T, cases = 1;
  cin >> T;
  while (T--) {
    test_case(cases++);
  }
  return 0;
}
