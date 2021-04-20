#include<bits/stdc++.h>
using namespace std;
int find(int a,int b,int n)
{
	if(n<=2) return 1;
	int f0=1,f1=1,f2;
	for(int i=3;i<=n;i++)
		f2=(a*f1+b*f0)%7,f0=f1,f1=f2;
	return f2;
}
int main()
{
	int a,b,n;
	while(scanf("%d%d%d",&a,&b,&n)&&a)
	{
		map<pair<int,int>,int>mp;
		int f0=1,f1=1,pos=1,len=0,pt=0;
		while(true)
		{
			if(mp[make_pair(f0,f1)])
			{
				pos=mp[make_pair(f0,f1)];
				len=pt-pos+1;
				break;
			}
			mp[make_pair(f0,f1)]=++pt;
			int f2=(a*f1+b*f0)%7;
			f0=f1,f1=f2,pt++;
		}
		if(n>pos) n-=(n-pos)/len*len;
		printf("%d\n",find(a,b,n));
	}
}