#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

#define MAX_N 10000
int graph[MAX_N][MAX_N];
int explored[MAX_N];
int visited[MAX_N];
int n, m;
int cycle_found = 0;

void printCycle(int index, int len, int cycle[MAX_N]) {
	for (int i = index; i < len + index; i++) {
		printf("%d ", cycle[i]);
	}
}

void detectCycle(int node, int cycle[MAX_N], int cycleLen) {
	if (cycle_found == 1)return;
	int i, flag;

	visited[node] = 1;
	cycle[cycleLen] = node;

	for (i = 1; i <= n; i++) {
		flag = 0;
		if (graph[node][i] == 1) {
			if (visited[i] == 0) {
				detectCycle(i, cycle, cycleLen + 1);
			}
			else if (visited[i] == 1) {	//cycle detected
				for (int x = 0; x <= cycleLen; x++) {
					if (cycle[x] == i)flag = 1;
					if (flag == 1) {
						printCycle(x, cycleLen - x + 1, cycle);
						cycle_found = 1;
						break;
					}
				}
				if(cycle_found==1)return;
			}
			visited[i] = 0;
		}
	}

	visited[node] = 0;
	explored[node] = 1;
	return;
}

int main(void) {
	int t=10;

	while (t > 0) {

		int u, v, i, j;
		int cycle[MAX_N];

		scanf("%d %d", &n, &m);
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
			if (explored[i] == 0) {
				detectCycle(i, cycle, 0);
			}
		}

		if (cycle_found == 0) {
			printf("0");
		}

		printf("\n");

		t--;

	}
	return 0;
}