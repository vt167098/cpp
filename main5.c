#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Lucky(int N,int M,int K){
	if(K==1) return M%N;
	return (Lucky(N-1,M,K-1)+M)%N;
}
int main(int argc, char *argv[]) {
	int N,M,K,i;
	while(scanf("%d %d %d",&N,&M,&K)==3){
		int tag=Lucky(N,M,K);
		printf("%d\n",tag+1);
	}
	return 0;
}

