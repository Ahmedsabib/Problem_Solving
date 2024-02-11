#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T; cin >> T;
    for(int testCase = 1; testCase <= T; ++testCase){
        
        cout << "Case " << testCase << ": " ;
        string s; cin >> s;
        if(s[4] == 's') cout << s << '\n';
        else{
            cout << s.substr(0, 4) << 's' << s.substr(4, s.size()-1) << '\n';
        }
    }
    
    return 0;
}
