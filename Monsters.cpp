#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir[4] = {'U', 'D', 'L', 'R'}; // Direction mapping

int n, m;
vector<string> grid;
vector<vector<int>> monsterDist, playerDist;
vector<vector<int>> direction; // To store the direction taken to reach each cell

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.';
}

void bfs(queue<pair<int, int>>& q, vector<vector<int>>& dist) {
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny) && dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                direction[nx][ny] = i; // Store the direction taken to reach (nx, ny)
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    grid.resize(n);
    monsterDist.assign(n, vector<int>(m, INF));
    playerDist.assign(n, vector<int>(m, INF));
    direction.assign(n, vector<int>(m, -1)); // Initialize with -1 to denote unvisited

    queue<pair<int, int>> monsterQueue, playerQueue;
    pair<int, int> start;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                monsterQueue.push({i, j});
                monsterDist[i][j] = 0;
            } else if (grid[i][j] == 'A') {
                start = {i, j};
                playerQueue.push({i, j});
                playerDist[i][j] = 0;
            }
        }
    }

    bfs(monsterQueue, monsterDist);
    bfs(playerQueue, playerDist);

    for (int i = 0; i < n; i++) {
        for (int j : {0, m - 1}) {
            if (playerDist[i][j] < monsterDist[i][j]) {
                cout << "YES\n";
                string path;
                pair<int, int> cur = {i, j};
                while (cur != start) {
                    int d = direction[cur.first][cur.second];
                    path += dir[d];
                    cur = {cur.first - dx[d], cur.second - dy[d]};
                }
                reverse(path.begin(), path.end());
                cout << path.size() << endl;
                cout << path << endl;
                return 0;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i : {0, n - 1}) {
            if (playerDist[i][j] < monsterDist[i][j]) {
                cout << "YES\n";
                string path;
                pair<int, int> cur = {i, j};
                while (cur != start) {
                    int d = direction[cur.first][cur.second];
                    path += dir[d];
                    cur = {cur.first - dx[d], cur.second - dy[d]};
                }
                reverse(path.begin(), path.end());
                cout << path.size() << endl;
                cout << path << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}
