#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<bool> > map_t;
typedef pair<int,int> point;

void input(int,int,map_t&);
bool dfs_start (int T,map_t& init);
int bfs (map_t cur);

point S,D;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int M,N,T;
	while (cin>>M>>N>>T && M!=0 && N!=0 && T!=0){
		map_t board;

		board.resize(M);
		for (auto &i:board) i.resize(N);

		input(M,N,board);

		int min_d=bfs(board);
		if ((T&1) != (min_d&1) || T==-1){
			cout<<"NO"<<endl;
			continue;
		}

		cout<<(dfs_start(T,board)?"YES":"NO")<<endl;

	}
}

inline bool can_occupy(int x,int y,map_t& cur){
	return (x<cur.size() && x>=0
	&& y<cur[x].size() && y>=0
	&& cur[x][y]);
}

int bfs (map_t cur){
	const int dx[]={-1,0,1,0};
	const int dy[]={0,1,0,-1};

	typedef pair<point,int> que_type;

	queue<que_type> que;
	que.push(que_type(S,0));

	while (!que.empty()){
		que_type t=que.back();
		que.pop();

		if (t.first==D) return t.second;

		for (int i=0;i<4;i++){
			if (can_occupy(t.first.first+dx[i],t.first.second+dy[i],cur)){
				cur[t.first.first][t.first.second]=false;
				que.push(que_type(point(t.first.first+dx[i],t.first.second+dy[i]),t.second+1));
			}
		}
	}
	return -1;
}

bool dfs (int x,int y,int T,map_t& cur){
	const int dx[]={-1,0,1,0};
	const int dy[]={0,1,0,-1};
	bool ret=false;

	if (x==D.first && y==D.second && T==0) return true;
	else if (T==0) return false;

	cur[x][y]=false;

	for (int i=0;i<4 && !ret;i++){
		if (can_occupy(x+dx[i],y+dy[i],cur)){
			ret |= dfs(x+dx[i],y+dy[i],T-1,cur);
		}
	}

	cur[x][y]=true;

	return ret;
}

bool dfs_start (int T,map_t& init){
	return dfs(S.first,S.second,T,init);
}

void input(int M,int N,map_t& board){
	for (int i=0;i<M;i++){
		for (int j=0;j<N;j++){
			char t;
			cin>>t;
			switch (t){
				case 'S':
				S=point(i,j);
				board[i][j]=true;
				break;
				case 'D':
				D=point(i,j);
				board[i][j]=true;
				break;
				case 'X':
				board[i][j]=false;
				break;
				case '.':
				board[i][j]=true;
				break;
			}
		}
	}
}
