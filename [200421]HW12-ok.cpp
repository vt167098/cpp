#include <iostream>
using namespace std;
long double s_x,s_y;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void point(long double x,long double y,long double offset,long int times){
	if(times==-2) return;
	else if(x>0&&y>0){
		s_x+=x;
		s_y+=y;
	}
	point(x+offset,y+offset,offset/2,times-1);
	point(x+offset,y-offset,offset/2,times-1);
	point(x-offset,y+offset,offset/2,times-1);
	point(x-offset,y-offset,offset/2,times-1);
}
int main(int argc, char** argv) {
	long double a,b,d,offset;
	long int x;
	while(cin >> a >> b >> d >> x){
		offset=d/2;
		s_x=0;s_y=0;
		point(a,b,offset,x);
		if(a>0&&b>0){
			s_x-=a;
			s_y-=b;
		} 
		cout << s_x <<" "<< s_y << endl;
	}
	return 0;
}
