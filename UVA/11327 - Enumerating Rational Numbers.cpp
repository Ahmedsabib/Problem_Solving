#include <bits/stdc++.h>

const int n = 2e5+7;

int64_t phi[n];

int64_t gcd (int64_t a, int64_t b) {
    return b ? gcd (b, a % b) : a;
}

//Finding the number of coprimes to n
//Sieve way
//Time Complexity O(n log log n)
void phi_1_to_n() {
    phi[0] = 0;
    phi[1] = 2;
    for (int i = 2; i <= n; i++) {
        phi[i] = i;
    }
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
        phi[i] = phi[i] + phi[i-1];
    }
}

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    phi_1_to_n();
    int64_t N;
    while (cin >> N && N > 0) {

        if (N == 1) {
            cout << "0/1" << '\n';
            continue;
        }
        if (N == 2) {
            cout << "1/1" << '\n';
            continue;
        }
        int64_t lb = lower_bound(phi, phi+n, N)-phi;
        int64_t sub = N - phi[lb-1];
        int64_t cnt = 0;
        for (int i = 1; i <= lb; ++i) {
            if (gcd(i, lb) == 1) {
                ++cnt;
                if (cnt == sub) {
                    cout << i << "/" << lb << '\n';
                    break;
                }
            }
        }
    }
    
    return 0;
}
