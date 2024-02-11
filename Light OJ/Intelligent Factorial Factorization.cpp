#include <bits/stdc++.h>

const int MAX = 1e6+7;
int primes[MAX], cnt = 0, i, is_prime[MAX], ara[MAX], last_prime;

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    is_prime[0] = is_prime[1] = true;
	for (i = 2; i * i <= MAX; i++) {
	    if (!is_prime[i]) {
	        for (int j = i * i; j <= MAX; j += i)
	            is_prime[j] = true;
	    }
	}
	for(i = 2; i <= MAX; ++i){
	    if(!is_prime[i]){
	        primes[cnt] = i;
	        ++cnt;
	    }
	}

    int T; cin >> T;
    for(int testCase = 1; testCase <= T; ++testCase){
        
        int64_t N; cin >> N;
        int64_t x = 0;
        for(i = 0; primes[i] <= N; ++i){
        	int64_t M = N;
        	int64_t k = 0;
        	while(M != 0){
        		k += M/primes[i];
        		M /= primes[i];
        	}
        	ara[x] = k;
        	++x;
        }
        last_prime = primes[i-1];
        cout << "Case " << testCase << ": " << N << " = ";
        for(int j = 0; primes[j] <= N; ++j){
        	cout << primes[j] << " (" << ara[j] << ")";
        	if(last_prime > primes[j]){
        		cout << " * ";
        	}
        }
        cout << '\n';
    }
    
    return 0;
}
