#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    long long N; cin >> N;
   	long long ans = 15;
    for(long long i = 1; i*i <= N; ++i){
   		if(N%i) continue;
   		long long M = N/i;
   		long long cnt = 0;
   		while(M > 0){
   			++cnt;
   			M /= 10;
   		}
   		ans = min(ans, cnt);
    }
    cout << ans << '\n';
    
    return 0;
}
