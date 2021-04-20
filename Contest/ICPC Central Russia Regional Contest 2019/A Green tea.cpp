#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t1,t2,ok=0;
	scanf("%d%d",&t1,&t2);
	for(int i=1;i<=2000&&!ok;i++)
		for(int v1=0,v2=i-v1;v1<=i&&v2>=0&&!ok;v1++,v2--)
			if(t1*v1+t2*v2==80*i)
				printf("%d %d\n",v1,v2),ok=1;
}