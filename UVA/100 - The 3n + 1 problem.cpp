#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int64_t N, M;
    while(cin >> N >> M){

    	cout << N << ' ' << M << ' ';
    	if(N > M) swap(N, M);
    	int64_t i = N, x = N, best = 0, cnt = 0;
    	while(i <= M){
    		++cnt;
    		if(x == 1){
    			++i;
    			x = i;
    			best = max(cnt, best);
    			cnt = 0;
    		}
    		else{
    			if(x&1){
    				x = 3*x+1;
    			}else{
    				x = x/2;
    			}
    		}
    	}
    	cout << best << '\n';
    }
    
    return 0;
}
