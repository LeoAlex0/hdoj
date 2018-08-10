#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int N;
	ios::sync_with_stdio(false);
	while (cin>>N && N!=0){
		int cur=0,ans=0;
		for (int i=0;i<N;i++){
			int to;
			cin>>to;
			if (to>cur) ans+=(to-cur)*6;
			else ans+=(cur-to)*4;
			cur=to;
		}
		cout<<ans+N*5<<endl;
	}
	return 0;
}
