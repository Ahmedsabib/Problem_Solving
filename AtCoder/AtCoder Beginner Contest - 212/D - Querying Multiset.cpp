#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int n; cin >> n;
    multiset<int64_t> s;
    int64_t last = 0;
    for (int i = 0; i < n; ++i) {
        int64_t x; cin >> x;
        if (x == 1) {
            int64_t y; cin >> y;
            s.insert(y-last);
        }
        else if (x == 2) {
            int64_t y; cin >> y;
            last += y;
        }
        else if (x == 3) {
            cout << *s.begin()+last << '\n';
            s.erase(s.begin());
        }
    }
        
    return 0;
}
