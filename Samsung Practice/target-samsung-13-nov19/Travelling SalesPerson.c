#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

long long int tsp(int number_of_cities, long long int city_cost[number_of_cities][number_of_cities],
                  long long int dp[1 << number_of_cities][number_of_cities], int mask, int pos) {
    if (mask == (1 << number_of_cities) - 1) {
        return city_cost[pos][0];  // Return cost to starting city
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    long long int new_ans = LLONG_MAX;

    for (int i = 0; i < number_of_cities; i++) {
        if (!(mask & (1 << i))) {  // City not yet visited
            long long int temp_ans = city_cost[pos][i] + tsp(number_of_cities, city_cost, dp, mask | (1 << i), i);
            if (temp_ans < new_ans) {
                new_ans = temp_ans;
            }
        }
    }

    dp[mask][pos] = new_ans;
    return dp[mask][pos];
}

long long int solve(int number_of_cities, long long int city_cost[number_of_cities][number_of_cities]) {
    long long int dp[1 << number_of_cities][number_of_cities];

    for (int i = 0; i < (1 << number_of_cities); i++) {
        for (int j = 0; j < number_of_cities; j++) {
            dp[i][j] = -1;
        }
    }

    return tsp(number_of_cities, city_cost, dp, 1, 0);
}

int main(void) {
    int test_cases;
    scanf("%d", &test_cases);

    while (test_cases > 0) {
        int number_of_cities;
        scanf("%d", &number_of_cities);

        if (number_of_cities <= 0) {
            printf("Invalid number of cities.\n");
            test_cases--;
            continue;
        }

        long long int city_cost[number_of_cities][number_of_cities];

        for (int i = 0; i < number_of_cities; i++) {
            for (int j = 0; j < number_of_cities; j++) {
                scanf("%lld", &city_cost[i][j]);
            }
        }

        printf("%lld\n", solve(number_of_cities, city_cost));
        test_cases--;
    }

    return 0;
}
