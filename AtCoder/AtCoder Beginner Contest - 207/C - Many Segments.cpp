#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int N; cin >> N;
    vector<int64_t> l(N), r(N);
    for(int i = 0; i < N; ++i){
        int64_t x; cin >> x;
        cin >> l[i] >> r[i];
        l[i] *= 2;
        r[i] *= 2;
        if(x == 3 || x == 4) l[i]++;
        if(x == 1 || x == 3) r[i]++;
    }
    int64_t ans = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = i +1; j < N; ++j){
            if(min(r[i], r[j]) > max(l[i], l[j])) ++ans;
        }
    }
    cout << ans << '\n';
    
    return 0;
}
