#include<bits/stdc++.h>
using namespace std;
int ansx[2505],ansy[2505];
bool exi=true,a[105][105],b[105][105];
int main()
{
	int n,m,step=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
		{
			if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1])
			{
				b[i][j]=b[i+1][j]=b[i][j+1]=b[i+1][j+1]=true;
				ansx[++step]=i,ansy[step]=j;
			}
		}
	for(int i=1;i<=n&&exi;i++)
		for(int j=1;j<=m&&exi;j++)
			if(a[i][j]!=b[i][j]) exi=false;
	if(!exi) cout<<-1;
	else
	{
		cout<<step<<endl;
		for(int i=1;i<=step;i++)
			cout<<ansx[i]<<" "<<ansy[i]<<endl; 
	}
}

