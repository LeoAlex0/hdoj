#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* OutputFormat="Case %d:\nMy king, at most %d %s can be built.\n\n";

#define max(a,b) ((a)>(b)?(a):(b))

int *dp=NULL;
int *dat=NULL;

int main(){
  int n,kase=1;
  int max_n=0;
  while (scanf("%d",&n) != EOF){
    if (n>max_n){
      dat=realloc(dat,sizeof(int)*(n+1));
      dp=realloc(dp,sizeof(int)*(n+1));
      max_n=n;
    }
    //输入
    for (int i=1;i<=n;i++){
      int s,d;
      scanf("%d%d",&s,&d);
      dat[s]=d;
    }
    
    int ans=0;

    for (int i=1;i<=n;i++){
      int a=0,b=ans;
      while (a < b){
	const int m=(b-a)/2+a;
	if (dp[m] <= dat[i]) a=m+1;
	else b=m;
      }
      //对每个新加入的元素都直接赋值，故不需要memset
      dp[a]=dat[i];
      if (a==ans) ans++;
    }
    
    printf (OutputFormat,kase++,ans,ans>1?"roads":"road");
  }
}
