#include<bits/stdc++.h>
using namespace std;
struct node
{
	int n,m,h;
	node(int n,int m,int h):n(n),m(m),h(h){}
};
vector<node>ans1,ans2;
char s1[105][105],s2[105][105];
int main()
{
	int n,m,h,ok=1;
	scanf("%d%d%d",&n,&m,&h);
	for(int i=0;i<n;i++)
		scanf("%s",s1[i]);
	for(int i=0;i<n;i++)
		scanf("%s",s2[i]);
	for(int i=0;ok&&i<n;i++)
	{
		for(int j=0;j<m;j++)
			for(int k=0;k<h;k++)
				if(s1[i][j]=='1'&&s2[i][k]=='1')
				ans1.emplace_back(i,j,k);
		vector<int>posm,posh;
		for(int j=0;j<m;j++)
			if(s1[i][j]=='1')
				posm.push_back(j);
		for(int j=0;j<h;j++)
			if(s2[i][j]=='1')
				posh.push_back(j);
		if(!posh.size()&&posm.size()) ok=0;
		if(posh.size()&&!posm.size()) ok=0;
		if(!ok||(!posh.size()&&!posm.size()))
			continue;
		int tot=max(posm.size(),posh.size()),pt1=0,pt2=0;
		while(tot--)
		{
			ans2.emplace_back(i,posm[pt1++],posh[pt2++]);
			if(posm.size()-pt1<posh.size()-pt2) pt1--;
			if(posm.size()-pt1>posh.size()-pt2) pt2--;
		}
	}
	if(!ok)
		puts("-1");
	else
	{
		printf("%d\n",(int)ans1.size());
		for(node x:ans1)
			printf("%d %d %d\n",x.n,x.m,x.h);
		printf("%d\n",(int)ans2.size());
		for(node x:ans2)
			printf("%d %d %d\n",x.n,x.m,x.h);
	}
}