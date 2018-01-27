#include <iostream>
#include <set>
#include <map>

using namespace std;

int main (){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  multiset<int> dat;
  
  while (cin>>N){
    dat.clear();

    for (int i=0;i<N;i++){
      int t;
      cin>>t;
      dat.insert(t);
    }

    for (int x:dat){
      if (dat.count(x) >= (N+1)/2){
	cout<<x<<endl;
	break;
      }
    }
    
  }
  return 0;
}
