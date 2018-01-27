#include <stdio.h>
#include <stdbool.h>

const int target=40;

int dat[40];

int main(){
  int dat_n=0;
  for (int k=2;k<=target;k++){
    bool is_pri=true;
    for (int i=0;i<dat_n;i++) if (k%dat[i] == 0){
	is_pri=false;
	break;
      }
    if (is_pri) dat[dat_n++]=k;
  }
  for (int i=0;i<dat_n;i++) printf("%d,",dat[i]);
  return 0;
}
