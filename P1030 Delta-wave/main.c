#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int sqr[31624];

#define min(a,b) ((a)>(b)?(b):(a))

int main (){
  int S,T;
  for (int i=0;(sqr[i] = i*i)<1E9;i++);
  
  while (scanf ("%d%d",&S,&T) != EOF){
    int co_S,co_T;
    if (T<S) S^=T^=S^=T;

    int a=0,b=min(S,31623);
    while (a < b){
      co_S = (b-a)/2+a;
      if (sqr[co_S] < S) a=co_S+1;
      else b=co_S;
    }
    co_S = a;
    a=0;b=min(T,31623);
    while (a<b){
      co_T = (b-a)/2+a;
      if (sqr[co_T] < T) a=co_T+1;
      else b = co_T;
    }
    co_T = b;

    const int l_S = S-sqr[co_S-1],l_T = T-sqr[co_T-1];
    const bool is_S_up = ((S&1) == (sqr[co_S]&1)),
      is_T_up = ((T&1) == (sqr[co_T]&1));

    int ans = (co_T - co_S)*2;

    if (l_T < l_S) ans+=l_S - l_T;
    else if (l_T > l_S + (co_T-co_S)*2) ans+=l_T - (l_S + (co_T - co_S)*2);
    else{
      if (is_S_up) ans-=1;
      if (is_T_up) ans+=1;
    }

    printf ("%d\n",ans);
  }
  return 0;
}
