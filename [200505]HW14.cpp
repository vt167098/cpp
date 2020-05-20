#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    int n, m;
	long double xa,ya,xb,yb,x,y;

    while(true){
        cin>>n;
        while(n--){
            cin>>xa>>ya>>xb>>yb;
            cin>>m;
            long long r1=0,r2=0,r3=0,r4=0;

            while(m--){
                cin>>x>>y;
                long long x1,y1,x2,y2;
                //x1=(x-xa)*(x-xa);
                //y1=(y-ya)*(y-ya);
                //x2=(x-xb)*(x-xb);
                //y2=(y-yb)*(y-yb);
                r1=(x-xa)*(x-xa)+(y-ya)*(y-ya);//(x1+y1); //>r1?(x1+y1):r1;
                r2=(x-xb)*(x-xb)+(y-yb)*(y-yb);//(x2+y2); //>r2?(x2+y2):r2;
                if (r1<=r2){
                    r3=r3>r1?r3:r1;
                } else {
                    r4=r4>r2?r4:r2;
                }
            }
            cout<<endl<<r3+r4;
        }
    }
	return 0;
}
