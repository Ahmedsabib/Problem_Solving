#include <bits/stdc++.h>
 
int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int64_t N; cin >> N;
    vector<int>A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int64_t m = A[N/2];
    int64_t cost = 0;
    for(int i = 0; i < N; ++i){
        cost += abs(A[i]-m);
    }
    cout << cost << '\n';
 
    return 0;
}
