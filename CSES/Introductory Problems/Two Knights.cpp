#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  for(int i = 1; i <= n; ++i){
   long long x = i*i;
   long long y = x*(x-1)/2;
   if(i > 2){
    y -= 4*(i-1)*(i-2);
   }
   cout << y << '\n';
  }
  return 0;
}
