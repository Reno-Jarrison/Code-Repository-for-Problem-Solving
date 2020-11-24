#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5;
int ans[maxn+5],cnt[15];
char s1[15],s2[15];
int main()
{
	int n,first=1;
	while(~scanf("%d",&n)&&n)
	{
		if(!first) puts("");
		first=0; 
		bool flag=false;
		for(int i=0;i<maxn;i++)
		{
			int num1=i,num2=i*n,ok=true;
			if(num2>=maxn) continue;
			memset(cnt,0,sizeof(cnt));
			for(int i=4;i>=0;i--) 
			{
				cnt[num1%10]++,cnt[num2%10]++;
				s1[i]=num1%10+'0',num1/=10;
				s2[i]=num2%10+'0',num2/=10;
			}
			for(int i=0;i<10;i++)
				if(!cnt[i]) ok=false;
			if(!ok) continue;
			num1=i,num2=i*n,flag=true;
			printf("%s / %s = %d\n",s2,s1,n);
		}
		if(!flag) printf("There are no solutions for %d.\n",n);
	}
}