#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

typedef pair<double,double> dat_type;
vector<dat_type> dat;

double dist(const dat_type& a1,const dat_type& a2){
	return sqrt((a1.first-a2.first)*(a1.first-a2.first)+(a1.second-a2.second)*(a1.second-a2.second));
}

double min_dist;

int min_div(int beg,int end){
	if (end-beg <= 1) return 0;

	const int m=(end-beg)/2+beg;

	for (int i=1;m - i >= beg;i++){
		if (dat[m].first - dat[m-i].first > min_dist) break;
		const double d=dist(dat[m],dat[m-i]);
		//if (d > min_dist) break;
		min_dist=min(min_dist,d);
	}
	for (int i=1;m + i < end;i++){
		if (dat[m+i].first - dat[m].first > min_dist) break;
		const double d=dist(dat[m],dat[m+i]);
		//if (d > min_dist) break;
		min_dist=min(min_dist,d);
	}

	min_div(beg,m);
	min_div(m+1,end);

	return 0;
}

int main() {
	int N;
	ios::sync_with_stdio(false);
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	while (cin>>N && N!=0){
		dat.clear();
		for (int i=0;i<N;i++){
			double x,y;
			cin>>x>>y;
			dat.push_back(dat_type(x,y));
		}
		sort(dat.begin(),dat.end());

		min_dist=dist(dat[0],dat[1]);

		min_div(0,N);

		cout<<min_dist/2<<endl;
	}
	return 0;
}
