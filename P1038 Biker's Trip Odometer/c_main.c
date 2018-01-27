#include <stdio.h>

int main(){
  const double k1=3.1415927/12/5280;
  const double k2=k1*3600;

  double diameter,times;
  int revolution,kase=0;
  while (scanf("%lf%d%lf",&diameter,&revolution,&times) != EOF &&
	 revolution!=0){
    printf ("Trip #%d: %.2f %.2f\n",++kase,k1*revolution*diameter,k2*revolution*diameter/times);
  }
  return 0;
}
