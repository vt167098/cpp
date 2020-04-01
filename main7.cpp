#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

int distance(int p1, int r1, int q1, int s1){
	int x1 = abs(p1-r1)*10;
	int y1 = abs(q1-s1)*10;
	return x1+y1;
}

int main() {
	int i,x,y;
	int u=0;
	stringstream ss;
	string input;
	int num;
	string num_s;
	
	scanf("%d", &i);
	scanf("%d %d", &x, &y);	
	getline(cin, input);
	int g[x][y];
	int *a = new int[3]();
	
	for (int i0=0; i0<i; i0++){ 
		for (int x0=0; x0<x; x0++){
			int y0=0;
			getline(cin, input);
			for (int j=0; j<input.size(); j++){
				num_s+=input[j];
				if (input[j]==' '){
					ss.clear();
					ss<<num_s;
					ss>>num;
					g[x0][y0++]=num<=1000?num:1000;
					num_s.clear();
				}
			}
			ss<<num_s;
			ss>>num;
			g[x0][y0++]=num<=1000?num:1000;
			num_s.clear();
			//printf("%d\n", x0);
		}
	
		for (int p=0; p<x; p++){
			for (int q=0; q<y; q++){
				for (int r=0; r<x; r++){
					for (int s=0; s<y; s++){
						num+=distance(p,r,q,s)*g[r][s];
					}
				}
				if (a[2]==0||a[2]>num){
					a[0]=p;
					a[1]=q;
					a[2]=num;
				}
				//cout<<p+1<<","<<q+1<<"="<<a[2]<<endl;	
				num=0;			
			}
		}
		cout<<a[0]+1<<" "<<a[1]+1<<" "<<a[2]<<endl;	
	} 
	return 0;
}

