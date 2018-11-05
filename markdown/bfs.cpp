#include<bits/stdc++.h>
#define for(x,i,j) for(int x=i;x<j;x++)
#define C(a,x,b) ((a)<=(x)&&(x)<=(b))
#define MAXLEN 1000
using namespace std;
	int MAP[MAXLEN][MAXLEN]={0};
	int MOVE[MAXLEN][MAXLEN]={0};
const int up[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct point
{
	
		int x;
		int y;	
};
int m,n;
void debug_map(int debugx,int debugy)
{
	cout<<"INSERT "<<debugx<<" "<<debugy<<" :\n";
	for(i,0,m)
	{
	for(j,0,n)
		cout<<MOVE[i][j]<<" ";
	cout<<"\n";
	}
	system("pause");
}
void bfs(int sx,int sy,int ex,int ey)
{

	queue<point> que;
	point s;
	s.x=sx;
	s.y=sy;
	que.push(s);
	while(!que.empty())
	{
	if(que.front().x==ex&&que.front().y==ey)return;
	
		for(i,0,4)
		{
			if(C(0,que.front().x+up[i][0],m-1)&&C(0,que.front().y+up[i][1],n-1)&&(MAP[que.front().x+up[i][0]][que.front().y+up[i][1]]==0)&&MOVE[que.front().x+up[i][0]][que.front().y+up[i][1]]==0)
			{
				MOVE[que.front().x+up[i][0]][que.front().y+up[i][1]]=MOVE[que.front().x][que.front().y]+1;
				s.x=que.front().x+up[i][0];
				s.y=que.front().y+up[i][1];
				que.push(s);
//				debug_map(que.front().x+up[i][0],que.front().y+up[i][1]);
			}
		}
	que.pop();
	}
}
int main()
{
	
	int sx,sy,ex,ey;
	cin>>m>>n;
	sx=sy=ex=ey=0;
	memset(MAP,0,sizeof(MAP));
	memset(MOVE,0,sizeof(MOVE));
	for(i,0,m)
		for(j,0,n)
		{
			cin>>MAP[i][j];
		}
		cin>>sx>>sy>>ex>>ey;
	bfs(sx-1,sy-1,ex-1,ey-1);
	cout<<((MOVE[ex-1][ey-1]==0)?-1:MOVE[ex-1][ey-1])<<endl;

}
