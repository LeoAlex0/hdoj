#include <stdio.h>
#include <math.h>

int main (){
  int n;
  double d;
  scanf ("%d%lf",&n,&d);

  int idx;
  while (scanf ("%d",&idx) == 1){
    int sum_seconds=0;
    for (int i=0;i<n;i++){
      int hour,minute,seconds;
      if (scanf(" %d:%d:%d",&hour,&minute,&seconds) == 3){
        if (sum_seconds == -1) continue;
        sum_seconds += (hour*60+minute)*60+seconds;
      }
      //清空缓冲区
      else {
        sum_seconds = -1;
        scanf ("%*s");
      }
    }

    if (sum_seconds != -1){
      sum_seconds = floor ((sum_seconds/d)+0.5);

      printf("%3d: %d:%02d min/km\n", idx,
        sum_seconds/60,
        sum_seconds%60);
    }
    else printf ("%3d: -\n", idx);
  }
  return 0;
}
