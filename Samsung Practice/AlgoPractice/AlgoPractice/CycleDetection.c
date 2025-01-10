//#define _CRT_

#include<stdio.h>
#include<string.h>

#define MAX_N 10000
int graph[MAX_N][MAX_N];
int explored[MAX_N];
int visited[MAX_N];
int n, m, k;

void detectCycle(int node, int cycle[MAX_N], int cycleLen) {
	int i, j;

	visited[node] = 1;
	cycle[cycleLen] = node;

	for (i = 1; i <= n; i++) {
		if (graph[node][i] == 1) {
			if (visited[i] == 1) {	//cycle detected

			}
			else if (explored[i] == 1) {

			}
		}
	}

	explored[node] = 1;
	return;
}

int main(void) {
	scanf("%d %d %d", &n, &m, &k);
	int u, v, i, j;
	int cycle[MAX_N];

	for (i = 1; i <= n; i++) {
		visited[i] = 0;
		explored[i] = 0;
		cycle[i] = 0;
		for (j = 1; j <= n; j++) {
			graph[i][j] = 0;
		}
	}
	
	for (i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		graph[u][v] = 1;
	}

	for (i = 1; i <= n; i++) {
		detectCycle(i, cycle, 0);
	}

	return 0;
}