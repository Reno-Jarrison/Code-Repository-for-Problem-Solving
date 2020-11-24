#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int a[maxn];
bool tag[maxn];
int main()
{
	int t,n,m,b,idx;
	cin>>t;
	while(t--)
	{
		ll ans=0,cnt=0;
		cin>>n>>m,idx=0;
		memset(tag,0,sizeof(tag));
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=m;i++) 
		{
			cin>>b,ans++;
			if(tag[b]) cnt--;
			else 
			{
				while(a[++idx]!=b) tag[a[idx]]=true,cnt++;
				ans+=cnt*2,tag[b]=true;
			}
		}
		cout<<ans<<endl;
	}
}