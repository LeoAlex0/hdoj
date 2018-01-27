#include <iostream>
#include <list>

using namespace std;

int main(){
  list<bool> dat[]={{true},{}};
  for (int i=0;i<1000;i++){
    list<bool> & next = dat[(i+1)&1],&thiz = dat[i&1];
    next.clear();
    int ans=0;
    bool prev=true;
    for (auto x:thiz){
      if (x){
	prev=true;
	next.push_back(false);
	next.push_back(true);
      } else {
	if (!prev) ans++;
	else prev = false;
	next.push_back(true);
	next.push_back(false);
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
