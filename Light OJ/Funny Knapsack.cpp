#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 50;
const int maxw = 1e9 + 7;

int t, n, cs = 1;
ll w, a[maxn];
vector<ll> v1, v2;

void precal(ll pos, ll sum) {
		if (pos == n/2) {
				v1.push_back(sum);
				return;
		}
		precal(pos + 1, sum);
		if (sum + a[pos] <= w) {
				precal(pos + 1, sum + a[pos]);
		}
}

void precal_again(ll pos, ll sum) {
		if (pos == n) {
				v2.push_back(sum);
				return;
		}
		precal_again(pos + 1, sum);
		if (sum + a[pos] <= w) {
				precal_again(pos + 1, sum + a[pos]);
		}
}

int main() {
		scanf("%d", &t);
		while (t--) {
				scanf("%d %lld", &n, &w);
				for (int i = 0; i < n; ++i) {
						scanf("%lld", &a[i]);
				}
				v1.clear();
				v2.clear();
				precal(0, 0);
				precal_again(n/2, 0);
				sort(v1.begin(), v1.end());
				ll ans = 0;
				for (int i = 0; i < (int)v2.size(); ++i) {
						ans += upper_bound(v1.begin(), v1.end(), w - v2[i]) - v1.begin();
				}
				printf("Case %d: %lld\n", cs++, ans);
		}
		return 0;
}	
