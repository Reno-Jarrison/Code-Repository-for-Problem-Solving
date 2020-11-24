#include<bits/stdc++.h>
using namespace std;
int cnt[4],nx[4]={0,1,0,-1},ny[4]={1,0,-1,0};
int main()
{
	int n,sx,sy,x,y;
	cin>>n>>sx>>sy;
	while(n--)
	{
		cin>>x>>y,x-=sx,y-=sy;
		if(x>0) cnt[1]++; 
		if(x<0) cnt[3]++;
		if(y>0) cnt[0]++; 
		if(y<0) cnt[2]++;
	}
	int mxv=max({cnt[0],cnt[1],cnt[2],cnt[3]});
	printf("%d\n",mxv);
	for(int i=0;i<4;i++) if(mxv==cnt[i])
	{	printf("%d %d",sx+nx[i],sy+ny[i]); break; }
}