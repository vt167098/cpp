#include <iostream>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
typedef struct{
	int w,f;
}element;
bool compare(element a,element b){
	return a.w*b.f<a.f*b.w;
}
int main(int argc, char** argv) {
	int n,i,j;
	while(cin >> n){
		element store[n];
		long int sum=0;
		for(i=0;i<n;i++) cin >> store[i].w;
		for(i=0;i<n;i++) cin >> store[i].f;
		sort(store,store+n,compare);
		long int temp=0;
		for(i=1;i<n;i++){
			temp+=store[i-1].w;
			sum+=temp*store[i].f;
		}
		cout << sum << endl;
	}
	return 0;
}
