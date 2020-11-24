#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x=1;
	char c;
	while((c=getchar())!=EOF)
	{
		switch(c)
		{
		case '"':
			cout<<(x?"``":"''");
			x=!x;
			break;
		default:	
			cout<<c;
		}
	}
}