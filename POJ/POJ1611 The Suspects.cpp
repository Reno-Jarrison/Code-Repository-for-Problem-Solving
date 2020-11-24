#include<iostream>
#include<cstring> 
using namespace std;
int f[30005];
int find(int x)
{
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
inline void join(int x,int y)
{
	f[find(x)]=find(y);
}
int main()
{
	int n,m,stu,fat,son,ans;
	while(scanf("%d%d",&n,&m)&&(n||m))
	{
		ans=0;
		for(register int i=0;i<n;i++) f[i]=i;
		for(register int i=0;i<m;i++)
		{
			scanf("%d%d",&stu,&fat);
			while(--stu)
				scanf("%d",&son),join(son,fat);
		}
		for(register int i=0;i<n;i++)
			if(find(0)==find(i)) ans++;
		printf("%d\n",ans);
	}
}