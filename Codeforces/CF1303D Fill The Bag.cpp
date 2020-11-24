#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int cnt[65];
void update(int pos)
{
	cnt[pos]--;
	for(int i=pos-1;i;i--) cnt[i]++;
}
int main()
{
	ll n,x,sum;
	int t,m,tmp,ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>m,sum=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=m;i++)
		{
			cin>>x,sum+=x,tmp=0;
			while(x) x>>=1,tmp++;
			cnt[tmp]++;
		}
		tmp=1,ans=sum<n?-1:0;
		while(n&&ans!=-1)
		{
			if(n&1)
			{
				if(!cnt[tmp]) for(int i=tmp+1;i<65;i++) 
					if(cnt[i]) { update(i),ans+=i-tmp; break; }
				cnt[tmp]--;
			}
			cnt[tmp+1]+=cnt[tmp]/2,n>>=1,tmp++;
		}
		cout<<ans<<endl;
	}
}