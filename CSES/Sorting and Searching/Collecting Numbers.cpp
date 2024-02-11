#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int64_t N; cin >> N;
    int64_t freq[N+1] = {0};
    for(int i = 1; i <= N; ++i) {
        int64_t x; cin >> x;
        freq[x] = i;
    }
    int64_t ans = 1, ind = 1;
    for(int i = 1; i <= N; ++i) {
        if(ind > freq[i]) {
            ++ans;
        }
        ind = freq[i];
    }
    cout << ans << '\n';
    
    return 0;
}
