#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if(n == 2 or n == 3){
   cout << "NO  SOLUTION" << '\n';
   return 0;
  }
  else if(n == 1){
   cout << "1" << '\n';
   return 0;
  }
  else if(n == 4){
   cout << "2 4 1 3" << '\n';
   return 0;
  }
  if(n&1){
   for(int i = n-1; i >= 1; i -= 2){
    cout << i << ' ';
   }
   for(int i = n; i >= 1; i -= 2){
    cout << i << ' ';
   }
  }
  else{
   for(int i = n; i >= 1; i -= 2){
    cout << i << ' ';
   }
   for(int i = n-1; i >= 1; i -= 2){
    cout << i << ' ';
   }
  }
  return 0;
}
