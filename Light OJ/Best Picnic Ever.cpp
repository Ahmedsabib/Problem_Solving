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

const int MAX_N = 1005;

bool vis[MAX_N];
int cnt_vis[MAX_N];
vi graph[MAX_N];

void BFS(int node) {
	rep(i, 0, MAX_N) {
    vis[i] = 0;
	}
  vis[node] = 1;
  queue<int> Q;
  ++cnt_vis[node];
  Q.push(node);
  while (!Q.empty()) {
    int U = Q.front();
    Q.pop();
    rep(i, 0, sz(graph[U])) {
      int V = graph[U][i];
      if (vis[V] == 0) {
        vis[V] = 1;
        cnt_vis[V]++;
        Q.push(V);
      }
    }
  }
}

void test_case(int cases) {
  int N, M, K;
  cin >> N >> K >> M;
  set<int> members;
  rep(i, 0, N) {
    int X;
    cin >> X;
    members.insert(X);
  }
  rep(i, 0, M) {
    int U, V;
    cin >> U >> V;
    graph[U].push_back(V);
  }
  for (auto& x: members) {
    BFS(x);
  }
  ll ans = 0;
  int len = sz(members);
  rep(i, 1, MAX_N) {
    if (cnt_vis[i] == len) {
      ++ans;
    }
  }
  cout << "Case " << cases << ": " << ans << '\n';
  rep(i, 0, MAX_N) {
    vis[i] = 0;
    cnt_vis[i] = 0;
    graph[i].clear();
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T, cases = 1;
  cin >> T;
  while (T--) {
    test_case(cases++);
  }
  return 0;
}
