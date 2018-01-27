#include <stdio.h>
#include <stdbool.h>

#define half_ceil(x) ((x)+1)/2

bool change(int *dat,int N){
  int tmp_in = half_ceil(dat[0]);
  int tmp_out = 0;
  int avr;
  bool ret = true;

  for (int i=N-1;i>=0;i--){
    tmp_out = dat[i] = half_ceil(dat[i]);
    dat[i]+=tmp_in;
    tmp_in = tmp_out;

    if (i== N-1) avr = dat[i];
    ret = ret && (avr == dat[i]);
  }
  return ret;
}

int main (){
  int n;
  int dat[20];

  while (scanf ("%d",&n) == 1 && n != 0){
    for (int i=0;i<n;i++) scanf ("%d",dat+i);
    while (!change(dat, n)){
      for (int i=0;i<n;i++) printf ("%d\t",dat[i]);
      printf ("\n");
    }

    printf ("\n");
  }
  
  return 0;
}
