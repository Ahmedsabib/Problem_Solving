#include <bits/stdc++.h>
 
using namespace std;  
 
const int MOD=1000000007;
map<long long, long long>f;
 
long long fib(long long n){
	if(f.count(n)) return f[n];
	if(n == 0) return 0;
	if(n == 2 or n == 1) return 1;
	if(n%2 == 0){
		long long k = n/2;
		long long ret1 = fib(k-1), ret2 = fib(k);
		return f[n] = (((2*ret1)+ret2)%MOD * (ret2)%MOD)%MOD;
 }
 else{
  long long k = (n+1)/2;
  long long ret1 = fib(k-1), ret2 = fib(k);
  return f[n] = (((ret1*ret1)%MOD) + (ret2*ret2)%MOD)%MOD;
 }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  cout << fib(n) << '\n';
  return 0;
}
