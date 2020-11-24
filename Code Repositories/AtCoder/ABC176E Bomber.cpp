#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
vector<int>vecr[maxn],vecc[maxn],mxvr,mxvc;
map<int,int>mp[maxn];
int main()
{
	int n,m,k,x,y;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		mp[x][y]=1;
		vecr[x].push_back(y);
		vecc[y].push_back(x);		
	}
	int sizr=0,sizc=0;
	for(int i=1;i<=n;i++)
	{
		if((int)vecr[i].size()>sizr)
			mxvr.clear(),sizr=vecr[i].size();
		if((int)vecr[i].size()==sizr)
			mxvr.push_back(i);
	}
	for(int i=1;i<=m;i++)
	{
		if((int)vecc[i].size()>sizc)
			mxvc.clear(),sizc=vecc[i].size();
		if((int)vecc[i].size()==sizc)
			mxvc.push_back(i);
	}
	int ans=sizr+sizc-1,ok=1;
	for(int i=0;i<(int)mxvr.size()&&ok;i++)
		for(int j=0;j<(int)mxvc.size()&&ok;j++)
			if(!mp[mxvr[i]][mxvc[j]]) ans++,ok=0;
	printf("%d\n",ans);
}