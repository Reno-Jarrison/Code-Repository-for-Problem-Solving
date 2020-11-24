#include<iostream>
#include<cstring>
using namespace std;
char ins[205];
int main()
{
	int m1,m2,r1,r2,r3,len;
	while(cin>>m1>>m2>>ins)
	{
		r1=r2=r3=0;
		len=strlen(ins);
		for(int i=0;i<len;i++)
		{
			switch(ins[i])
			{
			case 'A':
				r1=m1; break;
			case 'B':
				r2=m2; break;
			case 'C':
				m1=r3; break;
			case 'D':
				m2=r3; break;
			case 'E':
				r3=r1+r2; break;
			case 'F':
				r3=r1-r2; break;
			}
		}
		cout<<m1<<","<<m2<<endl; 
	}
}