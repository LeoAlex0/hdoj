#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);

	cout<<"n e"<<endl;
	cout<<"- -----------"<<endl;

	double ans=0;
	for (int i=0;i<=9;i++){
		int frac=1;
		for (int j=1;j<=i;j++) frac*=j;
		if (i>2) cout<<fixed<<setprecision(9);
		ans+=1./frac;
		cout<<i<<' '<<ans<<endl;
	}
	return 0;
}
