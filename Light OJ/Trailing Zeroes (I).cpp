#include <bits/stdc++.h>

const int MAX = 1e6+7;

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
	vector<char> is_prime(MAX+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= MAX; i++) {
	    if (is_prime[i]) {
	        for (int j = i * i; j <= MAX; j += i)
	            is_prime[j] = false;
	    }
	}
	vector<int64_t>primes;
	for(int i = 2; i <= MAX; ++i){
	    if(is_prime[i]){
	        primes.push_back(i);
	    }
	}

    int T; cin >> T;
    for(int testCase = 1; testCase <= T; ++testCase){

    	int64_t N; cin >> N;
    	int64_t sum = 1;
    	for(int i = 0; i < MAX && primes[i]*primes[i] <= N; ++i){
    		if(N%primes[i] == 0){
    			int64_t k = 0;
    			while(N%primes[i] == 0){
    				N /= primes[i];
    				++k;
    				if(N == 1 || N == 0){
    					break;
    				}
    			}
    			sum *= k+1;
    		}
    	}
    	if(N != 1){
    		sum *= 2;
    	}
    	--sum;
    	cout << "Case " << testCase << ": " << sum << '\n';
    }
    
    return 0;
}
