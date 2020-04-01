#include<iostream>
//#include<string>
#include<vector>
#include<sstream>

using namespace std;

int main()
{
    int num;
    int n;
    vector<int> nums;
    bool scoreadd=true;
    int scoremax = 0;
    int s_add= 0 ;
    string input;
    
    stringstream ss;

    getline(cin, input);
    ss<<input;
	ss>>n;
	
	int *exam = new int[n]();
	for (int i=0; i<n; i++){
		string score_s;
		int score_i;
		getline(cin, input);
		for (int j=0; j<input.size(); j++){
			score_s+=input[j];
			if (input[j]==' '){
				ss.clear();
				ss<<score_s;
				ss>>score_i;
				scoremax=score_i>=scoremax?score_i:scoremax;
				nums.push_back(score_i);
				score_s.clear();
			}
		}
		ss.clear();
		ss<<score_s;
		ss>>score_i;
		scoremax=score_i>=scoremax?score_i:scoremax;
		nums.push_back(score_i);
		//score_s.clear();
		s_add=scoremax>95?0:(95-scoremax);
		for (int k=0; k<nums.size(); k++){
			exam[i]+=(nums[k]+s_add)>=55&&(nums[k]+s_add)<=59?1:0; 
			//cout<<(nums[k]+s_add)<<" ";
		}
		nums.clear();
		scoremax=0;
		//cout<<endl;
	}
	for (int i=0; i<n; i++){
		cout<<exam[i]<<endl; 
	}

    return 0;
}
