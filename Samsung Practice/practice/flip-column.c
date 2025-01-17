#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>


#define MAX_SIZE 15
#define MAX_DEC 65536

int main(void){
    int i, j;
    int m[MAX_SIZE][MAX_SIZE];
    int power[MAX_SIZE+1];
    int numzero[MAX_SIZE];
    int decSet[MAX_DEC];
    power[0]=1;

    int n, mm, k, temp;
    int max=0;
    scanf("%d %d %d", &n, &mm, &k);

    for(i=1; i<=n+1; i++){
        power[i]=power[i-1] * 2;
    }

    for(i=0; i<power[n]; i++){
        decSet[i]=0;
    }

    for(i=0; i<n; i++){
        numzero[i]=0;
        temp=0;
        for(j=0; j<mm; j++){
            scanf("%d", &m[i][j]);
            if(m[i][j]==1){
                temp= temp + power[j];
            }else{
                numzero[i]++;
            }
        }
        if(k<numzero[i])continue;
        else if((k-numzero[i])%2==0){
            decSet[temp]++;
            if(max<decSet[temp])max=decSet[temp];
        }
    }


    printf("%d", max);

}
