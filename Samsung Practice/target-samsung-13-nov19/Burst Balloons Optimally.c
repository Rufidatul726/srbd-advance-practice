#include<stdio.h>
#include<stdlib.h>

int find_max_score(int number_of_balloons, long long int balloons[number_of_balloons+2],
                  long long int score[number_of_balloons+2][number_of_balloons+2], int left, int right) {
    if(left > right) return 0;
    if(score[left][right] > 0) return score[left][right];

    long long int max_score = 0;
    for(int i = left; i <= right; i++) {
        long long int temp = 0;
        temp = balloons[left-1] * balloons[right+1];
        if(left==1 && right==number_of_balloons){
            if(temp<balloons[i])temp=balloons[i];
        }

        temp += find_max_score(number_of_balloons, balloons, score, left, i-1) + find_max_score(number_of_balloons, balloons, score, i+1, right);

        if(temp > max_score) {
            max_score = temp;
        }
    }

    score[left][right] = max_score;
    return max_score;
}

int solve(long long int balloons[], int number_of_balloons) {
    long long int score[number_of_balloons+2][number_of_balloons+2];

    // Initialize score array to 0
    for(int i = 0; i < number_of_balloons+2; i++) {
        for(int j = 0; j < number_of_balloons+2; j++) {
            score[i][j] = 0;
        }
    }

    return find_max_score(number_of_balloons, balloons, score, 1, number_of_balloons);
}

int main(void) {
    int number_of_balloons;
    scanf("%d", &number_of_balloons);

    long long int balloons[number_of_balloons+2];
    balloons[0] = 1;
    balloons[number_of_balloons+1] = 1;

    for(int i = 1; i <= number_of_balloons; i++) {
        scanf("%lld", &balloons[i]);
    }

    printf("%d", solve(balloons, number_of_balloons));

    return 0;
}
