#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

int getint(char s[1000], int start, int *end) {
	int i, j=0;
	int num[100] = { 0 };
	int decimal_pos = 1;
	int sum = 0;

	for(i = start; ;i++) {
		if (s[i] == '\0')break;
		if (s[i] >= '0' && s[i] <= '9') {
			num[j++] = s[i] - 48;
		}
		else {
			*end = i-1;
			break;
		}
	}

	for(i = j-1; i >= 0; i--) {
		sum = sum + num[i] * decimal_pos;
		decimal_pos *= 10;
	}
	return sum;
}

int string_to_binary_to_k(char s[1000], int k) {
	int i = 0;
	int level = 0;
	int sum = 0;
	int end = 0;

	while (s[i] != '\0') {
		if (s[i] == '(') {
			level++;
		}
		if (s[i] >= '0' && s[i] <= '9' && level==k+1) {
			sum = sum + getint(s, i, &end);
			i = end;
		}
		if (s[i] == ')') {
			level--;
		}
		i++;
	}

	return sum;
}

int sum_of_node_in_kth_level(void) {
	int k, i=0;
	char s[1000];

	if (scanf("%d", &k) != 1) {
		return -1;
	}

	
	if (scanf("%s", &s) != 1) {
		return -1;
	}

	int x = string_to_binary_to_k(s, k);
	printf("%d", x);

	return 0;
}

//int main(void) {
	//sum_of_node_in_kth_level();
//}