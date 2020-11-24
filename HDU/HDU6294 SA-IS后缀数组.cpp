#include<iostream>
#include<cstring>
#define maxn 1000005
using namespace std;
int cmp[maxn];
char s[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		memset(cmp,0,sizeof(cmp));
		scanf("%d",&n);
		scanf("%s",s);
		for(int i=0;i<n;i++)
			if(s[i]<s[i+1]) cmp[i]=-1;
			else if(s[i]>s[i+1]) cmp[i]=1;
		for(int i=n-1;i;i--)
			if(!cmp[i-1]) cmp[i-1]=cmp[i];
		for(int i=0;i<n-1;i++)
			if(cmp[i]==-1) cout<<'<';
			else cout<<'>';	
			cout<<endl;	
	}
}