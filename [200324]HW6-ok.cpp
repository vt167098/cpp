#include <iostream>
#include <map>
#include <iterator>
#include <queue>

using namespace std;
int main(int argc, char** argv) {
	int n,i;
	while(cin >> n){
		int id=1,num;
		string s1,s2;
		queue<string> q;
		queue<int> numof[n];
		queue<string> q_ani[n];
		map<string,int> has_place;
		map<string,int> has_animal[n];
		for(i=0;i<n;i++){
			cin >>  s1 >> num >> s2;
			int check=has_place[s2];
			if(!check){
				q.push(s2);
				has_place[s2]=id;
				q_ani[id].push(s1);
				has_animal[id][s1]+=num;
				id++;
			}
			else{
				int k=has_animal[check][s1];
				if(k)
					has_animal[check][s1]+=num;
				else{
					q_ani[check].push(s1);
					has_animal[check][s1]+=num;
				}
			}
		}
		while(q.size()){
			cout << q.front() << " : " ;
			int check=has_place[q.front()];
			while(q_ani[check].size()){
				if(q_ani[check].size()==1) cout << q_ani[check].front() << " " << has_animal[check][q_ani[check].front()] << endl;
				else cout << q_ani[check].front() << " " << has_animal[check][q_ani[check].front()] << ", ";
				q_ani[check].pop();
			}
			q.pop();
		}
	}
	return 0;
}
