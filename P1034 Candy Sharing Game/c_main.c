#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check (int *dat,int N){
  const int cmp=dat[0];
  for (int i=0;i<N;i++) if (dat[i] != cmp) return false;
  return true;
}

void change(int *dat,int N){
  int tmp_in = dat[0] - dat[0]/2;
  int tmp_out = 0;

  for (int i=N-1;i>=0;i--){
    tmp_out = dat[i] - dat[i]/2;
    dat[i] = dat[i]/2;
    dat[i] += tmp_in;
    if (dat[i]%2 != 0) dat[i]+=1;
    tmp_in = tmp_out;
  }
}

int main (){
  int N,size=0;
  int *dat=NULL;
  while (scanf("%d",&N) == 1 && N != 0){
    if (size < N) dat = (int*)realloc(dat, (size = N)*sizeof(int));
    for (int i=0;i<N;i++) scanf ("%d",dat+i);

    int ans=0;
    for (;!check(dat, N);change(dat, N),ans++){
      //for (int i=0;i<N;i++) printf ("%d\t",dat[i]);
      //puts("");
    }
    
    printf ("%d %d\n",ans,dat[0]);
  }
  
  free(dat);
  return 0;
}
