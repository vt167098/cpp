#include <iostream>
#include <string.h>
#include <stdlib.h> 

using namespace std;

int* square(int x, int y, int w, int n){
    int x1,x2,x3,x4,y1,y2,y3,y4;
    static int l[2];

    x1 = x2 = x+w;
    x3 = x4 = x-w;
    y1 = y4 = y+w;
    y2 = y3 = y-w;
    
    if (n%2==0){    
        l[0] = (x1>0&&y1>0?x1:0)+(x2>0&&y2>0?x2:0)+(x3>0&&y3>0?x3:0)+(x4>0&&y4>0?x4:0);
        l[1] = (x1>0&&y1>0?y1:0)+(x2>0&&y2>0?y2:0)+(x3>0&&y3>0?y3:0)+(x4>0&&y4>0?y4:0);
    } else {
        l[0] = x;
        l[1] = y;
    }
    if (n>0){
        int *l0 = square(x1,y1,w/2,--n);
        l[0]+=l0[0];
        l[1]+=l0[1];
        l0 = square(x2,y2,w/2,--n);
        l[0]+=l0[0];
        l[1]+=l0[1];
        l0 = square(x3,y3,w/2,--n);
        l[0]+=l0[0];
        l[1]+=l0[1];
        l0 = square(x4,y4,w/2,--n);
        l[0]+=l0[0];
        l[1]+=l0[1];
    }
    return l;
}

int main(){
    int x,y,w,n;

    cin>>x>>y>>w>>n;
    int* s = square(x, y, w/2, n);

    cout<<s[0]<<" "<<s[1]<<endl;

    return 0;
}