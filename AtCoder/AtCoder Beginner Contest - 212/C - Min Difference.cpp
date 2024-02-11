#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        p.push_back({x, 0});
    }
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        p.push_back({x, 1});
    }
    sort(p.begin(), p.end());
    int ans = 1e9+7;
    for (int i = 0; i < n+m-1; ++i) {
        if (p[i].second != p[i+1].second) {
            ans = min(ans, abs(p[i].first-p[i+1].first));
        }
    }
    cout << ans << '\n';
    
    return 0;
}
