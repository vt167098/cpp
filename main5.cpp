#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,i;
	scanf("%d%*c",&n);
	while(n--){
		char s[1001];
		int num[1000]={0},k=0,max=0,ans=0;
		scanf("%[^\r]%*c",s);
		for(i=0;i<strlen(s);i++){
			if(isdigit(s[i])) num[k]=10*num[k]+s[i]-'0';
			else if(s[i]==' ') k++;
			if(max<num[k]) max=num[k];
		}
		if(max<95) for(i=0;i<=k;i++) num[i]+=95-max;
		for(i=0;i<=k;i++) if(num[i]>=55&&num[i]<=59) ans++;
		printf("%d\n",ans);
	}
	return 0;
}

