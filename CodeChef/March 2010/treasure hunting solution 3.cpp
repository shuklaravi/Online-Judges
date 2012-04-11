#include <iostream>
#include <cstdio>

using namespace std;

char grid[20][20];

int c;

int tx[13];
int ty[13];

int adj[13][13];
int dist[13][13];

int q[1000];
int k;
int distDone[13][13];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int distFromSource[13];
int distFromDest[13];

#define INF 10000

int t;

int done[1<<13][13];
int memo[1<<13][13];

int sourceToDest;

int go(int state, int pos){
	int &ret = memo[state][pos];
	int &mark = done[state][pos];
	if (mark == t){
		return ret;
	}

	if (state == (1 << c) - 1){
		mark = t;
		return ret = distFromDest[pos];
	}


	int i;
	mark = t;
	ret = INF;

	for(i = 0; i < c; ++i) if (((1<<i) & state) == 0){
		int temp = adj[pos][i] + go(state | (1<<i), i);
		if(temp < ret) ret = temp;
	}

	return ret;
}

void showRes(int val){
	if (val >= INF) printf("%d\n", -1);
	else printf("%d\n", val);
}

int main (void){
	//freopen("n1.in", "r", stdin);
	int T, n, i, j;
	scanf("%d", &T);
	k = 0;
	for(i = 0; i < 13; ++i) for (j = 0; j < 13; ++j) distDone[i][j] = 0;
	for (i = 0; i < (1<<13); ++i) for (j = 0; j < 13; ++j) done[i][j] = 0;

	for(t = 1; t <= T; ++t){
		scanf("%d", &n);

		for(i=0; i<n; ++i) scanf("%s", &grid[i]);

		c = 0;

		if (grid[0][0] == '*') grid[0][0] = '.';

		for (i = 0; i < n; ++i){
			for (j = 0; j < n; ++j){
				if (grid[i][j] == '*'){
					tx[c] = i;
					ty[c] = j;
					c++;
				}
			}
		}

		for (i = 0; i < c; ++i){
			int front = 0;
			int back = 0;

			q[front++] = tx[i];
			q[front++] = ty[i];

			dist[tx[i]][ty[i]] = 0;

			k++;
			distDone[tx[i]][ty[i]] = k;


			while (back < front){
				int x = q[back++];
				int y = q[back++];

				for (j = 0; j < 4; ++j){
					int nx = x + dx[j];
					int ny = y + dy[j];

					if (nx >= 0 && ny >= 0 && nx < n && ny < n){
						if (distDone[nx][ny] != k && grid[x][y] != '#'){
							distDone[nx][ny] = k;
							dist[nx][ny] = dist[x][y] + 1;
							q[front++] = nx;
							q[front++] = ny;
						}
					}
				}
			}


			for (j = 0; j < c; ++j){
				if (distDone[tx[j]][ty[j]] == k){
					adj[i][j] = dist[tx[j]][ty[j]];
				}
				else{
					adj[i][j] = INF;
				}
			}
		}

		int front = 0;
		int back = 0;

		q[front++] = 0;
		q[front++] = 0;

		dist[0][0] = 0;

		k++;
		distDone[tx[i]][ty[i]] = k;


		while (back < front){
			int x = q[back++];
			int y = q[back++];

			for (j = 0; j < 4; ++j){
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx >= 0 && ny >= 0 && nx < n && ny < n){
					if (distDone[nx][ny] != k && grid[x][y] != '#'){
						distDone[nx][ny] = k;
						dist[nx][ny] = dist[x][y] + 1;
						q[front++] = nx;
						q[front++] = ny;
					}
				}
			}
		}


		for (j = 0; j < c; ++j){
			if (distDone[tx[j]][ty[j]] == k){
				distFromSource[j] = dist[tx[j]][ty[j]];
			}
			else{
				distFromSource[j] = INF;
			}
		}

		if (distDone[n-1][n-1] == k) sourceToDest = dist[n-1][n-1];
		else sourceToDest = INF;

		if (c == 0) {
			showRes(sourceToDest); continue;
		}

		front = 0;
		back = 0;

		q[front++] = n - 1;
		q[front++] = n - 1;

		dist[n-1][n-1] = 0;

		k++;
		distDone[tx[i]][ty[i]] = k;


		while (back < front){
			int x = q[back++];
			int y = q[back++];

			for (j = 0; j < 4; ++j){
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx >= 0 && ny >= 0 && nx < n && ny < n){
					if (distDone[nx][ny] != k && grid[x][y] != '#'){
						distDone[nx][ny] = k;
						dist[nx][ny] = dist[x][y] + 1;
						q[front++] = nx;
						q[front++] = ny;
					}
				}
			}
		}


		for (j = 0; j < c; ++j){
			if (distDone[tx[j]][ty[j]] == k){
				distFromDest[j] = dist[tx[j]][ty[j]];
			}
			else{
				distFromDest[j] = INF;
			}
		}

		int res = INF;
		for (i = 0; i < c; ++i){
			int temp = distFromSource[i] + go(1<<i, i);
			if (temp < res) res = temp;
		}
		showRes(res);
	}

	return 0;
}
