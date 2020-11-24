#include<iostream>
#define isleap(y) y%4==0&&y%100||y%400==0
using namespace std;
char day[12];
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int y=0,m=0,d=0,dif=0;
		cin>>day;
		for(int i=0;i<4;i++)
			y*=10,y+=day[i]-'0';
		for(int i=5;i<7;i++)
			m*=10,m+=day[i]-'0';
		for(int i=8;i<10;i++)
			d*=10,d+=day[i]-'0';
		if(m==2&&d==29)
		{
			while(1)
			{
				if((isleap(y))&&(dif!=0)&&(dif%7==0))
					break;
				if(isleap(y))
					dif++;
				dif++,y++;
			}
		}
		else if(m>2)
			while(dif%7||dif==0)
			{
				y++,dif++;
				if(isleap(y))
					dif++;
			}
		else
			while(dif%7||dif==0)
			{
				if(isleap(y))
					dif++;
				y++,dif++;
			}		
		cout<<y<<endl;
	}
}