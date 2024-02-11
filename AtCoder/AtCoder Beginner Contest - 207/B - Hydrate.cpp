#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int a, b, c, d; cin >> a >> b >> c >> d;
    int64_t cyan = a, red = 0, ans = 0, ok = 0;
    while(1){
        cyan += b;
        red += c;
        ++ans;
        if(cyan <= d*red) break;
        if(ans > 100005){
            ok = 1;
            break;
        }
    }
    cout << (ok? -1:ans) << '\n';

    return 0;
}
