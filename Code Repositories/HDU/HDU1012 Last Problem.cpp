#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5,base=500;
int a[maxn][maxn];
void paint(int id,int x,int y)
{	printf("%d %d %d\n",x-base,y-base,id),a[x][y]=id; }
void solve(int n,int x,int y)
{
	if(!n) { paint(x,y,0); return; }
	if(a[x-1][y]!=max(0,n-4))
		solve(max(0,n-4),x-1,y);
	if(a[x][y+1]!=max(0,n-3))
		solve(max(0,n-3),x,y+1);
	if(a[x][y-1]!=max(0,n-2))
		solve(max(0,n-2),x,y-1);
	if(a[x+1][y]!=max(0,n-1))
		solve(max(0,n-1),x+1,y);
	paint(n,x,y);
}
int main()
{
	int n;
	scanf("%d",&n);
	solve(n,base,base);
}