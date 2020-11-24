#include <math.h>
#include <stdio.h>
#define ll long long
ll n,m;
using namespace std;
const double eps=1e-3;
bool dcmp(double x,double y){return fabs(x-y)<eps;}
int main(){
	while(~scanf("%lld%lld",&n,&m)&&(n||m)){
		ll delta=n*n-4*m;
		if(delta<0){
			printf("No\n");
			continue;
		}
		double sdelta=sqrt((double)delta);
		int a=sdelta-1;
		bool flag=false;
		while(a<0||a*a<=delta)
		{
			if(a*a==delta) flag=true;
			a++;							
		}
		puts(flag?"Yes":"No");
	}
}
