#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
char mat[2][6][5],alp[5][6];
int num[5],mul[6];
int main()
{
	int t,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&k);
		for(int d=0;d<2;d++)
			for(int i=0;i<6;i++)
				scanf("%s",mat[d][i]);
		memset(num,0,sizeof(num)),mul[5]=1;
		for(int i=0;i<5;i++)
			for(int j=0;j<26;j++)
			{
				bool flag1=false,flag2=false;
				for(int d=0;d<6;d++)
				{
					if(mat[0][d][i]=='A'+j) flag1=true;
					if(mat[1][d][i]=='A'+j) flag2=true;
				}
				if(flag1&&flag2) alp[i][num[i]++]='A'+j;
			}
		for(int i=4;i>=0;i--) mul[i]=mul[i+1]*num[i];
		if(k-->mul[0]) { puts("NO"); continue; }
		for(int i=1;i<=5;i++)
		{
			printf("%c",alp[i-1][k/mul[i]]);
			k%=mul[i];
		}
		puts("");
	}
}