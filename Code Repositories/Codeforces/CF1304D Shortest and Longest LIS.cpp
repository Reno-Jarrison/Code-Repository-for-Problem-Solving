#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
char s[maxn];
int ans[2][maxn];
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n>>(s+1);
		vector<int>v;
		for(int i=2;i<n;i++)
			if(s[i]!=s[i-1])
				v.push_back(i);
		v.push_back(n);
		int pt0=n,pt1=1,tag=s[1]=='<',las=1;
		for(int x:v)
		{
			if(tag)
			{
				for(int i=x;i>=las;i--)
					ans[0][i]=pt0--;
				if(las==1) ans[1][1]=pt1++;
				for(int i=las+1;i<x;i++)
					ans[1][i]=pt1++;
				if(x==n) ans[1][n]=pt1++;
			}
			else
			{
				if(las==1) ans[0][1]=pt0--;
				for(int i=las+1;i<x;i++)
					ans[0][i]=pt0--;
				if(x==n) ans[0][n]=pt0--;
				for(int i=x;i>=las;i--)
					ans[1][i]=pt1++;
			}
			las=x,tag=!tag;
		}
		for(int i=1;i<=n;i++) cout<<ans[0][i]<<" ";
		puts("");
		for(int i=1;i<=n;i++) cout<<ans[1][i]<<" ";
		puts("");
	}
}