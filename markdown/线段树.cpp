#include<bits/stdc++.h>
using namespace std;
#define lson(p) (p<<1)
#define rson(p) (p<<1|1)
#define MAXN 1000
#define MAX -1
#define MIN 0
#define t tree
int n;
int tag[MAXN*4];
int tree[MAXN*4];
void push_up_sum(int p)
{
	t[p]=t[lson(p)]+t[rson(p)];
}
void push_up(int p,int operators)
{
	if(operators===MAX)
		t[p]=max(t[lson(p)],t[rson(p)]);
	else
		t[p]=min(t[lson(p)],t[rson(p)]);
}
void push_up_xor(int p)
{
	t[p]=t[lson(p)] xor t[rson(p)];
}
void build_tree(int p,int l,int r)
{
	if(l==r)
	{
		ans[p]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(lson(p),l,mid);
	build(rson(p),mid+1,r);
	push_up_sum(p);
}
inline void push_down(ll p,ll l,ll r)
{
    int mid=(l+r)>>1;
    f(lson(p),l,mid,tag[p]);
    f(rson(p),mid+1,r,tag[p]);
    tag[p]=0;
}
int query(int x,int y,int l,int r,int p)
{
	int res=0;
    if(x<=l&&r<=y)return ans[p];
    int mid=(l+r)>>1;
    push_down(p,l,r);
    if(x<=mid)res+=query(x,y,l,mid,lson(p));
    if(y>mid) res+=query(x,y,mid+1,r,rson(p));
    return res;
}
inline void update(int nl,int nr,int l,int r,int p,int k)
{
    if(nl<=l&&r<=nr)
    {
        ans[p]+=k*(r-l+1);
        tag[p]+=k;
        return ;
    }
    push_down(p,l,r);
    ll mid=(l+r)>>1;
    if(nl<=mid)update(nl,nr,l,mid,ls(p),k);
    if(nr>mid) update(nl,nr,mid+1,r,rs(p),k);
    push_up(p); 
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>	
}
