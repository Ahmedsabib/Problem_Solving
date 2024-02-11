#include <bits/stdc++.h>
using namespace std;
void test_case() {
  int m, n;
  scanf("%d %d", &m, &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  map<int, int> mp, freq;
  for (int i = 0; i < n; ++i) {
    mp[a[i]] = i;
    freq[a[i]]++;
  }
  int pos1 = -1, pos2 = -1, x = 0;
  for (int i = 0; i < n; ++i) {
    x = m - a[i];
    if (x == a[i]) {
      if (freq[x] > 1) {
        pos2 = mp[a[i]];
        break;
      }
    }
    else {
      if (mp.count(x)) {
        pos1 = mp[a[i]];
        pos2 = mp[x];
        break;
      }
    }
  }
  if (pos1 == -1) {
    for (int i = pos2-1; i >= 0; --i) {
      if (a[i] == x) {
        pos1 = i;
        break;
      }
    }
  }
  printf("%d %d\n", pos1+1, pos2+1);
}
int main(int argc, char const *argv[]) {
  int t;
  scanf("%d", &t);
  while (t--) {
    test_case();
  }
  return 0;
}
