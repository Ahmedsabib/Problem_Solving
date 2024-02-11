#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

void add_to_queue(int a) {
    if ((int)max_heap.size() && a >= max_heap.top())
        min_heap.push(a);
    else
        max_heap.push(a);

    if (abs((int)max_heap.size() - (int)min_heap.size()) > 1) {
        if ((int)max_heap.size() > (int)min_heap.size()) {
            int temp = max_heap.top();
            max_heap.pop();
            min_heap.push(temp);
        }
        else {
            int temp = min_heap.top();
            min_heap.pop();
            max_heap.push(temp);
        }
    }
}

double get_median() {
    int total = (int)min_heap.size() + (int)max_heap.size();
    double ans = 0;

    if (total&1) {
        if ((int)max_heap.size() > (int)min_heap.size())
            ans = max_heap.top();
        else
            ans = min_heap.top();
    }
    else {
        if (!min_heap.empty())
            ans += min_heap.top();

        if(!max_heap.empty())
            ans += max_heap.top();

        ans /= 2;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        add_to_queue(a);
        double ans = get_median();
        printf("%.1lf\n", ans);
    }

    return 0;
}
