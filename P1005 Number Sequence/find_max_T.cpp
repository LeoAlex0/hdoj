#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    int max_T=0;
    for (int a=1;a<=1000;a++){
        for (int b=1;b<=1000;b++){
            std::vector<int> dat;
            dat.push_back(1);dat.push_back(1);
            int i=2;
            do{
                dat.push_back((a*dat[i-1]+b*dat[i-2])%7);
                ++i;
            }while (i<=4 || (dat[i-1]!=dat[3] || dat[i-2]!=dat[2]));
            // cout<<i-2<<'\t';
            max_T=max(max_T,i-4);
        }
    }
    cout<<max_T<<endl;
    return 0;
}
