#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans,num,n;
int p[10]={0,2,3,5,7,11,13,17,19,23};
void dfs(int step,int lastcnt,ll tmul,ll tnum)
{
	if(step>=10) return;
	if(tnum>num||tnum==num&&ans>tmul) 
		num=tnum,ans=tmul;
	for(int i=1;i<=lastcnt&&tmul*p[step]<=n;i++)
		dfs(step+1,i,tmul*=p[step],tnum*(i+1));
}
int main()
{
	cin>>n;
	dfs(1,35,1,1);
	cout<<ans; 
}