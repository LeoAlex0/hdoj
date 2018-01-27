#include <iostream>
#include <map>
#include <string>
#include <typeinfo>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    while (cin>>n && n!=0){
        map<string,int> dat;
        for (int i=0;i<n;i++){
            string buf;
            cin>>buf;
            if (!dat.count(buf)) dat[buf]=1;
            else dat[buf]++;
        }

        int max_cnt=-1;
        string ans;
        for (auto i:dat){
            if (i.second>max_cnt){
                ans=i.first;
                max_cnt=i.second;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
