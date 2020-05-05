#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int ans,n,total,bit;
void permutation(char s[],int count,int num){
	if(total<strlen(s)||num>n||bit<count) return;
	if(bit==count){
		int i;
		for(i=2;i*i<=num&&(num%i);i++);
		if(i*i>num)	if(num>ans) ans=num;
		char a[10000];
		strcpy(a,s);
		strcat(a,"0");
		permutation(a,count,num*2);
		return;
	}
	char a[10000],b[10000];
	strcpy(a,s);
	strcat(a,"0");
	strcpy(b,s);
	strcat(b,"1");
	permutation(a,count,num*2);
	permutation(b,count+1,num*2+1);
}
int main(int argc, char *argv[]) {
	while(scanf("%d",&n),n){
		int count=0,num=0,k=n;
		ans=0;total=0;bit=0;
		while(k){
			bit+=k%2;
			k/=2;
			total++;
		}
		permutation("",count,num);
		printf("%d\n",ans);
	}
	return 0;
}
