#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
    int ans=0;
    double D;
    cin>>D;

    for (int h=0;h<12;h++){
        for (int m=0;m<60;m++){
            for (int s=0;s<60;s++){
                const double deg_s=s*6;
                const double deg_m=m*6+ double(s)/10;
                const double deg_h=h*30+ deg_m/12;
                vector<double> tmp;
                tmp.push_back(min(abs(deg_s-deg_m),360-abs(deg_s-deg_m)));
                tmp.push_back(min(abs(deg_s-deg_h),360-abs(deg_s-deg_h)));
                tmp.push_back(min(abs(deg_h-deg_m),360-abs(deg_h-deg_m)));
                if (*min_element(tmp.begin(),tmp.end()) >= D) ans++;
            }
        }
    }

    cout<<setiosflags(ios::fixed)<<setprecision(3)<<double(ans)/(12*60*60)*100<<endl;
    return 0;
}
