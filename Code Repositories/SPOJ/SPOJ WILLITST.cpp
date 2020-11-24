#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	scanf("%lld",&n);
	while(!(n&1)) n>>=1;
	puts(n>1?"NIE":"TAK");
}