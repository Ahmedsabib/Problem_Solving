#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
   
    int64_t N; cin >> N;
    vector<int64_t>arr(N);
    for(auto &x: arr) cin >> x;
    sort(arr.begin(), arr.end());
    int64_t sum = 0;
    for(int i = 0; i < N; ++i){
        if(arr[i] > sum+1){
            cout << sum+1 << '\n';
            return 0;
        }
        sum += arr[i];
    }
    cout << sum+1 << '\n';
    
    return 0;
}
