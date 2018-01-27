#include <iostream>
#include <vector>
using namespace std;

int main (){
    vector<int> dat;
    int a,b,n;
    ios::sync_with_stdio(false);
    while ((cin>>a>>b>>n) && n!=0){
        dat.resize(2);
        dat[0]=dat[1]=1;
        int T=-1;
        for (int i=2;i<n;i++){
            dat.push_back ((a*dat[i-1]+b*dat[i-2])%7);
            if (i>4 && dat[i]==dat[3] && dat[i-1]==dat[2]){
                T=i-3;
                // for (int i:dat)cout<<i<<'\t';
                // cout<<endl;
                break;
            }
        }
        if (T!=-1) cout<<dat[(n-3)%T+2]<<endl;
        else cout<<dat[n-1]<<endl;
    }
    return 0;
}
