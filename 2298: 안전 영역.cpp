#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int s, floodHeight = 0;
vector<vector<int>> map;
int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };
void bfs(int i, int j, vector<vector<bool>>& visited) {
	queue<pair<int, int>> cp;
	cp.push({ i, j });
	visited[i][j] = true;
	int ip, jp;
	while (!cp.empty()) {
		ip = cp.front().first, jp = cp.front().second;
		cp.pop();
		for (int k = 0; k < 4; k++) {
			int ni = ip + di[k], nj = jp + dj[k];
			if (ni >= 0 && nj >= 0 && ni < s && nj < s) {
				if (!visited[ni][nj] && map[ni][nj] > floodHeight) {
					visited[ni][nj] = true;
					cp.push({ ni, nj });
				}
			}
		}
	}
}
int areaCount() {
	vector<vector<bool>> visited(s, vector<bool>(s, false));
	int count = 0;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (!visited[i][j] && map[i][j] > floodHeight) bfs(i, j, visited), count++;
		}
	}
	return count;
}
int main() {
	cin >> s;
	map.resize(s, vector<int>(s));
	int maxHeight = 0;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			cin >> map[i][j];
			maxHeight = max(map[i][j], maxHeight);
		}
	}
	int maxAreaCount = 0;
	for (int areas; floodHeight <= maxHeight; floodHeight++) {
		areas = areaCount();
		maxAreaCount = max(maxAreaCount, areas);
	}
	cout << maxAreaCount;
}
