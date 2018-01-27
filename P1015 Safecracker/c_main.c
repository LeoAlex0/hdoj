#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char dat[20];
int K;
_Bool can[20];
char ans[20];
int pow_tmp[26][5];

_Bool dfs(int dep,int tmp,const int n);

int cmp (const void* a1,const void* a2){
  return *(char*)a2-*(char*)a1;
}

#define zero(a) memset(a,0,sizeof(a))

int main(){
  //init
  zero(ans);
  for (int i=0;i<26;i++){
    pow_tmp[i][0]=i+1;
    for (int j=1;j<5;j++)
      pow_tmp[i][j]=-(i+1)*pow_tmp[i][j-1];
  }
  
  while (scanf("%d%s",&K,dat) != EOF && !(K==0 && !strcmp(dat,"END"))){
    const int n=strlen(dat);
    
    //对dat[i]排序以达到按字典序枚举的目的
    qsort(dat,n,sizeof(char),cmp);
    for (int i=0;i<n;i++) can[i]=true;

    //for (int i=0;i<26;i++){
    //  for (int j=0;j<5;j++){
    //    printf ("%d\t",pow_tmp[i][j]);
    //  }
    //  printf ("\n");
    //}

    printf ("%s\n",dfs(0,0,n)?ans:"no solution");
  }
  return 0;
}

_Bool dfs (int dep,int tmp,const int n){
  //0--4
  if (dep==5) return tmp==K;

  //对于每个可以加入队列的值枚举
  for (int i=0;i<n;i++){
    if (can[i]){
      can[i]=false;
      //进行下一层dfs
      if (dfs(dep+1,tmp+pow_tmp[dat[i]-'A'][dep],n)){
	//满足要求则记录答案并返回
	ans[dep]=dat[i];
	return true;
      }
      //释放对于dat[i]的占用
      can[i]=true;
    }
  }
  return false;
}
