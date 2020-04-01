#include<stdio.h>
#include<iostream>
#include<cstdio>
#include <stdlib.h>

using namespace std;
int main()
{
	int n=0;
	char s[100];
	int ** d;
	char c;
	int i;
	cin>>n;
	d = new int*[n];
	while(n>0){
		d[n]=new int[20];
		i=0;
		while(gets(s)){
			c=getchar();		
			if (c==' ')
				d[n][i++]=atoi(s);							
			cout<<n<<"|"<<i<<"|"<<s<<"|"<<endl;
		}
		n--;
	}
	for (int p=0; p<n; p++){
		for (int q=0; q<20; q++){
			cout<<d[p][q]<<endl;
		}
	}
    return 0;
}
