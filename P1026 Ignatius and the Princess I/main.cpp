#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <functional>

using namespace std;

typedef pair<int, int> point;
const size_t max_N = 100+5;
int ground[max_N][max_N];
point past[max_N][max_N];
bool reached[max_N][max_N];

int main (){
  cout.tie(0);
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m;
  while (cin>>n>>m){
    
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++)
	reached[i][j] = false;
    
    //输入数据
    for (int i=0;i<n;i++){
      for (int j=0;j<m;j++){
	char c;
	cin>>c;
	//移动需要一秒时间
	if (isdigit(c)) ground[i][j] = c - '0' + 1;
	else if (c == 'X') ground[i][j] = 0;
	else ground[i][j] = 1;
      }
    }

    bool solved=false;
    typedef pair<int, point> item_type;
    priority_queue<item_type,deque<item_type>,greater<item_type>> que;
    //出生点有怪
    reached[0][0]=true;
    que.push(make_pair(ground[0][0],make_pair(0, 0)));
    while (!que.empty()){
      const int dx[] = {0,1,0,-1};
      const int dy[] = {1,0,-1,0};
      
      auto t = que.top();
      que.pop();
      const int& tick=t.first;
      const int& x=t.second.first;
      const int& y=t.second.second;

      //输出结果
      if (x == n-1 && y == m-1){
	stack<point> way;
	const point src = make_pair(0, 0); 

	for (point x = t.second;x != src;x = past[x.first][x.second])
	  way.push(x);
	way.push(src);

	cout<<"It takes "
	    <<tick-1
	    <<" seconds to reach the target position, let me show you the way."
	    <<endl;

	for (int t=1,last_t=0;t < tick;t++){
	  const point& pos = way.top();
	  const int& x = pos.first;
	  const int& y = pos.second;
	  cout<<t<<"s:";
	  if (t - last_t < ground[x][y]){
	    cout<<"FIGHT AT ("<<x<<','<<y<<')'<<endl;
	  }
	  else{
	    way.pop();
	    last_t = t;

	    const point& pos_n = way.top();
	    const int& x_n = pos_n.first;
	    const int& y_n = pos_n.second;
	    cout<<'('<<x<<','<<y<<")->("<<x_n<<','<<y_n<<')'<<endl;
	  }
	}

	solved = true;
	break;
      }

      //移动
      for (int i=0;i<4;i++){
	const int x_n = x + dx[i];
	const int y_n = y + dy[i];
	
	if (x_n < n && x_n >= 0 &&
	    y_n < m && y_n >= 0 &&
	    ground[x_n][y_n] &&
	    !reached[x_n][y_n]){
	  const int& cost = ground[x_n][y_n];
	  que.push(make_pair(tick + cost, make_pair(x_n, y_n)));

	  past[x_n][y_n] = make_pair(x, y);
	  reached[x_n][y_n] = true;
	}
      }
    }

    if (!solved)
      cout<<"God please help our poor hero."<<endl;

    cout<<"FINISH"<<endl;
  }
  return 0;
}
