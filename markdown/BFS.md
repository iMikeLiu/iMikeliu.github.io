# 关于BFS

BFS，广度优先搜索。

伪代码级别的CPP源码：

```cpp
void bfs(point sp)
{
	int top;
	queue<point> que;
	que.push(sp);
	while(!que.empty())
	{
		top=que.front();
		que.pop();
		if(top==终点)结束搜索并处理();
		for i in 所有与top联通的下一个点
		{
			que.push(i);
			更新i的对应值();
		}
	}
}
```

迷宫问题

```cpp

#include<bits/stdc++.h>
using namespace std;
struct point
{
public:
    int x;
    int y;	
};
const int gp[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int mark[6][6]={0};
int MAP[6][6]={0};
int sx,sy,fx,fy;
int n,m,t;
inline bool pd(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<n&&MAP[x-1][y-1]==0&&mark[x-1][y-1]==0)
    return 1;
    else return 0;
}
int sum=0;
inline void bfs(point p)
{
    point start;
    start.x=sx;
    start.y=sy;
    mark[sx][sy]=1;
    queue<point> que;
    que.push(start);
    while(!que.empty())
    {
    	for(int j=0;j<n;j++)
    	{
    		for(int k=0;k<m;k++)
    		{
    			cout<<MAP[j][k]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
    	for(int j=0;j<n;j++)
    	{
    		for(int k=0;k<m;k++)
    		{
    			cout<<mark[j][k]<<" ";
			}
			cout<<"\n";
		}
		system("pause");
        point top=que.front();
        que.pop();
        if(top.x==fx-1&&top.y==fy-1)sum++;
        for(int i=0;i<4;i++)
        {
        	cout<<"test:"<<top.x+gp[i][0]-1<<" "<<top.y+gp[i][1]-1<<"\n";
            if(pd(top.x+gp[i][0],top.y+gp[i][1]))
            {
            	cout<<"correct:"<<top.x+gp[i][0]-1<<" "<<top.y+gp[i][1]-1<<"\n";
                start.x=top.x+gp[i][0];
                start.y=top.y+gp[i][1];
                que.push(start);
                mark[start.x-1][start.y-1]=mark[top.x-1][top.y-1]+1;
            }
        }
    }	
}
int main()
{
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    for(int i=0;i<t;i++)
    {
        int x,y;
        cin>>x>>y;
        MAP[x-1][y-1]=-1;
    }
    //cout<<pd(3,2)<<endl;
    point s={sx-1,sy-1};
    bfs(s);	
    cout<<sum;
}


```