#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

vector<bool> is_prime(maxn + 1, true);
vector<int> primes, visited(1005, 0);

void sieve_of_eratosthenes() {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= maxn; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= maxn; j += i) {
        is_prime[j] = false;
      }
    }
  }
  for (int i = 2; i <= maxn; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
}

vector<int> prime_factor(int n) {
  vector<int> factors;
  int temp = n;
  for (int i = 0; i < (int)primes.size() && primes[i] * primes[i] <= n; ++i) {
    if (n%primes[i] == 0) {
      while (n%primes[i] == 0) {
        n /= primes[i];
      }
      factors.push_back(primes[i]);
    }
  }
  if (n != 1 && n != temp) {
    factors.push_back(n);
  }
  return factors;
}


int bfs(int node, int dest) {
  queue<pair<int, int>> q;
  q.push({node, 0});
  for (int i = 0; i < maxn; ++i) {
    visited[i] = 0;
  }
  visited[node] = 1;
  while (!q.empty()) {
    pair<int, int> top = q.front();
    q.pop();
    if (top.first == dest) {
        return top.second;
    } 
     
    vector<int> factors = prime_factor(top.first);
    for (auto& edges: factors) {
      if (!visited[edges + top.first] && edges + top.first <= dest) {
        q.push({edges + top.first, top.second + 1});
        visited[edges + top.first] = 1;
      }
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  sieve_of_eratosthenes();
  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    int n, m;
    cin >> n >> m;
    cout << bfs(n, m) << '\n';
  }
  return 0;
}
