#include <iostream>

using namespace std;

int main (){
    int n;
    cin>>n;
    for (int kase=1;kase<=n;kase++){
        int size;
        cin>>size;
        int dat;
        int val_max_to=-1,max_val_max_to=-1;
        int idx_max_from,max_idx_max_from;
        int max_idx_max_to;
        for (int i=0;i<size;i++){
            cin>>dat;
            if (val_max_to >= 0LL){
                val_max_to+=dat;
            }
            else{
                val_max_to=dat;
                idx_max_from=i;
            }

            if (max_val_max_to < val_max_to || i==0){
                max_val_max_to=val_max_to;
                max_idx_max_from=idx_max_from;
                max_idx_max_to=i;
            }
        }
        cout<<"Case "<<kase<<":"<<endl;
        cout<<max_val_max_to<<' '<<max_idx_max_from+1<<' '<<max_idx_max_to+1<<endl;
        if (kase!=n) cout<<endl;
    }
    return 0;
}
