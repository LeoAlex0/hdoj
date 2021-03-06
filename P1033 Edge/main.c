#include <stdio.h>

int main (){
  const int dx[]={10,0,-10,0};
  const int dy[]={0,10,0,-10};
  const char* prefix = "300 420 moveto";
  const char* suffix = "stroke\nshowpage";
  const char* item_suffix = "lineto";

  char buf[200];
  while (fgets(buf, 200, stdin) != NULL){
    int x=310,y=420,dir=0;

    puts(prefix);
    for (int i=0;buf[i];i++){
      printf ("%d %d %s\n",x,y,item_suffix);
      switch (buf[i]){
      case 'V':
	dir = (dir+1)%4;
	break;
      case 'A':
	dir = (dir+3)%4;
	break;
      }
      x+=dx[dir];
      y+=dy[dir];
    }
    puts(suffix);
  }
  return 0;
}
