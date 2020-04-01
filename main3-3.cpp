#include <stdio.h>
int Josephus(int n,int m,int k)/*計算約瑟夫環問題的迭代法函式*/
{
	int i;
	int x,y;
	if(n<=1||m<=1)
		return -1;
	if(m%2==0)
		y=1;
	else
		y=2;
	for(i=3;i<=n;i++)
	{
		x=(y-1+m)%i+1;
		y=x;
	}
	return y;
}

int main()
{
	int n,m,x,k;
	scanf("%d %d %d",&n,&m,&k);
	x=Josephus(n,m,k);
	printf("最後一個的編號是： %d\n",x);
	return 0;
}
