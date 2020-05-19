#include <iostream>

using namespace std;
long double x_0, y_0;

void runSquare(long double x, long double y, long double w, long double n){
	//cout<<endl<<n<<" "<<w<<" "<<s0.x0<<" "<<s0.y0<<" "<<x<<" "<<y;
	if (x>0&&y>0){
		x_0+=x;
		y_0+=y;
	}
	if (n<0) return;
	runSquare(x+w,y+w,w/2,n-1);
	runSquare(x+w,y-w,w/2,n-1);
	runSquare(x-w,y-w,w/2,n-1);
	runSquare(x-w,y+w,w/2,n-1);
	//cout<<"|"<<q.x0<<" "<<q.y0;
}

int main(){
    long double x,y,w,n;

    while (cin>>x>>y>>w>>n){
		x_0=0;
		y_0=0;
		//while(n>0){
			runSquare(x, y, w/2, n);
			//n--; 
		//}
		//cout<<endl;
		cout<<x_0<<" "<<y_0<<endl;
	}
    return 0;
}
