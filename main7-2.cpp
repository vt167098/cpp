#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <set>
#include <math.h>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 100005
#define Mod 1000000007
using namespace std;
int main()
{
    int w,m,n;
    scanf("%d%d%d",&w,&m,&n);
    int x1=1,y1=1,cnt=1;
    while(cnt<m)
    {
        cnt++;
        if(y1%2)
        {
            x1++;
            if(x1>w)
            {
                x1=w;
                y1++;
            }
        }
        else
        {
            x1--;
            if(x1<1)
            {
                x1=1;
                y1++;
            }
        }
    }
    //cout<<x1<<" "<<y1<<endl;
    int x2=1,y2=1;
    cnt=1;
    while(cnt<n)
    {
        cnt++;
        if(y2%2)
        {
            x2++;
            if(x2>w)
            {
                x2=w;
                y2++;
            }
        }
        else
        {
            x2--;
            if(x2<1)
            {
                x2=1;
                y2++;
            }
        }
    }
    //cout<<x2<<" "<<y2<<endl;
    int ans=abs(x1-x2)+abs(y1-y2);
    cout<<ans;
    return 0;
}
