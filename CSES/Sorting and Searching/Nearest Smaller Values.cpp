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
	for (int i = 0; i < n; ++i) {
		while (!s.empty() && a[s.top()] >= a[i]) {
			s.pop();
		}
		if (s.empty()) {
			printf("0 ");
		}
		else {
			printf("%d ", s.top() + 1);
		}
		s.push(i);
	}
}

int main(int argc, char const *argv[]) {
	int T = 1;
	// scanf("%d", &T);
	while (T--) {
		test_case();
	}
	return 0;
}
