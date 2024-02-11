#include <bits/stdc++.h>

int opposite(int a){

	if(a == 1) return 6;
	else if(a == 2) return 5;
	else if(a == 3) return 4;
	else if(a == 4) return 3;
	else if(a == 5) return 2;
	else return 1;
}

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int a, b, c; cin >> a  >> b >> c;
    int sum = 0;
    sum += opposite(a) + opposite(b) + opposite(c);
    cout << sum << '\n';
    
    return 0;
}
