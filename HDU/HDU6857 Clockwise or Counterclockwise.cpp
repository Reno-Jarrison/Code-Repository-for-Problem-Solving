#include<bits/stdc++.h>
using namespace std;
bool cross(int xi,int yi,int xj,int yj)
{	return 1LL*xi*yj<1LL*xj*yi; }
int main()
{
	int t,x1,y1,x2,y2,x3,y3;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		bool tag1=cross(x1,y1,x2,y2);
		bool tag2=cross(x2,y2,x3,y3);
		bool tag3=cross(x3,y3,x1,y1);
		bool ok=0;
		if(tag1&&tag2) ok=1;
		if(tag1&&!tag2&&tag3) ok=1;
		if(!tag1&&tag2&&tag3) ok=1;
		puts(ok?"Clockwise":"Counterclockwise");
	}
}