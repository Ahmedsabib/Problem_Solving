#include <bits/stdc++.h>

const int64_t INF = 1100000000000000000;;

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int64_t N, M; cin >> N >> M;
    vector<int64_t>A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    for(int i = 0; i < M; ++i){
        int64_t x; cin >> x;
        int64_t f = INF, v = 0;
        while(f-v > 1){
            int64_t mid = (f+v)/2;
            int64_t cnt = upper_bound(A.begin(),A.end(), mid)-A.begin();
            if(mid - cnt >= x){
                f = mid;
            } else{
                v = mid;
            }
        }
        cout << f << '\n';
    }

    
    return 0;
}
