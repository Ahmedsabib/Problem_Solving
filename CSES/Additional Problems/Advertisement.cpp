#include <bits/stdc++.h>
 
using namespace std;
 
void test_case() {
	int n;
	scanf("%d", &n);
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	stack<int> s;
	int i = 0, top = 0;
	long long ans = 0, cnt = 0;
	while (i < n) {
		if (s.empty() || a[s.top()] <= a[i]) {
			s.push(i++);
		}
		else {
			top = s.top();
			s.pop();
			cnt = a[top] * (s.empty()? i : i - s.top() - 1);
			ans = max(ans, cnt);
		}
	}
	while (!s.empty()) {
		top = s.top();
		s.pop();
		cnt = a[top] * (s.empty()? i : i - s.top() - 1);
		ans = max(ans, cnt);
	}
	printf("%lld\n", ans);
}
 
int main(int argc, char const *argv[]) {
	int T = 1;
	// scanf("%d", &T);
	while (T--) {
		test_case();
	}
	return 0;
}
