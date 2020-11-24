#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int f[maxn];
bool tag[maxn][30];
char s[55];
vector<int>v[30];
int find(int x)
{	return f[x]==x?f[x]:f[x]=find(f[x]); }
int main()
{
	int n,ans;
	scanf("%d",&n),ans=n;
	for(int i=1;i<=n;i++) 
	{
		scanf("%s",s),f[i]=i;
		int len=strlen(s);
		for(int j=0;j<len;j++)
			if(!tag[i][s[j]-'a'])
			{
				tag[i][s[j]-'a']=true;
				v[s[j]-'a'].push_back(i);
			}
	}
	for(int i=0;i<26;i++)
	{
		int siz=v[i].size();
		if(!siz) continue;
		for(int j=1;j<siz;j++)
		{
			int fx=find(v[i][0]),fy=find(v[i][j]);
			if(fx==fy) continue;
			f[fy]=fx,ans--;
		}
	}
	cout<<ans;
}