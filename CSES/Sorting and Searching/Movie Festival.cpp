#include <bits/stdc++.h>

using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int N; cin >> N;
    vector<pair<int64_t, int64_t>>v(N);
    for(int i = 0; i < N; ++i){
        cin >> v[i].first >>v[i].second;
    }
    sort(v.begin(), v.end(), sortbysec);
    int64_t i = 0, temp = 0, ans = 0;
    while(i < N){
        if(temp <= v[i].first){
            ++ans;
            temp = v[i].second;
        }
        ++i;
    }
    cout << ans << '\n';
    
    return 0;
}
