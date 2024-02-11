#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int A, B, C; cin >> A >> B >> C;
	if(B - A == C - B) cout << "YES" << '\n';
	else cout << "NO" << '\n';
	return 0;
}
