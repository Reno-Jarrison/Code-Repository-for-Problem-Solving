#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
	int n;
	char ch[15]={0};
	while(cin>>n)
	{
		memset(ch,0,15);
		int count=0,k=0;
		for(int i=9;i>=0;i--)
		{
			if(n>=pow(2,i))
			{
				count++;
				n-=pow(2,i);
				ch[k++]='1';
			}
			else
			{
				if(count)
				ch[k++]='0';
			}
		}
		cout<<ch<<endl;			
	}	
}