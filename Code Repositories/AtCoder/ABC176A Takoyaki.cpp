#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,t;
	scanf("%d%d%d",&n,&x,&t);
	printf("%d\n",(n/x+(n%x>0))*t);
}