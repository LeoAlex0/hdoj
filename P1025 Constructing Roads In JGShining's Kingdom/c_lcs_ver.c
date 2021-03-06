#include <stdio.h>

void output(int kase,int ans){
  //注意单复数
  const char* OutputFormat="Case %d:\nMy king, at most %d %s can be built.\n\n";
  printf(OutputFormat,kase,ans,ans>1?"roads":"road");
}

#define max(a,b) ((a)>(b)?(a):(b))
#define lowbit(x) ((x)&(-x))

#define MAX_N (500000+5)
int A[MAX_N],B[MAX_N];

int max_match_tree[MAX_N];

int main (){
  int n,kase=1;
  while (scanf("%d",&n) != EOF){
    //初始化
    for (int i=0;i<=n;i++) A[i]=B[i]=0;
    //每种资源一种编号，第一个没有被分配的编号
    int tmp_idx=1;
    //输入
    for (int i=1;i<=n;i++){
      int s,d;
      scanf("%d%d",&s,&d);
      //二者都没有分配物品编号
      if (A[s]==0 && B[d]==0) A[s]=B[d]=tmp_idx++;
      //其中一个分配物品编号
      else if (A[s]!=0 && B[d]==0) B[d]=A[s];
      else if (A[s]==0 && B[d]!=0) A[s]=B[d];
      //二者都分配了不同的物品编号
      else if (A[s]!=B[d]) return -1;
    }

    //dp方程:max_match(a,b)=max{ max(max_match(a-1,k)+1),max_match(a,b-1) }
    for (int b=1;b<=n;b++){
      int idx_max_match=0;
      for (int a=1;a<=n;a++){
	if (b>1) max_match[b%2][a]=max_match[(b+1)%2][a];
	else max_match[b%2][a]=0;
	if (A[a]==B[b])
	  max_match[b%2][a]=max(max_match[b%2][a],
				max_match[(b+1)%2][idx_max_match]+1);
	//维护idx_max_match(k)
	if (b>1 && max_match[(b+1)%2][a]>max_match[(b+1)%2][idx_max_match])
	  idx_max_match=a;
      }
    }

    int m=0;
    for (int i=1;i<=n;i++) m=max(m,max_match[n%2][i]);

    output(kase++,m);
  }

  return 0;
}
