#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int a, b, c; cin >> a >> b >> c;
    int ans = (a+b+c - min(a, min(b, c)));
    cout << ans << '\n';
    
    return 0;
}
