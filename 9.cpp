#include <iostream>
#include <map>
#include <queue>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	map<string,long int> num;
	queue<string> q;
	queue<long int> pc;
	long int n,p,top=0,i,t=0;
	string s;
	while(cin >> s){
		if(s[0]=='0'){
			for(;q.size();q.pop(),pc.pop())
				if((q.front())[0]=='X')
					t+=(num[q.front()]/2+num[q.front()]%2)*pc.front();
				else if((q.front())[0]=='Y')
					t+=(num[q.front()]/2*1.5+num[q.front()]%2)*pc.front();
			num.clear();
			cout << t << endl;
			t=0;
			continue;
		}
		cin >> p >> n;
		if(!n) continue;
		if(s[0]!='X'&&s[0]!='Y'){
			t+=n*p;
			continue;
		}
		if(!num[s]){
			q.push(s);
			pc.push(p);
		}
		num[s]+=n;
	}
	return 0;
}
