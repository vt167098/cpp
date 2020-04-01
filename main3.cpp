#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <time.h>

using namespace std;
 
int main()
{	
	double start, end;
	int n,m,k,s,l;
	vector<int> ss;
	vector<int>::iterator it;
	
	cin>>n>>m>>k;

	start = clock();
	for (int i=0; i<n; i++)
		ss.push_back(i+1);
		
	l=0;
	s=1;
	do
	{
		for (it=ss.begin(); it!=ss.end(); it++){
			if (s%m==0){
				//cout<<"boom:"<<*it<<"|"<<ss.size()<<endl;
				it = ss.erase(it);
				if (it==ss.end())
					it=ss.begin();
				l++;
				s=1;           
			} 
			s++;
			if (l>=k){
				break;
			}
		}
	}    
	while(l<k);	
	cout<<"lucky man:"<<*it<<"|"<<ss.size()<<endl;
//	for (it=ss.begin(); it!=ss.end(); ++it){
//		cout<<*it<<endl;
//	}
	end = clock();
	cout << "execute time:"<< (end - start) / CLOCKS_PER_SEC << endl; 
	return 0;
}
