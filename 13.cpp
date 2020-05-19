#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	long long int n,x,i,j,k;
	cin >> n;
	while(n--){
		cin >> k;
		int num[k],max[k][k],min[k][k],top=1;
		for(i=0;i<k;i++){
			cin >> num[i];
			//top*=num[i];
		}
		for(i=k-1;i>=0;i--)
			for(j=0;j<k;j++){
				int sum,sum2=0,maxi=0,mini;
				if(j-i<2){
					max[i][j]=0;
					min[i][j]=0;
					continue;
				}
				else if(j-i==2){
					max[i][j]=num[i]*num[i+1]*num[i+2];
					min[i][j]=num[i]*num[i+1]*num[i+2];
					continue;
				}
				else{
					for(x=i+1;x<j;x++){ //�ݭn�@��x�ܼơA��index���̫�~�nreduction���� 
						sum=max[i][x]+max[x][j]+num[i]*num[x]*num[j];
						sum2=min[i][x]+min[x][j]+num[i]*num[x]*num[j];
						if(x==i+1) mini=sum2;
						if(sum>maxi) maxi=sum;
						if(sum2<mini) mini=sum2;
					}
					max[i][j]=maxi;
					min[i][j]=mini;
				}
			}
		cout << max[0][k-1] << " " << min[0][k-1] << endl;
	}
	return 0;
}
