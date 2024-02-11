#include <bits/stdc++.h>

using namespace std;

long long fib(long long x){
 long long sum = 0, i = 1, j = 1;
 for(int m = 0; ; ++m){
  i = sum;
  sum += j;
  j = i;
  if(sum == x){
   return 1;
  }
  else if(sum > x){
   return 0;
  }
 }
} 

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--){
   long long n;
   cin >> n;
   if(n == 1 or n == 0){
    cout << "IsFibo" << '\n';
   }
   else{
    long long ans = fib(n);
    if(ans == 1){
     cout << "IsFibo" << '\n';
    }
    else{
     cout << "IsNotFibo" << '\n';
    }
   }
  }
  return 0;
}
