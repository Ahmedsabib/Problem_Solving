#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    string s; cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    if (t[0] == t[3]) {
        cout << "Weak" << '\n';
        return 0;
    }
    for (int i = 0; i < 3; ++i) {
        int x = (int)(s[i]-'0');
        int y = (int)(s[i+1]-'0');
        if (y != (x+1)%10) {
            cout << "Strong" << '\n';
            return 0;
        }
    }
    cout << "Weak" << '\n';
    
    return 0;
}
