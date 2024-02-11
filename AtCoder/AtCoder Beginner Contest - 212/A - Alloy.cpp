#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int64_t a, b; cin >> a >> b;
    if (a == 0 && b > 0) {
        cout << "Silver" << '\n';
    }
    else if (a > 0 && b == 0) {
        cout << "Gold" << '\n';
    }
    else if (a > 0 &&  b > 0) {
        cout << "Alloy" << '\n';
    }
    
    return 0;
}
