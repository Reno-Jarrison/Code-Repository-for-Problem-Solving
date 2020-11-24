#include<bits/stdc++.h>
using namespace std;
int a[30],ok;
int way1[8]={1,3,5,7,9,11,13,15};
int way2[8]={4,5,22,20,15,14,17,19};
int way3[8]={2,3,22,23,9,8,18,19};
bool check()
{
	for(int i=0;i<24;i+=4)
		for(int j=1;j<=3;j++)
			if(a[i+j]!=a[i]) return false;
	return true;
}
void turn(int *way,int tag)
{
	if(tag)
	{
		int init0=a[way[0]],init1=a[way[1]];
		for(int i=0;i<6;i++)
			a[way[i]]=a[way[i+2]];
		a[way[6]]=init0,a[way[7]]=init1;
	}
	else
	{
		int init0=a[way[6]],init1=a[way[7]];
		for(int i=7;i>1;i--)
			a[way[i]]=a[way[i-2]];
		a[way[0]]=init0,a[way[1]]=init1;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<24;i++)
			scanf("%d",&a[i]);
		ok=check();
		for(int i=0;i<24;i++)
		turn(way1,1),ok|=check(),turn(way1,0);
		turn(way1,0),ok|=check(),turn(way1,1);
		turn(way2,1),ok|=check(),turn(way2,0);
		turn(way2,0),ok|=check(),turn(way2,1);
		turn(way3,1),ok|=check(),turn(way3,0);
		turn(way3,0),ok|=check(),turn(way3,1);
		puts(ok?"YES":"NO");
	}
}