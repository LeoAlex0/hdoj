#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>
#include <cmath>
#include <utility>

typedef std::pair<double,double> single_dat_type;
typedef std::set<single_dat_type> dat_type;

using namespace std;

// ostream & operator<< (ostream & out,const single_dat_type &a){
// 	out<<'('<<a.first<<','<<a.second<<')';
// 	return out;
// }

dat_type interaction(const dat_type &a,const dat_type &b){
	dat_type ret;
	for (auto i=a.begin(),j=b.begin();i!=a.end() && j!=b.end();){
		if (i->first < j->first){
			if (i->second > j->second){
				ret.insert (*j);
				j++;
			}
			else if (i->second > j->first){
				ret.insert (single_dat_type(j->first,i->second));
				i++;
			}
			else i++;
		}
		else{
			if (j->second > i->second){
				ret.insert (*i);
				i++;
			}
			else if (j->second > i->first){
				ret.insert (single_dat_type(i->first,j->second));
				j++;
			}
			else j++;
		}
	}
	return ret;
}

int main(){
	const double hdps=1.0/120,mdps=1./10,sdps=6.;
	const double T_hm=360./(mdps-hdps),T_hs=360./(sdps-hdps),T_ms=360./(sdps-mdps);

	cout<<setiosflags(ios::fixed)<<setprecision(3);

	double D;
	while (cin>>D && D!=-1){
		dat_type hm_time,hs_time,ms_time;
		for (int i=0;i<43200./T_hm;i++)
			hm_time.insert(single_dat_type(D/(mdps-hdps)+T_hm*i,(360.-D)/(mdps-hdps)+T_hm*i));
		for (int i=0;i<43200./T_hs;i++)
			hs_time.insert(single_dat_type(D/(sdps-hdps)+T_hs*i,(360.-D)/(sdps-hdps)+T_hs*i));
		for (int i=0;i<43200./T_ms;i++)
			ms_time.insert(single_dat_type(D/(sdps-mdps)+T_ms*i,(360.-D)/(sdps-mdps)+T_ms*i));

		double sum_time=0;
		for (auto i:interaction (ms_time,interaction(hm_time,hs_time))) sum_time+=i.second-i.first;
		cout<<sum_time/43200 * 100<<endl;
	}
	return 0;
}
