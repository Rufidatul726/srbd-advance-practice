#include<stdio.h>
#include<string.h>
#include<limits.h>

#define MAX_SIZE 15

int n,m;
int conn[MAX_SIZE][MAX_SIZE];
int cost[MAX_SIZE][MAX_SIZE];
int explored[MAX_SIZE];
int visited[MAX_SIZE];
int cycle[MAX_SIZE];
int node_sum;
int best_len;

void dfs(int node, int curr_cycle[n], int curr_len){
    int i, j=0, flag=-1, curr_sum=0;

    for(i=0; i<curr_len; i++){
        if(curr_cycle[i]==node){
            flag=i;
        }
        if(flag!=-1){
            curr_sum+=curr_cycle[i];
        }
    }

    if(flag!=-1){
        if(node_sum>curr_sum){
            for(i=flag; i<curr_len; i++){
                cycle[j++]=curr_cycle[i];
            }
            best_len=j;
            return;
        }
    }

    curr_cycle[curr_len]=node;

    for(i=1; i<=n; i++ ){
        if(conn[node][i]==1){
            dfs(i, curr_cycle, curr_len + 1);

        }
    }

    explored[node]=1;
    return;
}

int main(void){
    scanf("%d %d", &n, &m);

    memset(cost, -1, sizeof(cost));
    memset(visited, 0, sizeof(visited));
    memset(explored, 0, sizeof(explored));
    memset(conn, 0, sizeof(conn));
    memset(cycle, 0, sizeof(cycle));

    int current_cycle[n];

    memset(current_cycle, 0, sizeof(int)*n);
    int curr_len=0;
    node_sum=INT_MAX;
    best_len=INT_MAX;

    int i, j, u,v ;

    for(i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        conn[u][v]=1;
    }

    for(i=1; i<=n; i++){
        if(explored[i]==0){
            dfs(i, current_cycle, curr_len);
        }
    }

    printf("%d\n",  best_len);

    for(i=1; i<=n; i++){
        for(j=0; j<best_len; j++){
            if(cycle[j]==i){
                printf("%d ", cycle[j]);
                break;
            }
        }
    }
}
