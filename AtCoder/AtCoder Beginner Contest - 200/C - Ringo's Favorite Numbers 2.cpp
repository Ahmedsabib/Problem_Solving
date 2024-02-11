#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    long long N; cin >> N;
    vector<int>A(N);
    map<int, int>mp;
    long long ans = 0;
    for(int i = 0; i < N; ++i){
    	cin >> A[i];
    	ans += mp[A[i]%200]++;
    }
    cout << ans << '\n';

    return 0;
}
