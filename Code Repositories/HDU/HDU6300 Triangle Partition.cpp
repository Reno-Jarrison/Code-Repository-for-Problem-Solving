#include<iostream>
#include<algorithm>
using namespace std;
struct Point
{
	int x,y,id;
}p[3005];
bool cmp(Point a,Point b)
{
	if(a.x==b.x)
		return a.y<b.y;
	else
		return a.x<b.x;
}
int main()
{
	ios::sync_with_stdio(false);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		n*=3;
		for(int i=0;i<n;i++)
			cin>>p[i].x>>p[i].y,p[i].id=i+1;
		sort(p,p+n,cmp);	
		for(int i=0;i<n;i+=3)
			cout<<p[i].id<<" "<<p[i+1].id<<" "<<p[i+2].id<<endl;	
	}
	return 0;
}