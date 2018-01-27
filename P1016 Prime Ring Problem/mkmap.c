#include <stdio.h>
#include <stdbool.h>

#define target 19
#define pri_target 40
const int pri_list[]={2,3,5,7,11,13,17,19,23,29,31,37};
int dat[target];

_Bool is_pri(int a){
  static _Bool prim[pri_target+1]={false};
  static int n=0,next_i=0;
  if (a<n) return prim[a];

  while (n <= a){
    if (n>pri_list[next_i]) next_i++;
    prim[n] = n==pri_list[next_i];
    n++;
  }
  return prim[a];
}

void dfs(const int dep,_Bool can[],const int dest){
  if (dep==dest && is_pri(dat[dep-1]+dat[0])){
    for (int i=0;i<dest;i++) printf ("%d ",dat[i]);
    putchar('\n');
    return;
  }

  for (int i=1;i<=dest;i++) if (can[i] && is_pri(dat[dep-1]+i)){
      can[i]=false;
      dat[dep]=i;
      dfs(dep+1,can,dest);
      can[i]=true;
    }
  return;
}

int main(){
  for (int i=1;i<=target;i++){
    _Bool can[i+1];
    can[1]=false;
    for (int j=2;j<=i;j++) can[j]=true;

    dat[0]=1;
    dfs(1,can,i);
    printf ("\n");
  }
}
