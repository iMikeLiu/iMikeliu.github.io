---
published:false
---

<center>写DFS的一点感想</center>
想写好DFS，需要明白两个问题：


1. <strong> 每层有多少要搜索的节点？ </strong>
2. <strong> 搜到什么时候为止？ </strong>


由此，我们可以有一个模板：
（使用类pascal的伪代码编写）

```pascal

function 深度优先搜索(当前位置,当前深度 as integer) as integer
var
    i:integer;
begin
    if ((当前深度 = 目的深度) and (当前位置 = 目的位置) ) then
        处理终点();
    else
    begin
        for i in 所有当前位置的相邻位置 do
        begin
            深度优先搜索(i,当前深度+1);
            还原现场;
        end;
    end;
end;

```

<strong>现在我用C来实现一下深度优先搜索的</strong>

```cpp
/*
*   地图的dfs
*   搜索最短路
*/
const int gtNP[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int MAP[1000][1000]={0};
int MINN[1000][1000]={0};
int dfs(int x,int y,int ex,int ey)
{
    if(x==ex&&y==ey)
    {
        minn=min(MINN[x][y],minn);
    }
    else
    {
        for(int i=0;i<4;i++)
        {
            if(abletogo(x+gtNP[i][0],y+gtNP[i][1]))
                {
                    MINN[x+gtNP[i][0]][y+gtNP[i][1]]=MINN[x][y]+1;
                    dfs(x+gtNP[i][0],y+gtNP[i][1]);
                }
        }
    }
}
```