#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int64_t a, b, c; cin >> a >> b >> c;
    if(c%2 == 0){
        a = abs(a);
        b = abs(b);
    }
    if(a < b) cout << '<' << '\n';
    else if(a > b) cout << '>' << '\n';
    else cout << '=' << '\n';
    
    return 0;
}
