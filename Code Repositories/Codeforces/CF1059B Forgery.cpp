#include<cstdio>
using namespace std;
const int maxn=1e3+5;
char s[maxn][maxn],t[maxn][maxn];
int nx[8]={-1,-1,0,1,1,1,0,-1};
int ny[8]={0,1,1,1,0,-1,-1,-1};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			t[i][j]='.';
	for(int i=1;i<n-1;i++)
		for(int j=1;j<m-1;j++)
		{
			int ok=1;
			for(int k=0;k<8;k++)
			{
				int x=i+nx[k],y=j+ny[k];
				if(s[x][y]=='.') ok=0;
			}
			if(ok) for(int k=0;k<8;k++)
				t[i+nx[k]][j+ny[k]]='#';
		}
	int ok=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]!=t[i][j]) ok=0;
	puts(ok?"YES":"NO");
}