#include <bits/stdc++.h>

int binpow(int a, int b, int m){

	a %= m;
	int res = 1;
	while(b > 0){
		if(b&1){
			res = res * a % m;
		}
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int T; cin >> T;
    while(T--){
        
        int64_t N, M; cin >> N >> M;
        int last_digits = binpow(N, M, 1000);
        double x = M*(log10(N));
        int first_digits = pow(10, x-floor(x))*100.0;
        printf("%d...%03d\n", first_digits, last_digits); 
    }
    
    return 0;	
}
