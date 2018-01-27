#include <stdio.h>

int main (){
  for (int i=1;i*i<1E9;i++)
    printf ("%d,",i*i);
  return 0;
}
