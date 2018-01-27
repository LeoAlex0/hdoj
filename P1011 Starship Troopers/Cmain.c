#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define max_N (100+5)
#define max_M (100+5)

int gain[max_N],pain[max_N];

int map[max_N][max_N];
int map_size[max_N];

_Bool occupied[max_N];
int dat[max_N][max_M];
#define zero(a) memset(a,0,sizeof(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define maxilize(a,b) ((a)=max(a,b))

int N,M;

void dfs(int s){
	occupied[s]=true;
	int find_list[max_N]={0};
	int list_size=0;
	if (M<pain[s]) return;

	//all connected&dfs
	for (int i=0;i<map_size[s];i++){
		if (!occupied[map[s][i]]){
			dfs (map[s][i]);
			find_list[list_size++]=map[s][i];
		}
	}

	//针对每一个相邻节点的数据独立的更新dat[s],独立的(敲黑板)
	for (int i=0;i<list_size;i++){
		//针对每一个可能的权值进行计算，类似于背包
		for (int j=M;j>=max(1,pain[s]);j--){
			//注意：此处枚举所有可以给节点find_list[i]的权值数目
			for (int k=max(1,pain[find_list[i]]);k<=j-pain[s];k++){
				maxilize(dat[s][j],dat[find_list[i]][k]+dat[s][j-k]);
			}
		}
	}

	for (int i=max(1,pain[s]);i<=M;i++){
		//不要忘记加上节点本身的收益
		dat[s][i]+=gain[s];
	}
}

int main(){
	while (scanf("%d%d",&N,&M) != EOF && N!=-1 && M!=-1){
		zero(map);
		zero(occupied);
		zero(map_size);
		zero(dat);
		for (int i=1;i<=N;i++){
			int bugs;
			scanf("%d%d",&bugs,&gain[i]);
			pain[i]=ceil((double)bugs/20);
		}
		for (int i=0;i<N-1;i++){
			int s,d;
			scanf("%d%d",&s,&d);
			map[s][map_size[s]++]=d;
			map[d][map_size[d]++]=s;
		}

		dfs(1);
		printf("%d\n",dat[1][M]);
	}
	return 0;
}
