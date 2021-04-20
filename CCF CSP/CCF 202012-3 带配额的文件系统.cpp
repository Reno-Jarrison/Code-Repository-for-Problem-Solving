#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+5;
const ll inf=1e19;
map<string,int>mp;
vector<int>e[maxn];
int flag[maxn],idx;
ll lim1[maxn],lim2[maxn],siz1[maxn],siz2[maxn];
int insert(string s,int tag)
{
	mp[s]=++idx;
	flag[idx]=tag;
	lim1[idx]=lim2[idx]=inf;
	siz1[idx]=siz2[idx]=0;
	return idx;
}
void remove(int u)
{
	flag[u]=-1;
	lim1[u]=lim2[u]=inf;
	siz1[u]=siz2[u]=0;
	for(int v:e[u])
		if(flag[v]!=-1)
			remove(v);
	e[u].clear();
}
string getf(string s)
{
	if(s=="/") return "";
	int pt=s.length();
	while(s[--pt]!='/');
	s=pt?s.substr(0,pt):"/";
	return s;
}
bool newfile(string cur,ll add,int tag1,int tag2)
{
	int id=mp[cur];
	if(tag2&&siz1[id]+add>lim1[id])
		return false;
	if(tag2&&tag1) siz1[id]+=add;
	while(cur!="")
	{
		id=mp[cur];
		if(siz2[id]+add>lim2[id])
			return false;
		if(tag1) siz2[id]+=add;
		cur=getf(cur);
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	memset(flag,-1,sizeof(flag));
	insert("/",1);
	for(int i=1;i<=n;i++)
	{
		ll a,b;
		string o,path;
		cin>>o>>path;
		int ok=0,id=mp[path];
		if(o[0]=='C')
		{
			cin>>a;
			if(flag[id]==0)
			{
				string f=getf(path);
				if(newfile(f,a-siz2[id],0,1))
					newfile(f,a-siz2[id],1,1),siz2[id]=a,ok=1;
			}
			else if(flag[id]==-1)
			{
				string f=getf(path);
				stack<string>stk;
				while(flag[mp[f]]==-1)
					stk.push(f),f=getf(f);
				if(flag[mp[f]]==1&&newfile(f,a,0,f==getf(path)))
				{
					while(!stk.empty())
					{
						string cur=stk.top(); stk.pop();
						insert(cur,1);
						e[mp[f]].push_back(mp[cur]),f=cur;
					}
					newfile(f,a,1,1);
					insert(path,0);
					int id=mp[path];
					e[mp[f]].push_back(id);
					siz2[id]=a,ok=1;
				}
			}
		}
		if(o[0]=='R')
		{
			if(flag[id]!=-1)
			{
				string f=getf(path);
				if(flag[id]==0)
					siz1[mp[f]]-=siz2[id];
				while(f!="")
					siz2[mp[f]]-=siz2[id],f=getf(f);
				remove(id);
			}
			ok=1;
		}
		if(o[0]=='Q')
		{
			cin>>a>>b;
			if(flag[id]==1)
			{
				if(!a) a=inf;
				if(!b) b=inf;
				if(siz1[id]<=a&&siz2[id]<=b)
					lim1[id]=a,lim2[id]=b,ok=1;
			}
		}
		puts(ok?"Y":"N");
	}
}