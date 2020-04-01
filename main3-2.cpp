#include <stdio.h>
int Josephus(int n,int m,int k){
	//printf("%d % d %d %d\n",n,m,k,(m+n-1));
    if(n>1&&k>0){
      return (m+Josephus(n-1,m,--k))%n;
    }
    else{
        return 0;
    }
}
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int result=Josephus(n,m,k);
    printf("%d",result+1);
 
    return 0;
}
