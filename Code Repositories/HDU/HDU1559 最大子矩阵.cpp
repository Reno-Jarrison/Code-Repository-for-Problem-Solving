#include<iostream>
using namespace std;
int matrix[1005][1005],sumcol[1005][1005],sumrow[1005][1005];
int main()
{
	int t,m,n,x,y,max;
	cin>>t;
	while(t--)
	{
		cin>>m>>n>>x>>y;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				cin>>matrix[i][j];
		for(int i=1;i<=n;i++)
		{
			sumcol[1][i]=0;
			for(int j=1;j<=x;j++)
				sumcol[1][i]+=matrix[j][i];
			for(int j=2;j<=m-x+1;j++)
				sumcol[j][i]=sumcol[j-1][i]+matrix[j+x-1][i]-matrix[j-1][i];
		}
		for(int i=1;i<=m-x+1;i++)
		{
			sumrow[i][1]=0;
			for(int j=1;j<=y;j++)
				sumrow[i][1]+=sumcol[i][j];
			if(sumrow[i][1]>max)
				max=sumrow[i][1];
			for(int j=2;j<=n-y+1;j++)
			{
				sumrow[i][j]=sumrow[i][j-1]+sumcol[i][j+y-1]-sumcol[i][j-1];
				if(sumrow[i][j]>max)
					max=sumrow[i][j];
			}
		}
		cout<<max<<endl;
	}
}