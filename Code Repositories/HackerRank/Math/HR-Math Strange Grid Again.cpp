#include<iostream>
using namespace std;
int main()
{
    long long r,c;
    cin>>r>>c,r--,c--;
    cout<<r/2*10+c*2+(r&1);
}