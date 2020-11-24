#include<bits/stdc++.h>
using namespace std;
const int maxn=4e6+5;
long long ans;
struct Trie
{
	int tot,cnt[maxn],tag[maxn],nxt[maxn][62];
	void clear()
	{	ans=tot=0,newnode(); }
	int newnode()
	{	
		memset(nxt[tot],0,sizeof(nxt[tot]));
		return cnt[tot]=tag[tot]=0,tot++; 
	}
	int idx(int ch)
	{
		if('0'<=ch&&ch<='9') return ch-'0';
		if('A'<=ch&&ch<='Z') return ch-'A'+10;
		return ch-'a'+36;
	}
	void insert(char* s)
	{
		int len=strlen(s),pt=0;
		for(int i=0;i<len;i++)
		{
			int to=idx(s[i]);
			if(!nxt[pt][to])
				nxt[pt][to]=newnode();
			ans+=(cnt[pt]-cnt[nxt[pt][to]])*(2*i+1);
			cnt[pt]++;
			pt=nxt[pt][to];
		}
		ans+=(tag[pt])*(2*(len+1));
		ans+=(cnt[pt]-tag[pt])*(2*len+1);
		cnt[pt]++,tag[pt]++;
	}
}t;
char str[1005];
int main()
{
	int n,ks=0;
	while(scanf("%d",&n)&&n)
	{
		t.clear();
		for(int i=1;i<=n;i++)
			scanf("%s",str),t.insert(str);
		printf("Case %d: %lld\n",++ks,ans);
	}
}