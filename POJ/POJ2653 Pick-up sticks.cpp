#include<cstdio>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
const int maxn=1e5+5;
struct Point 
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	void read()
	{	scanf("%lf%lf",&x,&y); }
};
typedef Point Vector;
struct Seg
{
	Point a,b;
	int id;
	Seg(Point a,Point b,int id):a(a),b(b),id(id){}
};
const double eps=1e-10;
int dcmp(double x)
{	return fabs(x)<eps?0:x<0?-1:1; }
Vector operator +(Vector a,Vector b)
{	return Vector(a.x+b.x,a.y+b.y); } 
Vector operator -(Vector a,Vector b)
{	return Vector(a.x-b.x,a.y-b.y); } 
double Cross(Vector a,Vector b)
{	return a.x*b.y-a.y*b.x; }
bool SSIntersection(Point a1,Point a2,Point b1,Point b2)
{   
	double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1);
	double c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0; 
}
bool SSIntersection(Seg s1,Seg s2)
{   
	Point a1=s1.a,a2=s1.b,b1=s2.a,b2=s2.b;
	double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1);
	double c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0; 
}
int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
		vector<Seg>s;
		vector<Seg>::iterator it;
		for(int i=1;i<=n;i++)
		{
			Point a,b;
			a.read(),b.read();
			Seg l(a,b,i);
			for(it=s.begin();it!=s.end();it++)
			{
				while(it!=s.end()&&SSIntersection((*it),l))
					s.erase(it);
				if(it==s.end()) break;
			}
			s.push_back(l); 
		}
		int m=s.size();
		printf("Top sticks:");
		for(int i=0;i<m;i++)
			printf(" %d%s",s[i].id,i<m-1?",":".\n");
	}
}
