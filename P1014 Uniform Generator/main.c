#include <stdio.h>

const char* spaces="    ";

int main(){
  int a,b;
  while (scanf("%d%d",&a,&b) != EOF){
    int t=0,step=0;
    do{
      t=(t%b+a%b)%b;
      step++;
    }while (t!=0);

    printf ("%10d%10d%s%s%7s\n\n",a,b,spaces,b==step?"Good":"Bad","Choice");
  }
  return 0;
}
