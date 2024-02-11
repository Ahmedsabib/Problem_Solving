#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, b;
  char op;
  cin >> a >> op >> b;
  if(op == '+') cout << a+b << '\n';
  else cout << a-b << '\n';
  return 0;
}
  

