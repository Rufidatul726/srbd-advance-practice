#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<limits.h>

#define MAX_N 12
int city[MAX_N][MAX_N];
int cost[MAX_N][MAX_N];
int visited[MAX_N];
int length;

int tsp(int pos, int citiesVisited) {
	if (citiesVisited == length)return city[pos][0];
	int temp = -1;
	for (int i = 0; i < length; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			int new_cost = city[pos][i] + tsp(i, citiesVisited + 1);
			if (temp == -1 || temp > new_cost)temp = new_cost;
			visited[i] = 0;
		}
	}

	cost[citiesVisited][pos] = temp;
	return cost[citiesVisited][pos];
}

int tsp_solution(void) {
	int test_cases;

	scanf("%d", &test_cases);

	while (test_cases > 0) {
		test_cases--;

		scanf("%d", &length);

		for (int i = 0; i < length; i++) {
			visited[i] = 0;
			for (int j = 0; j < length; j++) {
				scanf("%d", &city[i][j]);
				cost[i][j] = -1;
			}
		}
		
		visited[0] = 1;
		printf("%d\n", tsp(0, 1));
	}
}