#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int n,m;
  while (cin>>n>>m){
    vector<int> dat;
    for (int x=1;x<=n;x++) dat.push_back(x);
    for (int i=1;i<m;i++)
      next_permutation(dat.begin(),dat.end());

    for (int i=0;i<n;i++){
      if (i) cout<<" ";
      cout<<dat[i];
    }
    cout<<endl;
  }
  return 0;
}
