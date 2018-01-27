#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N (999999+5)

int main (){
  int N=0;
  int *num=NULL,*num_idx=NULL;
  int size=0;
  while (scanf("%d", &N) != EOF){
    if (N > size){
      num = (int*)realloc(num, sizeof(int)*N);
      num_idx = (int*)realloc(num_idx, sizeof(int)*N);
      size = N;
    }
    
    int n=0;
    for (int i=0;i<N;i++){
      int finded=-1,x;
      scanf("%d",&x);
      for (int i=0;i<n;i++){
	if (num_idx[i] == x){
	  finded = i;
	  break;
	}
      }

      if (finded == -1){
	num_idx[finded = n++] = x;
	num[finded] = 1;
      }
      else num[finded]+=1;
    }

    for (int i=0;i<n;i++){
      if (num[i] >= (N+1)/2){
	printf ("%d\n",num_idx[i]);
	break;
      }
    }
  }
  return 0;
}
