#include<iostream>
#define maxn 100005
using namespace std;
bool vis[maxn];
int e[maxn],a[maxn],b[maxn];
int main()
{
	int t,n,cnt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]),vis[i]=0,e[a[i]]=b[i];
		cnt=0;
		for(int i=1;i<=n;i++)
			if(!vis[a[i]])
			{
				int next=a[i],k=0;
				while(!vis[next])
					vis[next]=1,next=e[next],k++;
				if(k>1) cnt++;
			}
		printf("%d\n",n-cnt);
	}
} 