#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    double a, b; cin >> a >> b;
    double ans = 0;
    ans = b/100 * a;
    cout << ans << '\n';
    
    return 0;
}
