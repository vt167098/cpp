#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define abs(x,y) (((x-y)>0)?x-y:y-x)
int main(int argc, char *argv[]) {
	long long int k,i,j;
	scanf("%d",&k);
	while(k--){
		int m,n;
		scanf("%d %d",&m,&n);
		long int graph[m][n],hor[m],ver[n];
		memset(graph,0,sizeof(graph));
		memset(ver,0,sizeof(ver));
		memset(hor,0,sizeof(hor));
		for(i=0;i<m;i++)
			for(j=0;j<n;j++){
				scanf("%d",&graph[i][j]);
				hor[i]+=graph[i][j];
				ver[j]+=graph[i][j];
			}
		long int min_row,min_col,min_r_id,min_c_id;
		for(i=0;i<m;i++){
			long int sum=0;
			for(j=0;j<m;j++) sum+=abs(i,j)*hor[j]*10;
			if(!i){
				min_row=sum;
				min_r_id=i;
			}
			if(sum<min_row){
				min_row=sum;
				min_r_id=i;
			}
		}
		for(i=0;i<n;i++){
			long int sum=0;
			for(j=0;j<n;j++) sum+=abs(i,j)*ver[j]*10;
			if(!i){
				min_col=sum;
				min_c_id=i;
			}
			if(sum<min_col){
				min_col=sum;
				min_c_id=i;
			}
		}
		printf("%ld %ld %ld\n",min_r_id+1,min_c_id+1,min_col+min_row);
	}
	return 0;
}
