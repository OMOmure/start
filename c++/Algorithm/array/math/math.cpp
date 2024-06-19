//注意题目给的要求：n要在1～100间，考虑过程的长度，如果n=27，有很长的长度

#include<iostream>
using namespace std;
int n,i=0,a[10];
int main()
{
    cin>>n;
    a[0]=n;
    while(a[i]!=1)
    {
    i++;
    if (a[i-1]%2==1) a[i]=a[i-1]*3+1;
    else a[i]=a[i-1]/2;
    }
    for ( int j = i; j >=0; j--)
    {
        cout<<a[j]<<" ";
    }
    return 0;
}