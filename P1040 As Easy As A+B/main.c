#include <stdio.h>
#include <stdlib.h>

int cmp(const void *int1,const void *int2){
  return *(int*)int1 - *(int*)int2;
}

int main(){
  int T;
  int *pool=NULL,pool_size=0;
  scanf("%d",&T);
  while (T--){
    int N;
    scanf("%d",&N);
    if (N >= pool_size) pool = realloc(pool, sizeof(int)*(pool_size=N));
    for (int i=0;i<N;i++) scanf("%d",pool+i);
    qsort(pool, N, sizeof(int), cmp);
    for (int i=0;i<N;i++){
      if (i) printf(" ");
      printf("%d",pool[i]);
    }
    puts("");
  }
  return 0;
}
