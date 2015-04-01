// This problem is bugged!
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int b[1001];
int h[1001];
int maxx=0;
int main()
{
    int m,n,t;
    while(cin>>m)
    {
        maxx=0; cin>>n;
     memset(b,0,sizeof(b));memset(h,0,sizeof(h));
        while(m--)
        { 
            for(int i=0;i<n;i++)
            {
                scanf("%d",&t);
                if(t==0)b[i]=0;
                if(t==1)b[i]++;
                if(b[i]!=0 && h[b[i]]==0)h[b[i]]=1;
            }
            for(int i=0;i<n;)
            {
                if(b[i]==0||h[b[i]]!=1){i++;continue;}
                h[b[i]]=0;
                int k=b[i]; int sum=0;
                for(int j=0;j<n;j++)
                {
                    if(b[j]>=k)  sum = sum+k;
                    else sum=0;
                    if(sum>maxx)maxx = sum;
                      
                }
                i++;
            }
        }
        cout<<maxx<<endl;
    }
    return 0;
}
  
/**************************************************************
    Problem: 1497
    User: uniquecx
    Language: C++
    Result: Accepted
    Time:410 ms
    Memory:1528 kb
****************************************************************/