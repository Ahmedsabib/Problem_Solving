#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;

using pii = pair<int, int>;

int N, M;
pii init_pos;
queue<pii> Q;
vector<pii> monster;
char grid[MAXN + 1][MAXN + 1];
int dist[MAXN][MAXN], possible[MAXN][MAXN], visited[MAXN][MAXN], parent[MAXN][MAXN];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

string S = "RLDU";

int check(int x, int y) {
    return (x >= 1 && x <= N && y >= 1 && y <= M && !visited[x][y] && grid[x][y] == '.');
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> grid[i][j];

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (grid[i][j] == 'A')
                init_pos = {i, j};

            if (grid[i][j] == 'M')
                monster.push_back({i, j});

            dist[i][j] = 1e9 + 7;
        }
    }

    for (auto& [x, y]: monster) {
        Q.push({x, y});

        dist[x][y] = 0;
        parent[x][y] = -1;
    }

    // auto check = [&] (int x, int y) {
    //     return (x >= 1 && x <= N && y >= 1 && y <= M && !visited[x][y] && grid[x][y] == ".");
    // };

    while (!Q.empty()) {
        auto& [x, y] = Q.front();
        Q.pop();

        for (int i = 0; i < 4; ++i) {
            int newx = dx[i] + x;
            int newy = dy[i] + y;

            if (check(newx, newy)) {
                visited[newx][newy] = 1;
                dist[newx][newy] = dist[x][y] + 1;
                parent[newx][newy] = i;
                Q.push({newx, newy});
            }
        }
    }

    memset(visited, 0, sizeof(visited));

    Q.push(init_pos);
    parent[init_pos.first][init_pos.second] = -1;
    dist[init_pos.first][init_pos.second] = 0;
    possible[init_pos.first][init_pos.second] = 1;

    while (!Q.empty()) {
        auto& [x, y] = Q.front();
        Q.pop();

        for (int i = 0; i < 4; ++i) {
            int newx = dx[i] + x;
            int newy = dy[i] + y;

            if (check(newx, newy)) {
                visited[newx][newy] = 1;
                int d = dist[x][y] + 1;

                if (d < dist[newx][newy]) {
                    possible[newx][newy] = 1;
                    dist[newx][newy] = d;
                }

                parent[newx][newy] = i;
                Q.push({newx, newy});
            }
        }
    }

    pii ans_pos = {0, 0};

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (i == 1 || j == 1 || i == N || j == M) {
                if (possible[i][j]) {
                    ans_pos = {i, j};
                    break;
                }
            }
        }
    }

    if (ans_pos.first == 0 && ans_pos.second == 0) {
        cout << "NO\n";
        return 0;
    }

    string ans_path = "";

    while (parent[ans_pos.first][ans_pos.second] != -1) {
        int x = parent[ans_pos.first][ans_pos.second];
        ans_path += S[x];
        ans_pos.first -= dx[x];
        ans_pos.second -= dy[x];
    }

    reverse(ans_path.begin(), ans_path.end());

    cout << "YES\n" << (int)ans_path.size() << '\n' << ans_path << '\n';

    return 0;
}
