#include<bits/stdc++.h>
using namespace std;
char s[65][65];
int main()
{
	int t,r,c;
	cin>>t;
	while(t--)
	{
		cin>>r>>c;
		for(int i=1;i<=r;i++)
			cin>>(s[i]+1);
		int g[65][65];
		bool taga=false,tagp=false;
		bool rx[65]={0},cx[65]={0};
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				if(s[i][j]=='A') taga=true,g[i][j]=1;
				else tagp=rx[i]=cx[j]=true,g[i][j]=0;
		if(!taga) {	puts("MORTAL"); continue; }
		int ans=4;
		for(int i=2;i<r;i++)
			if(g[i][1]||g[i][c]) ans=3;
		for(int i=2;i<c;i++)
			if(g[1][i]||g[r][i]) ans=3;
		if(g[1][1]||g[1][c]||g[r][1]||g[r][c]) ans=2;
		for(int i=2;i<r;i++)
			if(!rx[i]) ans=2;
		for(int i=2;i<c;i++)
			if(!cx[i]) ans=2;
		if(!rx[1]||!rx[r]||!cx[1]||!cx[c]) ans=1;
		if(!tagp) ans=0;
		cout<<ans<<endl;
	}	
}