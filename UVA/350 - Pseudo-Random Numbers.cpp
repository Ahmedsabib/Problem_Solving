#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int z, i, m, l, cs = 0;
	while (cin >> z >> i >> m >> l) {
		if (z == 0 && i == 0 && m == 0 && l == 0) {
			break;
		}
		l = (z * l + i)%m;
		int ans = 1, d = l;
		while (1) {
			l = (z * l + i)%m;
			if (d == l) {
				break;
			}
			++ans;
		}
		cout << "Case " << ++cs << ": " << ans << '\n';
	}
	return 0;
}
