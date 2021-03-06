#include <stdio.h>
#include <string.h>

#define MAX_N (5+1000000)

int datValue[MAX_N];

int solve (unsigned long long x){
  if (x > 1E19) printf ("%llu\n",x);
  if (x < MAX_N && datValue[x] != -1) return datValue[x];
  if ((x&1) == 0) {
    if (x<MAX_N) return datValue[x] = solve(x/2)+1;
    else return solve(x/2)+1;
  }
  else{
    if (x<MAX_N) return datValue[x] = solve(3*x+1)+1;
    else return solve(3*x+1)+1;
  }
}

int main (){
  int A,B;
  memset (datValue,-1,sizeof(datValue));
  datValue[1]=1;

  while (scanf ("%d%d",&A,&B) == 2){
    printf ("%d %d ",A,B);
    if (A>B) A^=B^=A^=B;
    unsigned long long max = 1;
    for (int x=A;x<=B;x++){
      const unsigned long long tmp = solve(x);
      max = tmp>max?tmp:max;
    }
    printf ("%llu\n",max);
  }
  return 0;
}
