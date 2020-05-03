#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int score[4]={0},top=0;
void hit(char (*s)[3],int t){
	int i;
	if(!strcmp(s[t],"1B")||!strcmp(s[t],"2B")||!strcmp(s[t],"3B")){
		if(!strcmp(s[t],"1B")){
			score[3]+=score[2];
			for(i=2;i>0;i--){
				score[i]=score[i-1];
				score[i-1]=0;
			}
			score[0]++;
		}
		else if(!strcmp(s[t],"2B")){
			score[3]+=score[1]+score[2]; score[1]=0; score[2]=0;
			score[2]+=score[0]; score[0]=0;
			score[1]++;
		}
		else if(!strcmp(s[t],"3B")){
			score[3]+=score[2]+score[0]+score[1];score[2]=0; score[0]=0; score[1]=0;
			score[2]++;
		}
		//printf("%d %d %d %d",score[0],score[1],score[2],score[3]);
	}
	else if(!strcmp(s[t],"HR")){
		score[3]++;
		for(i=2;i>=0;i--){
			score[3]+=score[i];
			score[i]=0;
		}
		//printf("%s ",s[t]);
		//printf("%d %d %d %d",score[0],score[1],score[2],score[3]);
	}
}
int main(int argc, char *argv[]) {
	int i,out,j,sum=0,k,m=0;
	char s[180][3];
	for(i=0;i<9;i++){
		int n;
		scanf("%d%*c",&n);
		for(j=0;j<n;j++,top++) scanf("%s*c",s[9*j+i]);
	}
	scanf("%d%*c",&out);
	for(i=0,j=0;(m*3+i)!=out&&j<top;j++){
		if(!strcmp(s[j],"FO")||!strcmp(s[j],"GO")||!strcmp(s[j],"SO")) i++;
		if(!(i%3)&&i!=0){
			//printf("%d\n",score[3]);
			for(k=0;k<=2;k++) score[k]=0;
			i=0;m++;
		}
		//printf("\n%s:",s[j]);
		hit(s,j);
	}
	printf("%d\n",score[3]);
	return 0;
}
