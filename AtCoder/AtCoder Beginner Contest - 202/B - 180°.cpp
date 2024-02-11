#include <bits/stdc++.h>

using namespace std;

int opposite(char a){

	if(a == '1') return 1;
	else if(a == '0') return 0;
	else if(a == '6') return 9;
	else if(a == '9') return 6;
	else if(a == '8') return 8;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    string S; cin >> S;
    reverse(S.begin(), S.end());
    string ans;
    for(int i = 0; i < S.size(); ++i){
    	ans += to_string(opposite(S[i]));
    }
    cout << ans << '\n';
    
    return 0;
}
