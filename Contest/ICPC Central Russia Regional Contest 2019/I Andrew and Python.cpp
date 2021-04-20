#include<bits/stdc++.h>
using namespace std;
bool ask(int o,int x1,int y1,int x2=0,int y2=0,int x3=0,int y3=0)
{
	if(o==1)
		printf("? 1 %d %d\n",x1,y1);
	if(o==2)
	{
		if(x1==x2&&y1==y2) return ask(1,x1,y1);
		printf("? 2 %d %d %d %d\n",x1,y1,x2,y2);
	}
	if(o==3)
	{
		if(x1==x2&&y1==y2) return ask(2,x1,y1,x3,y3);
		if(x1==x3&&y1==y3) return ask(2,x1,y1,x2,y2);
		if(x2==x3&&y2==y3) return ask(2,x2,y2,x3,y3);
		printf("? 3 %d %d %d %d %d %d\n",x1,y1,x2,y2,x3,y3);
	}
	fflush(stdout);
	char s[5];
	scanf("%s",s);
	return s[0]=='Y';
}
void answer(int x,int y)
{	printf("! %d %d\n",x,y),fflush(stdout); }
int main()
{
	int n;
	scanf("%d",&n);
	if(n==1) answer(1,1);
	else
	{
		int p=ask(3,1,1,1,n,n,1)?1:n,l=1,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(ask(3,p,p,p,mid,mid,p))
				p==1?r=mid-1:l=mid+1;
			else p==1?l=mid+1:r=mid-1;
		}
		int lx,rx,k;
		if(p==1) 
			lx=1,rx=l,k=1+l;
		else lx=r,rx=n,k=r+n;
		while(lx<=rx)
		{
			int mid=(lx+rx)>>1;
			if(ask(2,lx,k-lx,mid,k-mid))
				rx=mid-1;
			else lx=mid+1;
		}
		answer(lx,k-lx);
	}
}