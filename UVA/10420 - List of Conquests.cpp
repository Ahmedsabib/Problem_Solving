#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int N; cin >> N;
    vector<string>v;
    for(int i = 0; i < N; ++i){
        string s; cin >> s;
        string t; getline(cin, t);
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    int cnt = 1;
    for(int i = 0; i < v.size(); ++i){
        if(v[i] == v[i+1]) ++cnt;
        else{
            cout << v[i] << ' ' << cnt << '\n';
            cnt = 1;
        }
    }
    
    return 0;
}
