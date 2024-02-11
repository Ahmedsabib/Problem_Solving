#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int64_t N; cin >> N;
    map<int64_t, int64_t>mp;
    vector<int>A(N), B(N), C(N);
    for(int i = 0; i < N; ++i){
    	cin >> A[i];
    	mp[A[i]]++;
    }
    for(int i = 0; i < N; ++i){
    	cin >> B[i];
    }
    for(int i = 0; i < N; ++i){
    	cin >> C[i];
    }
    vector<int>v;
    for(int i = 0; i < N; ++i){
    	int64_t x = C[i];
    	--x;
    	v.push_back(B[x]);
    }
    int64_t res = 0;
    for(int i = 0; i < N; ++i){
    	res += mp[v[i]];
    }
    cout << res << '\n';

    return 0;
}
