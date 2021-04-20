#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int main()
{
	int n,w,score,y=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&w,&score),y+=w*score;
	printf("%d\n",max(y,0));
}