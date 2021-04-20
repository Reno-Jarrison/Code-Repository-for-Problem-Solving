#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e5+5;
int main()
{
	int n,x,las=0;
	scanf("%d",&n);
	ll ans=0;
	vector<int>vecr,vecb;
	for(int i=1;i<=n;i++)
	{
		char s[3];
		scanf("%d%s",&x,s);
		if(s[0]=='G')
		{
			if(!las)
			{
				if(!vecr.empty()) ans+=x-vecr.front();
				if(!vecb.empty()) ans+=x-vecb.front();
			}
			else
			{
				ans+=x-las;
				int tmpr=0,tmpb=0,tagr=0,tagb=0;
				if(!vecr.empty())
				{
					tmpr=vecr[0]-las,tagr=1;
					vecr.push_back(x);
					int siz=vecr.size();
					for(int i=1;i<siz;i++)
						tmpr=max(tmpr,vecr[i]-vecr[i-1]);
				}
				if(!vecb.empty())
				{
					tmpb=vecb[0]-las,tagb=1;
					vecb.push_back(x);
					int siz=vecb.size();
					for(int i=1;i<siz;i++)
						tmpb=max(tmpb,vecb[i]-vecb[i-1]);
				}
				if(tagr&&!tagb)
					ans+=x-las-tmpr;
				if(!tagr&&tagb)
					ans+=x-las-tmpb;
				if(tagr&&tagb)
					ans+=min(x-las,2*(x-las)-tmpr-tmpb);
			}
			las=x,vecr.clear(),vecb.clear();
		}
		if(s[0]=='R') vecr.push_back(x);
		if(s[0]=='B') vecb.push_back(x);
	}
	if(las&&!vecb.empty()) ans+=vecb.back()-las;
	if(las&&!vecr.empty()) ans+=vecr.back()-las;
	if(!las)
	{
		int sizr=vecr.size(),sizb=vecb.size();
		if(sizr) ans+=vecr.back()-vecr.front();
		if(sizb) ans+=vecb.back()-vecb.front();
	}
	printf("%lld\n",ans);
}
