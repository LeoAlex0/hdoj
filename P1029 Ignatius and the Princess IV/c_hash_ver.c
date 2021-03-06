#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main (){
  int *num=NULL,*mem_list=NULL;
  int size_num=0,size_list=0,N;

  while (scanf("%d",&N) != EOF){
    if (size_list < N) mem_list = (int*)realloc(mem_list,sizeof(int)*(size_list = N));
    if (num != NULL) memset(num, 0, sizeof(int)*size_num);

    int list_used=0;
    for (int i=0;i<N;i++){
      int x;
      scanf ("%d",&x);

      if (x > size_num){
	num = (int*) realloc(num, sizeof(int)*(x+1)*2);
	memset (num+size_num,0,sizeof(int)*((x+1)*2-size_num));
	size_num = (x+1)*2;
      }

      if (num[x] == 0){
	mem_list[list_used++] = x;
      }

      num[x]+=1;
    }

    _Bool solved = false;
    for (int i=0;i<list_used;i++)
      if (num[mem_list[i]] >= (N+1)/2){
	printf("%d\n", mem_list[i]);
	solved = true;
	break;
      }

    if (!solved) putchar('\n');
  }
  return 0;
}
