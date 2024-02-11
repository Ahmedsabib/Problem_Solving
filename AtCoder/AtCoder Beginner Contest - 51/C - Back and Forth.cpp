#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  string s1(d-b, 'U');
  string s2(c-a, 'R');
  string s3(d-b, 'D');
  string s4(c-a, 'L');
  cout << s1 + s2 + s3 + s4 + 'L' + s1 + 'U' + 'R' + s2 + 'D' + 'R' + s3 + 'D' + 'L' + s4 + 'U' << '\n';
  return 0;
}
