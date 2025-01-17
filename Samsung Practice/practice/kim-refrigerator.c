#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define MAX_N 15
#define MAX_X 100

int n;
int graph_x[MAX_N];
int graph_y[MAX_N];
int visited[MAX_X][MAX_X];
int cost[MAX_N][MAX_N];
int dp[1<<MAX_N][MAX_N];

int dfs(int mask, int pos){
   if(mask == (1<<(n+2))-1)return cost[pos][n+1];
   if(dp[mask][pos]!=-1)return dp[mask][pos];

   int temp=-1;
   for(int i=0; i<n+2; i++){
    if(!(mask & (1<<i))){
        int new_cost= cost[pos][i] + dfs((mask | (1<<i)), i);
        if(temp==-1 || temp>new_cost)temp=new_cost;
    }
   }

   dp[mask][pos]=temp;
   return temp;
}

int abs_x(int x){
    if(x<0)return -x;
    return x;
}

int distance(int x1, int y1, int x2, int y2){
    int dist= abs_x(x2-x1) + abs_x(y2-y1);
    return dist;
}

int main(void){
    int testcases;

    for(int testcase=0; testcase<10; testcase++){
        scanf("%d", &n);

        int i,j;
        scanf("%d %d", &graph_x[0], &graph_y[0]);
        scanf("%d %d", &graph_x[n+1], &graph_y[n+1]);
        for(i=1; i<=n; i++){
            scanf("%d %d", &graph_x[i], &graph_y[i]);
        }

        memset(dp, -1, sizeof(dp));

        for(i=0; i<n+2; i++){
            cost[i][i]=0;
            for(j=i+1; j<n+2; j++){
                cost[i][j]=distance(graph_x[i], graph_y[i], graph_x[j], graph_y[j]);
                cost[j][i]=cost[i][j];
            }
        }

        printf("cost =%d\n", dfs(1, 0));

        for(i=0; i<n+2; i++){
            for(j=0; j<n+2; j++){
                printf("%d\t", dp[i][j]);
            }
            printf("\n");
        }

    }
}
