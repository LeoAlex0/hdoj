#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
  const char* dirs = "NEWS";
  const int dx[] = {-1,0,0,1};
  const int dy[] = {0,1,-1,0};

  int X,Y,I;
  int *dat=NULL,*dist=NULL,dist_size=0;
#define idx_of(x,y) ((x)*Y+(y))
#define dir_of(c) (strchr(dirs,(c))-dirs)

  while (scanf("%d%d%d",&X,&Y,&I) == 3 && X!=0 && Y!=0){
    if (idx_of(X, Y) > dist_size){
      dat = (int*)realloc(dat, (dist_size = idx_of(X, Y))*sizeof(int));
      dist = (int*)realloc(dist, sizeof(int)*dist_size);
    }
    memset(dist, -1, sizeof(int)*dist_size);

    for (int i=0;i<X;i++){
      for (int j=0;j<Y;j++){
        char c;
        scanf(" %c", &c);
        dat[idx_of(i, j)] = dir_of(c);
      }
    }

    int x=0,y=I-1,d=0;
    while (x>=0 && x<X && y>=0 && y<Y){
      if (dist[idx_of(x, y)] != -1){
        printf ("%d step(s) before a loop of %d step(s)\n",
        dist[idx_of(x, y)],
        d-dist[idx_of(x, y)]);
        d = -1;
        break;
      }
      dist[idx_of(x, y)] = d++;
      //printf ("%d\t%d\n",x,y);
      const int tx=dx[dat[idx_of(x, y)]];
      const int ty=dy[dat[idx_of(x, y)]];
      x+=tx;y+=ty;
    }
    if (d!=-1) printf("%d step(s) to exit\n", d);
  }
  free(dist);
  free(dat);
  return 0;
}
