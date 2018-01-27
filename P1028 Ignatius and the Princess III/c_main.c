#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N (120+5)

int main(){
  int n,calc_to=1;
  int div[MAX_N][MAX_N];

  while (scanf("%d",&n) != EOF){
    div[0][0]=1;
    div[1][1]=1;
    
    if (n >= calc_to){
      for (int calc=calc_to;calc <= n;calc++){
	div[calc][1]=1;
	//printf("%d ", div[calc][1]);
	for (int upper=2;upper <= calc;upper++){
	  div[calc][upper]=0;
	  for (int x=1 ; x<=upper ; x++){
	    div[calc][upper]+=div[calc-x][x>(calc-x)?(calc-x):x];
	  }
	  //printf("%d ", div[calc][upper]);
	}
	//printf("\n");
      }
    }


    printf("%d\n", div[n][n]);
  }
  return 0;
}
