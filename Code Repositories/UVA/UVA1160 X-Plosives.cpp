#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int f[maxn],cnt[maxn],ans;
void init()
{	for(int i=1;i<=maxn-5;i++) f[i]=i; ans=0; }
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
void join(int x,int y)
{	f[find(x)]=find(y); }
int main()
{
	int a,b;
	init();
	while(cin>>a)
		if(a==-1) cout<<ans<<endl,init();
		else 
		{
			cin>>b;
			if(find(a)==find(b)) ans++;
			else join(a,b);
		}
}
