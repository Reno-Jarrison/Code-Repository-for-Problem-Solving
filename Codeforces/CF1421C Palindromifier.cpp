#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int main()
{
	scanf("%s",s);
	int n=strlen(s);
	puts("3");
	printf("R %d\n",n-1);
	printf("L %d\n",n);
	puts("L 2");
}