#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int64_t N; cin >> N;
    vector<int64_t> arr(N);
    map<int64_t, int64_t> mp;
    for(int i = 0; i < N; ++i){
        cin >> arr[i];
    }
    int64_t sum = 0;
    for(int i = 0; i < N; ++i){
        sum += i - mp[arr[i]];
        mp[arr[i]]++;
    }
    cout << sum << '\n';
    
    return 0;
}
