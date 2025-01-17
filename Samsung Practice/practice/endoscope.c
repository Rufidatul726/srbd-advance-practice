#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define MAX_N 50
#define MAX_L 20

int matrix[MAX_N]{MAX_N}

int n,m,l;

bool left(int curr_x, int curr_y){
    if(matrix[curr_x][curr_y]==1 || matrix[curr_x][curr_y]==3 || matrix[curr_x][curr_y]==6 || matrix[curr_x][curr_y]==7)return true;
    return false;
}

bool right(int curr_x){
    if(matrix[curr_x][curr_y]==1 || matrix[curr_x][curr_y]==3 || matrix[curr_x][curr_y]==4 || matrix[curr_x][curr_y]==5)return true;
    return false;
}

bool up(int curr_x){
    if(matrix[curr_x][curr_y]==1 || matrix[curr_x][curr_y]==2 || matrix[curr_x][curr_y]==7 || matrix[curr_x][curr_y]==4)return true;
    return false;
}

bool down(int curr_x){
    if(matrix[curr_x][curr_y]==1 || matrix[curr_x][curr_y]==2 || matrix[curr_x][curr_y]==5 || matrix[curr_x][curr_y]==6)return true;
    return false;
}

void gotoNextNode(int curr_nodeX, int curr_nodeY){
    if(left(curr_nodeX, curr_nodeY) && matrix[curr_nodeX-1][curr_nodeY]!=0)curr_nodeX-=1;
    else if(right(curr_nodeX, curr_nodeY) && matrix[curr_nodeX-1][curr_nodeY]!=0)curr_nodeX-=1;
    else if(up(curr_nodeX, curr_nodeY) && matrix[curr_nodeX-1][curr_nodeY]!=0)curr_nodeX-=1;
    else if(down(curr_nodeX, curr_nodeY) && matrix[curr_nodeX-1][curr_nodeY]!=0)curr_nodeX-=1;

}

int main(void){
    int t;

    scanf("%d", &t);

    while(t>0){
        int x, y;

        scanf("%d %d %d %d %d", &n,&m,&l,&x,&y);

        for(int i=0; i<n; i++){
            fot(int j=0; j<m; j++){
                scanf("%d", &matrix[i][j]);
            }
        }

        solve(x, y, l)

        t--;
    }
}
