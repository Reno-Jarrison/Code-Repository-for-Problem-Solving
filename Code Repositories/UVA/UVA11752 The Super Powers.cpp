#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
bool vis[65];
const ll maxn=~0LL>>1;
vector<ll>ans;
vector<ll>::iterator it,itend;
void getcom()
{
	int pcnt=0,p[30]={0};
	for(int i=2;i<64;i++)
	{
		if(!vis[i]) p[++pcnt]=i;
		for(int j=1;i*p[j]<=64;j++)
		{
			vis[i*p[j]]=true;
			if(i%p[j]==0) break; 
		}	
	}
}
int main()
{
	getcom();
	ans.push_back(1);
	for(int i=2;i<65536;i++)
	{
		ll tmp=(ll)i*i*i,x=maxn;
		int k=-1;
		while(x) x/=(ll)i,k++;
		for(int j=4;j<=k;j++)
		{
			tmp=tmp*(ll)i;
			if(vis[j]) ans.push_back(tmp);
		}
	}
	sort(ans.begin(),ans.end());
	itend=unique(ans.begin(),ans.end()); 
	for(it=ans.begin();it!=itend;it++)
		printf("%llu\n",*it);
}
