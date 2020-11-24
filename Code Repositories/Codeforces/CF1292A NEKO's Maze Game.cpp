#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
const int maxn=1e5+5;
bool a[maxn][2],sta[maxn][3];
set<int>s;
void update(int x,int n)
{
	if(!a[x][1])
		sta[x][0]=sta[x][1]=sta[x][2]=false,s.erase(x);
	else 
	{
		bool tag=false;
		for(int i=max(1,x-1);i<=min(n,x+1);i++)
			if(a[i][0]) sta[x][i-x+1]=true,tag=true;
			else sta[x][i-x+1]=false;
		if(tag) s.insert(x);
		else s.erase(x);
	}
}
int main()
{
	int n,q,r,c;
	scanf("%d%d",&n,&q);
	while(q--)
	{
		scanf("%d%d",&r,&c),r--;
		a[c][r]=!a[c][r];
		if(r) update(c,n);
		else for(int i=max(1,c-1);i<=min(n,c+1);i++)
			update(i,n);
		bool flag=a[1][0]||a[n][1];
		puts(s.empty()&&!flag?"Yes":"No");
	}
}