#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> g(H);
  for (auto& s : g) cin >> s;
  vector vis(H, vector<int>(W, false));

  int i = 0, j = 0;
  while (1) {
    if (vis[i][j] == true) {
      cout << -1 << endl;
      exit(0);
    }
    vis[i][j] = true;
    if (g[i][j] == 'U' and i != 0) {
      --i;
    } else if (g[i][j] == 'D' and i != H - 1) {
      ++i;
    } else if (g[i][j] == 'L' and j != 0) {
      --j;
    } else if (g[i][j] == 'R' and j != W - 1) {
      ++j;
    } else {
      break;
    }
  }
  cout << i + 1 << " " << j + 1 << endl;
}
