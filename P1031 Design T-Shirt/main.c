#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *idx=NULL;
double *dat=NULL;

int idx_cmp(const void* a,const void* b){
  return dat[*(int*)b] - dat[*(int*)a];
}
int idx_rev(const void* a,const void* b){
  return *(int*)b - *(int*)a;
}

int main (){
  int N,M,K;
  int max_m=0;

  while (scanf("%d%d%d", &N,&M,&K) != EOF){
    if (max_m < M){
      dat = (double*) realloc(dat, sizeof(double)*M);
      idx = (int*) realloc(idx, sizeof(int)*M);
      max_m = M;
    }
    memset(dat, 0, sizeof(double)*M);
    
    for (int i=0;i<N;i++){
      for (int j=0;j<M;j++){
	double t;
	scanf("%lf", &t);
	dat[j]+=t;
      }
    }
    for (int i=0;i<M;i++) idx[i]=i;

    qsort(idx, M, sizeof(int), idx_cmp);
    qsort(idx, K, sizeof(int), idx_rev);

    for(int i=0;i<K;i++){
      if (i != 0) printf (" ");
      printf("%d", idx[i]+1);
    }
    printf("\n");
  }
  return 0;
}
