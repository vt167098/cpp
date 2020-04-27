#include <iostream>
#include <string.h>
#include <stdlib.h> 

using namespace std;
struct Square
{
    int x0, y0;
};

Square runSquare(int x, int y, int w, int n, Square s0){
	Square q; 
	//cout<<endl<<n<<" "<<w<<" "<<s0.x0<<" "<<s0.y0<<" "<<x<<" "<<y;
   	for (int i=0; i<4; i++){
   		//cout<<n<<" "<<i<<" "<<s0.x0<<" "<<s0.y0<<" "<<x<<" "<<y<<endl;
   		if (i==0){
   			q.x0 = x+w/2;
   			q.y0 = y+w/2;
		} else if (i==1){
   			q.x0 = x+w/2;
   			q.y0 = y-w/2;
		} else if (i==2){
   			q.x0 = x-w/2;
   			q.y0 = y-w/2;
		} else if (i==3){
   			q.x0 = x-w/2;
   			q.y0 = y+w/2;
		}

        s0.x0 += q.x0>0&&q.y0>0?q.x0:0;
        s0.y0 += q.x0>0&&q.y0>0?q.y0:0;

        if (n>0){ 
        	s0 = runSquare(q.x0, q.y0, w/2, n-1, s0);   
		}
 
	}
	//cout<<"|"<<q.x0<<" "<<q.y0;
    return s0;
}

int main(){
    int x,y,w,n;
    Square s;

    cin>>x>>y>>w>>n;
    s.x0=0;
    s.y0=0;
    while(n>0){
	    s = runSquare(x, y, w, n, s);
	    n--; 
	}
	//cout<<endl;
    cout<<s.x0<<" "<<s.y0<<endl;

    return 0;
}
