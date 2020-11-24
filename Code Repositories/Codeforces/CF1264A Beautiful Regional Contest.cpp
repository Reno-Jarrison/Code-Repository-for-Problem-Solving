#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
int p[maxn];
unordered_map<int,int>mp;
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n),mp.clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]),mp[p[i]]++;
		int g=mp[p[1]],s=0,b=0,mid=p[n/2],pt;
		if(p[n/2]==p[n/2+1]) mid++;
		for(pt=p[1]-1;pt>=mid&&s<=g;pt--)
			s+=mp[pt];
		while(pt>=mid) b+=mp[pt--];
		if(!g||!b||!s||s<=g||b<=g) g=s=b=0;
		printf("%d %d %d\n",g,s,b);
	}
}