#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    long long N, K; cin >> N >> K;
    while(K > 0){
    	if(N%200 == 0){
    		N /= 200;
    	} else{
    		N *= 1000;
    		N += 200;
    	}
    	--K;
    }
    cout << N << '\n';

    return 0;
}
