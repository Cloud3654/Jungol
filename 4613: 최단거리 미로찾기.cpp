#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
vector<vector<int>> maze;
vector<vector<bool>> visited;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int bfs(int stX, int stY) {
	queue<pair<int, int>> q;
	q.push({ stX, stY });
	visited[stX][stY] = true;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (maze[nx][ny] == 1 || visited[nx][ny]) continue;

			visited[nx][ny] = true;
			maze[nx][ny] = maze[x][y] + 1;
			q.push({ nx, ny });
		}
	}
	return (maze[0][m - 1] == 0 ? -1 : maze[0][m - 1]);
}
int main() {
	cin >> n >> m;
	maze = vector<vector<int>>(n, vector<int>(m));
	visited = vector<vector<bool>>(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> maze[i][j];
	}
	cout << bfs(n - 1, 0);
}
