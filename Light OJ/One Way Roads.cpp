#include <bits/stdc++.h>

using namespace std;

void test_case(int cases) {
  int N;
  scanf("%d", &N);
  vector<int> graph[N + 1];
  map<pair<int, int>, int> mp;
  for (int i = 1; i <= N; ++i) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    mp[{u, v}] = c;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int ans1 = 0;
  int cur_city = 1, next_city = graph[1][0], temp;
  for (int i = 1; i <= N; ++i) {
    if (mp[{cur_city, next_city}] == 0) {
      ans1 += mp[{next_city, cur_city}];
    }
    temp = graph[next_city][0];
    if (temp == cur_city) {
      temp = graph[next_city][1];
    }
    cur_city = next_city;
    next_city = temp;
  }
  int ans2 = 0;
  cur_city = 1, next_city = graph[1][1];
  for (int i = 1; i <= N; ++i) {
    if (mp[{cur_city, next_city}] == 0) {
      ans2 += mp[{next_city, cur_city}];
    }
    temp = graph[next_city][0];
    if (temp == cur_city) {
      temp = graph[next_city][1];
    }
    cur_city = next_city;
    next_city = temp;
  }
  printf("Case %d: %d\n", cases, min(ans1, ans2));
}

int main() {
  int T, cases = 0;
  scanf("%d", &T);
  while (T--) {
    test_case(++cases);
  }
  return 0;
}
