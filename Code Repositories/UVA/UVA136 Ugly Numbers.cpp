#include<cstdio>
#include<set>
#define ll long long
using namespace std;
int main()
{
	set<ll>s;
	int cnt=1;
	s.insert(1LL);
	while(cnt<1500)
	{
		ll cur=*s.begin();
		s.insert(cur*2);
		s.insert(cur*3);
		s.insert(cur*5);
		s.erase(cur),cnt++;
	}
	printf("The 1500'th ugly number is %lld.\n",*s.begin());
}