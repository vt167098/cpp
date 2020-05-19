#include <iostream>
#include <stdlib.h>

using namespace std;

long double x_0,y_0;

int main() {
    int n, m;
	long double xa,ya,xb,yb,x,y;

    cin>>n;
    while(n--){
        cin>>xa>>ya>>xb>>yb;
        cin>>m;
        long long r1=0,r2=0,r3=0;
        while(m--){
            cin>>x>>y;
            long long x1,y1,x2,y2;
            x1=(x-xa)*(x-xa);
            y1=(x-xb)*(x-xb);
            r1=abs(x1*x1+y1*y1)>r1?abs(x1*x1+y1*y1):r1;
            r2=abs(x2*x2+y2*y2)>r2?abs(x2*x2+y2*y2):r2;
            r3=abs(x1*x1+y1*y1)>abs(x2*x2+y2*y2)
        }
    }
	return 0;
}
