#include <bits/stdc++.h>
 
using namespace std;
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long T;
  cin >> T;
  while(T--){
   long long A, B;
   cin >> A >> B;
   if(A < B) swap(A, B);
   if(A > 2*B) cout << "NO" << '\n';
   else if((A+B)%3 == 0) cout << "YES" << '\n';
   else cout << "NO" << '\n';
  }
  return 0;
} 
