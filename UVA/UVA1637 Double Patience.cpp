#include<cstdio>
#include<cstring>
#include<vector> 
using namespace std;
const int maxn=1953125;
char idx[5]={'A','T','J','Q','K'};
int a[9][5],sta[9];
double dp[maxn];
int getid(char x)
{
	for(int i=0;i<5;i++)
		if(x==idx[i]) return i; 
	return x-'1';
}
int read()
{
	char tmp[5];
	for(int i=0;i<9;i++)
		for(int j=1;j<=4;j++)
			if(scanf("%s",tmp)==-1) return -1;
			else a[i][j]=getid(tmp[0]);
	return 0;
}
int main()
{
	while(~read())
	{
		memset(dp,0,sizeof(dp)),dp[maxn-1]=1.0;
		for(int i=maxn-1;i;i--)
		{
			int tmp=i,sum=0;
			if(dp[i]==0.0) continue;
			vector<int>v[9];
			for(int j=0;j<9;j++)
			{	
				sta[j]=tmp%5,tmp/=5;
				if(!sta[j]) sta[j]=0;
				else v[a[j][sta[j]]].push_back(j);
			}
			for(int j=0;j<9;j++) 
				sum+=v[j].size()*(v[j].size()-1)/2;
			for(int j=0;j<9;j++)
				for(int x=0;x<(int)v[j].size()-1;x++)
					for(int y=x+1;y<(int)v[j].size();y++)
					{
						sta[v[j][x]]--,sta[v[j][y]]--;
						int nsta=0;
						for(int k=8;k>=0;k--)
							nsta=nsta*5+sta[k];
						dp[nsta]+=dp[i]/sum;
						sta[v[j][x]]++,sta[v[j][y]]++;
					}
		}
		printf("%.6lf\n",dp[0]);
	}
}