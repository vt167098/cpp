#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
unsigned int ones;
int check(unsigned int n){
	unsigned long int bit=0;
	while(n){
		bit+=n%2;
		n/=2;
	}
	return bit==ones;
}
int main(int argc, char *argv[]) {
	unsigned long int n;
	unsigned long int i,j;
	while(scanf("%u",&n),n){
		ones=0;
		unsigned long int k=n;
		while(k){
			ones+=k%2;
			k/=2;
		}
		for(j=n;j>1;j--){
			if(!check(j)) continue;
			for(i=2;i*i<=j&&(j%i);i++);
			if(i*i<=j) continue;
			printf("%u\n",j);
			break;
		}
		if(j==1) printf("%d\n",0);
	}
	return 0;
}
