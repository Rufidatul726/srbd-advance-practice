#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

#define MAX_N 12

int balloon[MAX_N];
int score[MAX_N][MAX_N];
int length;

int balloonburst(int start, int end) {
	if (start > end)return 0;

	for (int i = start; i <= end; i++) {
		int temp = balloon[start - 1] * balloon[end + 1];
		if (start == 1 && end == length) {
			temp = balloon[i];
		}
		temp += balloonburst(start, i - 1) + balloonburst(i + 1, end);
		if (score[start][end] < temp)score[start][end] = temp;
	}

	return score[start][end];
}

int balloonsolution(void) {
	scanf("%d", &length);

	balloon[0] = 1;
	balloon[length + 1] = 1;
	memset(score, -1, length* length * sizeof(int));
	for (int i = 1; i <= length; i++) {
		scanf("%d", &balloon[i]);
	}

	printf("%d\n", balloonburst(1, length));

	return 0;
}