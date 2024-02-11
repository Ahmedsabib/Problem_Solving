#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int64_t N; cin >> N;
    vector<int64_t>A(N);
    for(int i = 0; i < N; ++i){
    	cin >> A[i];
    }
    int64_t sum = -1e9, best = -1e9;
    for(int i = 0; i < N; ++i){
    	sum = max(sum+A[i], A[i]);
    	best = max(sum, best);
    }
    cout << best << '\n';
    
    return 0;
}
