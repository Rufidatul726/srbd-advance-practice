#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n;
int m[20][20];
int cost[1<<20][20];

int solve(int mask, int pos){
    if(mask ==(1<<n)-1)return m[pos][0];
    if(cost[mask][pos]!=-1)return cost[mask][pos];

    int temp_cost=-1;

    for(int i=0; i<n; i++){
        if(!(mask & (1<<i))){
            int new_cost=m[pos][i] + solve(mask | (1<<i), i);
            if(temp_cost==-1 || temp_cost>new_cost)temp_cost=new_cost;
        }
    }

    cost[mask][pos]=temp_cost;
    return cost[mask][pos];
}

int main(void){
    int t;

    scanf("%d", &t);

    while(t>0){
        scanf("%d", &n);
        int i, j;

        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                scanf("%d", &m[i][j]);
            }
        }

        memset(cost, -1, sizeof(cost));

        printf("%d\n", solve(1, 0));
        t--;
    }

}
