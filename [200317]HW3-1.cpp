#include <iostream>
#include<bitset>

using namespace std;

int main() {
	int i;
	bitset<10000000> b;	
	int s,e;
	int u=0;
	
	scanf("%d", &i);
	
	while(i-->0){
		scanf("%d %d",&s, &e);
		for (int p=s; p<e; p++){
			b.set(p);
		}
	}
//	for (int j=0; j<1000; j++){
//		u+=a[j]?1:0;	
//	}
	printf("%d\n",b.count());
	return 0;
}
