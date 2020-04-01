#include <iostream>
#include<vector>

using namespace std;

int main() {
	int i;
	vector<char> b(10000000,'0');
	vector<int>::iterator it;	
	int s,e;
	int u=0;
	
	//cin>>i;
	scanf("%d", &i);
	printf("%d\n",b.size());
	//while(cin>>s>>e){
	while(i-->0){
		scanf("%d %d",&s,&e);
		//it=b.begin()+s;
		char l[e-s]={'1'};
		b.erase(b.begin()+s,b.begin()+e-s);
		printf("%d %d\n",b.begin(),b.size());
		b.insert(b.begin()+s,l[0],l[e-s-1]);
		printf("%d %d\n",b.begin(),b.size());
//		for (int p=s; p<e; p++){
//			b[p]='1';
//		}
		//if (--i==0) break;
	}
	printf("%d\n",b.size());
	for (int j=0; j<b.size(); j++){
		u+=b[j]=='1'?1:0;	
	}
	printf("%d\n", u);
	return 0;
}
