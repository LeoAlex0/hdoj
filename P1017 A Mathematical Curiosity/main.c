#include <stdio.h>

int main (){
  int N;
  scanf ("%d",&N);
  for (int t=0;t<N;t++){
    if (t!=0) putchar('\n');
    int n,m,kase=1;
    while (scanf("%d%d",&n,&m) != EOF && (n!=0 || m!=0)){
      int ans=0;
      for (int a=1;a<n;a++){
	for (int b=a+1;b<n;b++){
	  if (((b-a)*(b-a)+m)%(a*b) == 0)
	    ans+=1;
	}
      }
      printf("Case %d: %d\n",kase++,ans);
    }
  }
  return 0;
}
