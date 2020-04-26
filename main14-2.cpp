#include <iostream>
#include <string.h>
#include <stdlib.h> 

using namespace std;
struct Square
{
    int x0, y0;
};

Square runSquare1(int x, int y, int w, int n, Square s0){
    if (n>0){
        s0.x0 += (x+w/2)>0&&(y+w/2)>0?(x+w/2):0;
        s0.y0 += (x+w/2)>0&&(y+w/2)>0?(y+w/2):0;
        return runSquare1(x+w/2, y+w/2, w/2, --n, s0);   
    } else {
        s0.x0 += (x>0&&y>0?x:0);
        s0.y0 += (x>0&&y>0?y:0);
        return s0;
    }
}

Square runSquare2(int x, int y, int w, int n, Square s0){
    if (n>0){
        s0.x0 += (x+w/2)>0&&(y-w/2)>0?(x+w/2):0;
        s0.y0 += (x+w/2)>0&&(y-w/2)>0?(y-w/2):0;
        return runSquare2(x+w/2, y-w/2, w/2, --n, s0);   
    } else {
        s0.x0 += (x>0&&y>0?x:0);
        s0.y0 += (x>0&&y>0?y:0);
        return s0;
    }
}

Square runSquare3(int x, int y, int w, int n, Square s0){
    if (n>0){
        s0.x0 += (x-w/2)>0&&(y-w/2)>0?(x-w/2):0;
        s0.y0 += (x-w/2)>0&&(y-w/2)>0?(y-w/2):0;
        return runSquare2(x-w/2, y-w/2, w/2, --n, s0);   
    } else {
        s0.x0 += (x>0&&y>0?x:0);
        s0.y0 += (x>0&&y>0?y:0);
        return s0;
    }
}

Square runSquare4(int x, int y, int w, int n, Square s0){
    if (n>0){
        s0.x0 += (x-w/2)>0&&(y+w/2)>0?(x-w/2):0;
        s0.y0 += (x-w/2)>0&&(y+w/2)>0?(y+w/2):0;
        return runSquare4(x-w/2, y+w/2, w/2, --n, s0);   
    } else {
        s0.x0 += (x>0&&y>0?x:0);
        s0.y0 += (x>0&&y>0?y:0);
        return s0;
    }
}

int main(){
    int x,y,w,n;
    Square s,s1,s2,s3,s4;

    cin>>x>>y>>w>>n;
    s1.x0=0;
    s1.y0=0;
    s1 = runSquare1(x+w/2, y+w/2, w/2, n, s1);
    s2.x0=0;
    s2.y0=0;
    s2 = runSquare2(x+w/2, y-w/2, w/2, n, s2);
    s3.x0=0;
    s3.y0=0;
    s3 = runSquare3(x-w/2, y-w/2, w/2, n, s3);
    s4.x0=0;
    s4.y0=0;
    s4 = runSquare4(x-w/2, y+w/2, w/2, n, s4);

    s.x0 = s1.x0+s2.x0+s3.x0+s4.x0;
    s.y0 = s1.y0+s2.y0+s3.y0+s4.y0;

    cout<<s.x0<<" "<<s.y0<<endl;

    return 0;
}