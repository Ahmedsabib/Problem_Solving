#include <bits/stdc++.h>
using namespace std;
bool check(string s, string t) {
  return s == t;
}
string rotate_x(string &s) {
  char x = s[0];
  s[0] = s[1];
  s[1] = s[5];
  s[5] = s[4];
  s[4] = x;
  return s;
}
string rotate_z(string &s) {
  char x = s[1];
  s[1] = s[3];
  s[3] = s[4];
  s[4] = s[2];
  s[2] = x;
  return s;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  string tt;
  while (cin >> tt && tt != "\n") {
    string s = tt.substr(0, 6);
    string t = tt.substr(6, 12);
    int ok = 1;
    for (int i = 0; i < 6; ++i) {
      ok = check(s, t);
      if (ok) {
        break;
      }
      else if (i < 4) {
        s = rotate_x(s);
      }
      else if (i == 4) {
        s = rotate_z(s);
        s = rotate_x(s);
      }
      else {
        rotate_x(s);
        rotate_x(s);
      }
      for (int j = 0; j < 4; ++j) {
        ok = check(s, t);
        if (ok) {
          break;
        }
        else {
          rotate_z(s);
        }
      }
      if (ok) {
        break;
      }
    }
    cout << (ok ? "TRUE\n" : "FALSE\n");
  }
  return 0;
}
