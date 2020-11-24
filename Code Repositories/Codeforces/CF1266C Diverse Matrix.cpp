#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int x[maxn][2];
int main()
{
	int r,c,pt=0;
	cin>>r>>c;
	if(r<c)
	{
		for(int i=1;i<=r;i++) x[i][0]=++pt;
		for(int i=1;i<=c;i++) x[i][1]=++pt;
	}
	else 
	{
		for(int i=1;i<=c;i++) x[i][1]=++pt;	
		for(int i=1;i<=r;i++) x[i][0]=++pt;
	}
	if(r==1&&c==1) x[1][0]=x[1][1]=0;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
			cout<<x[i][0]*x[j][1]<<" ";
		puts("");
	}
}