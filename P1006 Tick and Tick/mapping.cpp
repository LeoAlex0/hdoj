#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <thread>
#include <atomic>

using namespace std;

const long long epsilon=50;
long double p_ans[121];
atomic_uint finished(0);

void calc (int D){
    unsigned long long ans=0;
    for (int h=0;h<12;h++){
        for (int m=0;m<60;m++){
            for (long long s=0;s<360*epsilon;s++){
                const long double deg_s=(long double)s/epsilon;
                const long double deg_m=m*6+deg_s/60;
                const long double deg_h=h*30+deg_m/12;
                vector<double> tmp;
                tmp.push_back(min(abs(deg_s-deg_m),360-abs(deg_s-deg_m)));
                tmp.push_back(min(abs(deg_s-deg_h),360-abs(deg_s-deg_h)));
                tmp.push_back(min(abs(deg_h-deg_m),360-abs(deg_h-deg_m)));
                if (*min_element(tmp.begin(),tmp.end()) >= D) ans++;
            }
        }
    }
    p_ans[D]=(long double)ans/(epsilon*12*60*360)*100;
    finished++;
}

int main() {
    ios::sync_with_stdio(false);

    for (int D=0;D<=120;D++){
        thread t(calc,D);
        t.detach();
    }

    while (finished != 121);

    for (auto i:p_ans) cout<<i<<',';

    return 0;
}
