#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
   long long n;
   cin >> n;
   long long sum = 0, a = 1, b = 2;
   while(b <= n){
    if(b%2 == 0){
     sum += b;
    }
    long long next = a+b;
    a = b;
    b = next;
   }
   cout << sum << '\n';
  }
  return 0;
}
