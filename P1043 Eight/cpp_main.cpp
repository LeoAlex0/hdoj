#include <cstdio>
#include <unordered_map>
#include <string>
#include <list>
#include <utility>
#include <algorithm>

using namespace std;

unordered_map<string,string> bfs(){
  const auto check_and_move = [](string &raw,int i)->bool{
    const static int dx[]={-1,1,0,0};
    const static int dy[]={0,0,-1,1};
    int z_pos=-1;while (raw[++z_pos]!='x');
    const int nx=z_pos/3+dx[i],ny=z_pos%3+dy[i];
    if (nx<0 || nx>=3 || ny<0 || ny>=3) return false;
    else swap(raw[z_pos],raw[nx*3+ny]);return true;
  };
  const char dir[]="durl",*begin="12345678x";
  unordered_map<string,string> ans = {make_pair(begin,"")};
  list<string> que = {begin};
  while (!que.empty()){
    string thiz=que.front();que.pop_front();
    for (int i=0;i<4;i++){
      string tmp=thiz;
      if (check_and_move(tmp,i) && !ans.count(tmp)){
	ans.insert(make_pair(tmp,dir[i]+ans[thiz]));
	que.push_back(tmp);
      }
    }
  }
  return ans;
}

int main(){
  auto ans = bfs();
  char buf[10]={0};
  while (~scanf(" %c %c %c %c %c %c %c %c %c",
		&buf[0],&buf[1],&buf[2],
		&buf[3],&buf[4],&buf[5],
		&buf[6],&buf[7],&buf[8])){
    const string tmp(buf);
    if (ans.count(tmp)) puts(ans[tmp].c_str());
    else puts("unsolvable");
  }
  return 0;
}
