#include <bits/stdc++.h>
using namespace std;

void run_case(int tests) {
	int bat_field, green_lem, blue_lem;
	scanf("%d %d %d", &bat_field, &green_lem, &blue_lem);
	multiset<int, greater<int>> green_pow, blue_pow;
	
	for (int i = 0; i < green_lem; ++i) {
		int x;
		scanf("%d", &x);
		green_pow.insert(x);
	}

	for (int i = 0; i < blue_lem; ++i) {
		int x;
		scanf("%d", &x);
		blue_pow.insert(x);
	}

	while (!blue_pow.empty() > 0 && !green_pow.empty() > 0) {
		int len = min({bat_field, (int)blue_pow.size(), (int)green_pow.size()});
		queue<int> blue_fighters, green_fighters;

		for (int i = 0; i < len; ++i) {
			auto b = blue_pow.begin();
			auto g = green_pow.begin();

			green_fighters.push(*g);
			blue_fighters.push(*b);

			blue_pow.erase(b);
			green_pow.erase(g);
		}

		for (int i = 0; i < len; ++i) {
			int b = blue_fighters.front();
			int g = green_fighters.front();

			blue_fighters.pop();
			green_fighters.pop();

			if (b == g)
				continue;
			if (b < g)
				green_pow.insert(g - b);
			else
				blue_pow.insert(b - g);
		}
	}

	if (blue_pow.empty() && green_pow.empty()) {
		printf("green and blue died\n");

		if (tests)
			printf("\n");
	}
	else if (blue_pow.empty()) {
		printf("green wins\n");

		for (auto& x: green_pow)
			printf("%d\n", x);

		if (tests)
			printf("\n");
	}
	else if (green_pow.empty()) {
		printf("blue wins\n");

		for (auto& x: blue_pow)
			printf("%d\n", x);

		if (tests)
			printf("\n");
	}
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests;
    scanf("%d", &tests);

    while (tests-- > 0)
        run_case(tests);

    return 0;
}
