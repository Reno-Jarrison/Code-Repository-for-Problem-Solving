#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map> 
#include <vector>
using namespace std;
 
int sum[105*256],set[105*256];  
void pushDown(int idx,int lx,int rx,int ly,int ry)
{
	if (set[idx]==-1) return;
	set[idx*4+1]=set[idx*4+2]=set[idx*4+3]=set[idx*4+4]=set[idx];
	int mx=(lx+rx)>>1,my=(ly+ry)>>1;
	sum[idx*4+1]=set[idx]*(mx-lx+1)*(my-ly+1);
	sum[idx*4+2]=set[idx]*(mx-lx+1)*(ry-my);
	sum[idx*4+3]=set[idx]*(rx-mx)*(my-ly+1);
	sum[idx*4+4]=set[idx]*(rx-mx)*(ry-my);
	set[idx]=-1;
}
void pushUp(int idx)
{
	sum[idx]=sum[idx*4+1]+sum[idx*4+2]+sum[idx*4+3]+sum[idx*4+4];
}
void insert(int idx,int lx,int rx,int ly,int ry,int Lx,int Rx,int Ly,int Ry,int val )
{
	if (Lx<=lx &&Rx>=rx &&Ly<=ly&&Ry>=ry)
	{
		set[idx]=val;
		sum[idx]=val*(rx-lx+1)*(ry-ly+1);
		return ;
	}
	pushDown(idx, lx, rx, ly, ry);
	int mx=(lx+rx)>>1,my=(ly+ry)>>1;
	if (Lx<=mx&&Ly<=my) insert(idx*4+1,lx,mx,ly,my,Lx,Rx,Ly,Ry,val);
if (Lx<=mx&&Ry>my) insert(idx*4+2,lx,mx,my+1,ry,Lx,Rx,Ly,Ry,val);
if (Rx>mx&&Ly<=my) insert(idx*4+3,mx+1,rx,ly,my,Lx,Rx,Ly,Ry,val);
if (Rx>mx&&Ry>my) insert(idx*4+4,mx+1,rx,my+1,ry,Lx,Rx,Ly,Ry,val);
	pushUp(idx);
}
int query(int idx, int lx, int rx, int ly, int ry, int Lx, int Rx, int Ly, int Ry)
{		
	if (Lx<=lx &&Rx>=rx &&Ly<=ly&&Ry>=ry) return sum[idx];
	pushDown(idx, lx, rx, ly, ry);
	int mx=(lx+rx)>>1,my=(ly+ry)>>1,t=0;
	if (Lx<=mx && Ly<=my) t+=query(idx*4+1,lx,mx,ly,my, Lx, Rx, Ly, Ry);
	if (Lx<=mx && Ry>my)  t+=query(idx*4+2,lx,mx,my+1,ry, Lx, Rx, Ly, Ry);
	if (Rx>mx && Ly<=my) t+=query(idx*4+3,mx+1,rx,ly,my, Lx, Rx, Ly, Ry);		
	if (Rx>mx && Ry>my ) t+=query(idx*4+4,mx+1,rx,my+1,ry, Lx, Rx, Ly, Ry);
	return t;
}	
 
int main()
{ 
	int n,x,y,L,i;
	char op[105];
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%s%d%d%d",op,&x,&y,&L);
		if (op[0]=='B')
		insert(0, 1, 100, 1, 100, x, x + L - 1, y, y + L - 1, 1); 
	    else if (op[0]=='W')
		insert(0, 1, 100, 1, 100, x, x + L - 1, y, y + L - 1, 0); 
		else
			printf("%d\n",query(0,1,100,1,100,x,x+L-1,y,y+L-1));
	}   
	return 0; 
}
