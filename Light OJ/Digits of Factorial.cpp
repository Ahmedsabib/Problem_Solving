#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    double memoize[1000001];
    memoize[0] = 0;
    for(int i = 1; i <= 1000000; ++i){
        memoize[i] = memoize[i-1] + log(i);
    }

    int T; cin >> T;
    for(int testCase = 1; testCase <= T; ++testCase){
        
        int64_t N, M; cin >> N >> M;
        int64_t ans = memoize[N] / log(M) + 1;
        cout << "Case " << testCase << ": " << ans << '\n';
    }
    
    return 0;
}
