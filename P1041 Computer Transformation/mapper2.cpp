#include <iostream>

using namespace std;

int main(){
  long long dat[1000]={0,1};
  for (int i=2;i<1000;i++) cout<<(dat[i]=dat[i-1]+2*dat[i-2])<<endl;
  return 0;
}
