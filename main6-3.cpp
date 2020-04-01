#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main() {
	int i,s,e,sw1,sw2,o,temp;
	vector<vector<int> > line;
	vector<vector<int> >::iterator it;
	vector<int> tmp;
	int pair[]={0,0};
	int pair2[]={0,0};
		
	scanf("%d", &i);
	for (int j=0; j<i; j++){
		scanf("%d %d",&s,&e);
		pair[0]=s;
		pair[1]=e;
		copy(pair,pair+1,line.end());
	}
	for (it=line.begin(); it!=line.end(); it++){
		tmp=*it;
		pair[0]=tmp.front();
		pair[1]=tmp.back();
		tmp=*(it+1);
		pair2[0]=tmp.front();
		pair2[1]=tmp.back();
		if (pair2[0]<pair[0]||(pair2[0]==pair[0]&&pair2[1]<pair[1])){
			iter_swap(pair2,it);
			iter_swap(pair,it+1);
		}
	}
//	for (it=line.begin(); it!=line.end(); it++){
//		pair=*it;
//		pair2=*(it+1);
//		if (pair2[0]>=pair[0]&&pair2[1]<=pair[1]){
//			pair2[0]=0;
//			pair2[1]=0;
//			iter_swap(pair2,it);
//			iter_swap(pair,it+1);
//		}
//	}
	o=0;
	for (it=line.begin(); it!=line.end(); it++){
		//o+=*(it+1)-*it;
		tmp=*it;
		pair[0]=tmp.front();
		pair[1]=tmp.back();
		printf("%d %d ",pair[0], pair[1]);
	}
	printf("%d", o);
	return 0;
} 
