#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>

#define MAX_M 100
#define MAX_N 11

int connection[MAX_N][MAX_N] = { 0 };
int explored[MAX_N] = { 0 };
int visited[MAX_N] = { 0 };
int cycle[MAX_N] = { 0 };
int length = INT_MAX;
int node_sum = INT_MAX;

void dfs(int node, int n, int current_cycle[MAX_N], int current_cycle_length) {
	int i , j, flag=0, cur_sum=0;
	if (explored[node] == 1)return;

	for (i = 0; i < current_cycle_length; i++) {
		if (node == current_cycle[i]) {	//cycle detected
			flag = i;
		}
		if (flag != 0) {
			cur_sum += current_cycle[i];
		}
	}

	if (flag != 0) {
		if (cur_sum < node_sum) {
			j = 0;
			for (i = flag; i < current_cycle_length; i++) {
				cycle[j++] = current_cycle[i];
			}
			length = j;
			return;
		}
	}

	current_cycle[current_cycle_length] = node;

	for (i = 1; i <= n; i++) {
		if (connection[node][i] == 1) {
			dfs(i, n, current_cycle, current_cycle_length + 1);
		}
	}

	explored[node] = 1;
	return;
}

int solve(void) {
	int n, m;
	int i, j, k=0;
	int u, v;
	int curr_len = 0;

	int current_cycle[MAX_N] = { 0 };

	if (scanf("%d %d", &n, &m) != 2) {
		return -1;
	}

	for (i = 0; i < m; i++) {
		if (scanf("%d %d", &u, &v) != 2) {
			return -1;
		}
		connection[u][v] = 1;
	}

	for (i = 1; i <= n; i++) {
		if (explored[i] == 0) {
			dfs(i, n, current_cycle, curr_len);
		}
	}

	for (i = 1; i <=n; i++) {
		for (j = 0; j < length; j++) {
			if (cycle[j] == i) {
				printf("%d ", i);
			}
		}
	}
}