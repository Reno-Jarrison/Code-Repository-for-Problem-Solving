#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5,maxm=1e4;
int pcnt,ncnt,prime[maxm],vis[maxn+5];
struct node
{
	int cnt,nxt[100];
}trie[maxn*10+5];
void getprime()
{
	for(int i=2;i<=maxn;i++)
	{
		if(!vis[i]) prime[++pcnt]=i;
		for(int j=1;i*prime[j]<=maxn;j++)
		{
			vis[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
}
int main()
{
	getprime();
	int n,k,a,tmp;
	ll ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a,tmp=a;
		int pt=0,sum=trie[0].cnt;
		for(int j=1;j<=pcnt;j++)
		{
			int cnt=0,ttmp=tmp;
			while(ttmp%prime[j]==0)
				ttmp/=prime[j],cnt++;
			cnt=(k-cnt%k)%k;
			if(!trie[pt].nxt[cnt]) break;
			else pt=trie[pt].nxt[cnt];
			sum+=trie[pt].cnt;
			tmp=ttmp;
		}
		if(tmp==1) ans+=sum;
		printf("%d %d\n",i,ans);
		pt=0,tmp=a;
		for(int j=1;j<=pcnt&&tmp>1;j++)
		{
			int cnt=0;
			while(tmp%prime[j]==0)
				tmp/=prime[j],cnt++;
			cnt%=k;
			if(!trie[pt].nxt[cnt])
				trie[pt].nxt[cnt]=++ncnt;
			pt=trie[pt].nxt[cnt];
		}
		cout<<pt<<endl;
		trie[pt].cnt++;
	}
	cout<<ans;
}

