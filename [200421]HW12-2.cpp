#include <iostream>

using namespace std;

long double x_0,y_0;

void coordinate(long double x,long double y,long double w,long int n){
	if(x>0&&y>0){
		x_0+=x;
		y_0+=y;
	}
	if(n<0) return;
	coordinate(x+w,y+w,w/2,n-1);
	coordinate(x+w,y-w,w/2,n-1);
	coordinate(x-w,y+w,w/2,n-1);
	coordinate(x-w,y-w,w/2,n-1);
}
int main() {
	long double x,y,w,n;
	//long int x;
	while(cin >> x >> y >> w >> n){
		x_0=0;y_0=0;
		coordinate(x,y,w/2,n);
		cout << x_0 <<" "<< y_0 << endl;
	}
	return 0;
}
