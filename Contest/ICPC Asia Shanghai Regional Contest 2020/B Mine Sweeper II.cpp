#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
char s1[maxn][maxn],s2[maxn][maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s1[i]+1);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s2[i]+1);
		for(int j=1;j<=m;j++)
			cnt+=s1[i][j]!=s2[i][j];
	}
	if(cnt>n*m/2)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				s1[i][j]=s1[i][j]=='X'?'.':'X';
	for(int i=1;i<=n;i++)
		printf("%s\n",s1[i]+1);
}