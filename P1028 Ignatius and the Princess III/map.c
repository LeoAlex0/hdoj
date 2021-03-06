#include <stdio.h>

const int MAX_TO = 120;

int div(int n,int upper){
  if (n==0) return 1;
  if (upper == 1) return 1;
  int ans=0;
  for (int x=1;x<=upper && x<=n;x++)
    ans+=div(n-x,x);
  return ans;
}

int main(){
  for (int i=1;i<=MAX_TO;i++)
    printf ("%d,",div(i,i));
  return 0;
}
