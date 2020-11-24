#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	if(a==b) printf("%d0 %d1",a,b);
	else if(a==b-1) printf("%d9 %d0",a,b);
	else if(a==9&&b==1) printf("9 10");
	else printf("-1");
}

