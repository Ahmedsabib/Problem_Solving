#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int64_t N; cin >> N;
    vector<int64_t>A(N);
    for(auto& x: A) cin >> x;
    sort(A.begin(), A.end());
    for(int i = 0; i < N; ++i){
        if(A[i] != i+1){
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';

    return 0;
}
