#include <iostream>
#include <algorithm>
#include <list>
#include <cstring>

const int MAX_N=(1000000+5);

//dp[b][a]表示包括dat[a]的b段之和的最大值
//dp[b][a]=max(dp[b][a-1]+dat[a],dp[b-1][k]+dat[a]) (k\in [b-1,a-1])
int dp[2][MAX_N];

int dat[MAX_N];
int sum[MAX_N];

using namespace std;

int main(){
  int m,n;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while (cin>>m>>n){
    sum[0]=0;
    for (int i=0;i<=n;i++) dp[0][i]=0;
    //输入
    for (int i=1;i<=n;i++){
      cin>>dat[i];
      sum[i]=sum[i-1]+dat[i];
    }

    //dp开始,先对b循环（维护最大值k）
    for (int b=1;b<=m;b++){
      int k=b-1;
      //边界情况，以b个数分成b段只能全部加起
      dp[b%2][b]=sum[b];
      for (int a=b+1;a<=n;a++){
	//维护k使得dp[k][b-1]使其满足最大
	if (dp[(b+1)%2][k] < dp[(b+1)%2][a-1]) k=a-1;
 
	dp[b%2][a]=max(dp[b%2][a-1],dp[(b+1)%2][k])+dat[a];
      }
    }
    
    int ans=*max_element(dp[m%2]+m,dp[m%2]+n+1);
    cout<<ans<<endl;
  }
  return 0;
}
