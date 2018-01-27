#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <utility>
#include <functional>

using namespace std;

int main(int argc, char const *argv[]) {
	int W,N;
	double ans=0;
	ios::sync_with_stdio(false);
	cout<<setiosflags(ios::fixed)<<setprecision(3);
	while (cin>>W>>N && W!=-1 && N!=-1){
		ans=0;
		vector<pair<double,int> > dat;
		for (int i=0;i<N;i++){
			int w,p;
			cin>>p>>w;
			if (p==0) continue;
			else if (w==0) ans+=p;
			else dat.push_back(pair<double,int>(double(p)/w,w));
		}
		sort(dat.begin(),dat.end(),greater<pair<double,int> >());

		for (auto i:dat){
			if (W>=i.second){
				ans+=i.first*i.second;
				W-=i.second;
			}
			else{
				ans+=i.first*W;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
