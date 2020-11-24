#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<vector>
using namespace std;
char s[200];
vector<int>e[30],v,out;
int ans,res[30],siz;
bool flag[30],etag[30][30];
void dfs(int step)
{
	if(step==siz)
	{
		int tmp=0;
		for(int i=0;i<siz;i++)
			for(int j=i+1;j<siz;j++)
				if(etag[res[i]][res[j]])
					tmp=max(tmp,j-i);
		if(tmp<ans)
		{
			ans=tmp,out.clear();
			for(int i=0;i<siz;i++)
				out.push_back(res[i]);
		}			
	}
	for(int i=0;i<siz;i++)
		if(!flag[v[i]]) 
		{
			int ok=1;
			res[step]=v[i];
			for(int j=0;j<step;j++)
				if(e[v[i]][res[j]]&&j-i>ans) ok=0;
			if(!ok) continue;
			flag[v[i]]=true;
			dfs(step+1);
			flag[v[i]]=false;
		}
}
void link(int u,int v)
{	
	if(etag[u][v]) return;
	e[u].push_back(v),etag[u][v]=true;
	e[v].push_back(u),etag[v][u]=true;
}
int main()
{
	while(scanf("%s",s))
	{
		int len=strlen(s),pt=-1;
		if(len==1&&s[0]=='#') break;
		memset(etag,0,sizeof(etag)),v.clear();
		for(int i=0;i<26;i++) e[i].clear();
		bool vflag[30]={0};
		for(int i=0;i<len;i++)
			if(isupper(s[i]))
			{
				int x=s[i]-'A';
				if(!vflag[x]) 
					v.push_back(x),vflag[x]=true;
				if(pt==-1) pt=x;
				else link(pt,x);
			}
			else if(s[i]==';') pt=-1;
		siz=v.size(),ans=siz;
		sort(v.begin(),v.end());
		dfs(0);
		for(int i=0;i<siz;i++)
			printf("%c ",'A'+out[i]);
		printf("-> %d\n",ans);
	}
}
