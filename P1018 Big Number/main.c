#include <stdio.h>
#include <math.h>

int main (){
  int n;
  scanf ("%d",&n);

  for (int i=0;i<n;i++){
    int a;
    scanf ("%d",&a);
    double ans=0;
    for (int k=2;k<=a;k++) ans+=log10(k);
    printf ("%d\n",(int)ceil(ans));
  }
  return 0;
}
