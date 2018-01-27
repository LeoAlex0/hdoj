#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* OutputFormat="Case %d:\nMy king, at most %d %s can be built.\n\n";

#define max(a,b) ((a)>(b)?(a):(b))

#define lowbit(x) ((x)&(-x))
int *max_length_tree=NULL;
int dp;
int *dat=NULL;

int main(){
  int n,kase=1;
  int max_n=0;
  while (scanf("%d",&n) != EOF){
    if (n>max_n){
      max_length_tree=realloc(max_length_tree,sizeof(int)*(n+1));
      dat=realloc(dat,sizeof(int)*(n+1));
      max_n=n;
    }
    for (int i=1;i<=n;i++) max_length_tree[i]=0;

    //输入
    for (int i=1;i<=n;i++){
      int s,d;
      scanf("%d%d",&s,&d);
      dat[s]=d;
    }
    
    int ans=0;

    for (int i=1;i<=n;i++){
      //query
      int m=0;
      for (int idx=dat[i];idx>0;idx-=lowbit(idx))
	m=max(m,max_length_tree[idx]);

      dp=m+1;
      
      //save
      for (int idx=dat[i];idx<=n;idx+=lowbit(idx))
	max_length_tree[idx]=max(max_length_tree[idx],dp);

      ans=max(ans,dp);
    }
    printf (OutputFormat,kase++,ans,ans>1?"roads":"road");
  }
}
