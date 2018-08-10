#include <stdio.h>

int main (){
  int n;
  while (scanf("%d",&n) != EOF){
    printf ("%s\n",(n+2)%4==0?"yes":"no");
  }
  return 0;
}
