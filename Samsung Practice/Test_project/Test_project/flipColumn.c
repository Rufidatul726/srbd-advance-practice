#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int main(void) {
	int matrix[15][15];
	int power[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
	int decimal[32770] = { 0 };
	int m, n, k, dec = 0, numZero = 0;
	int i, j;
	
	scanf("%d %d %d", &n, &m, &k);
	
	for (i = 0; i < m; i++) {
		dec = 0;
		for (j = 0; j < n; j++) {
			scanf("%d", &matrix[i][j]);
			if (matrix[i][j]==1) {
				dec += power[j];
			}
			else {
				numZero
			}
		}
	}
}