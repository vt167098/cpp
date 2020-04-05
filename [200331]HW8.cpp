#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// void batter_display(vector<string> hit1){
// 	vector<string>::iterator it1;
// 	for (it1=hit1.begin();it1!=hit1.end();it1++){
// 		cout<<*it1<<" ";
// 	}
// 	cout<<endl;
// }

int main() {
	int score, b, inning, out, loop;
	vector< vector<string> > batter;
	vector< vector<string> >::iterator it;
	vector<string> hit;
    string input,input2;
    int base[4]={0,0,0,0};
    bool inning1;
    
    stringstream ss;

	for (int i=0; i<9; i++){
    	getline(cin, input);
		int k=input.size();
		for (int j=0; j<k; j++){
			if (input[j]==' '){
				hit.push_back(input2);
				input2.clear();
			} else {
				input2+=input[j];
			}
		}
		hit.push_back(input2);
		batter.push_back(hit);
		hit.clear();
		input2.clear();
	}
	inning=1;
	loop=1;
	b=0;
	out=0;
	score=0;
	inning1=false;
	 
	it=batter.begin();
	cin>>b;
	while(out<b){
		if (it==batter.end()){ 
			it=batter.begin();
			loop++;
		} 
		hit=*it;
		//batter_display(hit);
		if (hit[loop]=="1B"){
			base[3]+=base[2]==1&&base[1]==1&&base[0]==1?1:0;
			base[2]=base[1]==1?1:base[2];
			base[1]=base[0]==1?1:base[1];
			base[0]=1;
		} else if (hit[loop]=="2B"){
			base[3]+=base[2]==1||base[1]==1?(base[2]+base[1]):0;
			base[2]=base[0]==1?1:base[2];
			base[1]=1;
			base[0]=0;
		} else if (hit[loop]=="3B"){
			base[3]+=base[2]==1||base[1]==1||base[0]==1?(base[2]+base[1]+base[0]):0;
			base[2]=1;
			base[1]=0;
			base[0]=0;
		} else if (hit[loop]=="HR"){
			base[3]+=base[2]==1||base[1]==1||base[0]==1?(base[2]+base[1]+base[0]+1):1;
			base[2]=0;
			base[1]=0;
			base[0]=0;
		} else if (hit[loop]=="FO"||hit[loop]=="GO"||hit[loop]=="SO"){
			out++;
			//inning1=inning1?false:inning1;
		} 
		score+=base[3];
		base[3]=0;
		it++;
		if (out%3==0 && out!=0){
			base[0]=0;base[1]=0;base[2]=0;base[3]=0;
			inning++;
			//inning1=true;
		}
	}
	cout<<score<<endl;
	return 0;

}
