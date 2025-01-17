#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define MAX_N 12

int n;
int m[MAX_N][MAX_N];
int dp[1<<MAX_N][MAX_N];

int solve(int mask, int pos){
    if(mask==(1<<n)-1){
        return m[pos][0];
    }
    if(dp[mask][pos]!=-1)return dp[mask][pos];

    int min_cost=-1;
    for(int i=0; i<n; i++){
        if((mask & (1<<i) ) == 0){
            int new_cost= m[pos][i] + solve(mask | (1<<i), i);
            if(new_cost<min_cost || min_cost==-1)min_cost=new_cost;
        }
    }

    dp[mask][pos]=min_cost;
    return dp[mask][pos];
}

int main(void){
    int t;

    scanf("%d", &t);

    while(t>0){
        scanf("%d", &n);
        memset(dp, -1, sizeof(dp));

        for(int i=0; i<n; i++){
            for(int j=0;j<n; j++){
                scanf("%d",&m[i][j]);
            }
        }

        printf("%d\n",solve(1, 0));


        t--;
    }
}
