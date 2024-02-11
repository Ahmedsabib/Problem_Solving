#include <bits/stdc++.h>

const int MAX = 1e5+7;

std::vector<char> is_prime(MAX, true);
std::vector<int64_t> primes;

void sieve () {
    //Finding out the primes in simple way
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
    //asssigning values to an vector
    for (int i = 2; i <= MAX; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

//Finding the number of coprimes to n
//Normal way
//Time Complexity O(sqrt(n))
int64_t phi (int64_t n) {
    if (n == 1) return 0;
    int64_t result = n;
    for (int i = 0; i < (int)primes.size() && primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            while (n % primes[i] == 0) {
                n /= primes[i];
            }
            result -= result / primes[i];
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    sieve();
    int n;
    while (cin >> n && n > 0) {

        int64_t ans = phi(n);
        cout << ans << '\n';
    }
    
    return 0;
}
