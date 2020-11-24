#include<bits/stdc++.h>
using namespace std;
int d[7]={0,3,4,5,6,1,2};
int u[7]={0,1,2,3,4,5,6};
void dnc(int n)
{
	if(n==1) return;
	if(n==2) 
	{	printf("234562"); return; }
	for(int i=1;i<=6;i++)
	{
		printf("%d",(i+1)%6?(i+1)%6:6);
		for(int j=1;j<=n-3;j++)
			printf("%d%d",d[i],u[i]);
		printf("%d%d",d[i],i==6?d[1]:u[i]);
	}
	dnc(n-2);
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
		scanf("%d",&n),dnc(n),puts("");
}