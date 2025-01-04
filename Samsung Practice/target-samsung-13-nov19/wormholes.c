#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int absolute_x(int x){
    if(x<0)return -x;
    return x;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int distance_xy(int source_x, int source_y, int dest_x, int dest_y){
    int dis= absolute_x(dest_x-source_x) + absolute_x(dest_y-source_y);
    return dis;
}

int min_number(int first_number, int second_number){
    if(first_number<second_number)return first_number;

    return second_number;
}

int min_coins(int cost_graph[100][100], int number_of_wormholes, int *x, int *y, int graph_len){
    int i,j,k;

    for(k=0; k<graph_len; k++){
        for(i=0; i<graph_len; i++){
            if(i==k)continue;
            for(j=i+1; j<graph_len; j++){
                if(j==k)continue;
                cost_graph[i][j]=min_number(cost_graph[i][j], cost_graph[i][k]+cost_graph[k][j]);
                cost_graph[j][i]=cost_graph[i][j];
            }
        }
    }
    printf("\n---new graph---\n");
    for(i=0; i<graph_len; i++){
        for(j=0; j<graph_len; j++){
            printf("%d\t", cost_graph[i][j]);
        }
        printf("\n");
    }
    return cost_graph[graph_len-1][0];
}

int main(void){
    int t=0;

    scanf("%d", &t);

    while(t--){
        int number_of_wormholes;
        int source_x, source_y, dest_x, dest_y;
        int i=0, j=0, cost, temp, temp1;
        int cost_graph[100][100];
        memset(cost_graph, -1, sizeof(cost_graph));

        scanf("%d", &number_of_wormholes);
        int graph_len=number_of_wormholes*2+2;
        int x[graph_len], y[graph_len];

        scanf("%d%d%d%d", &x[0], &y[0], &x[graph_len-1], &y[graph_len-1]);

        for(i=1; i<graph_len-2; i=i+2){
           scanf("%d %d %d %d %d", &x[i], &y[i], &x[i+1], &y[i+1], &cost) ;
           temp = distance_xy(x[i], y[i], x[i+1], y[i+1]);
           cost_graph[i][i+1]=min_number(cost, temp);
           cost_graph[i+1][i]=cost_graph[i][i+1];
        }

        cost_graph[0][graph_len-1]=distance_xy(x[0], y[0], x[graph_len-1], y[graph_len-1]);
        cost_graph[graph_len-1][0]=cost_graph[0][graph_len-1];

        for(i=1; i<graph_len-1; i=i+2){
            cost_graph[0][i]=distance_xy(x[0], y[0], x[i], y[i]);
            cost_graph[i][0]=cost_graph[0][i];
        }

        for(i=0; i<graph_len; i++){
            cost_graph[i][i]=0;
            for(j=i+1; j<graph_len; j++){
                if(cost_graph[i][j]==-1){
                    cost_graph[i][j]=distance_xy(x[i], y[i], x[j], y[j]);
                    cost_graph[j][i]=cost_graph[i][j];
                }
            }
        }

        for(i=0; i<graph_len; i++){
            for(j=0; j<graph_len; j++){
                printf("%d\t", cost_graph[i][j]);
            }
            printf("\n");
        }

        printf("%d\n", min_coins(cost_graph, number_of_wormholes, x, y, graph_len));

        if(t<=0)break;
    }
}
