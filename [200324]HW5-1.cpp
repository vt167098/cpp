#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector< vector<int> > matrix_2d;
vector<int> matrix;

void display_matrix(){
    cout<<matrix_2d.size()<<" "<<matrix_2d[0].size()<<endl;
	for (int i=0; i<matrix_2d.size(); i++){
		matrix = matrix_2d[i];
		for (int j=0; j<matrix.size(); j++){
			cout<<matrix[j];
			if (j==matrix.size()-1)
				cout<<endl;
			else
				cout<<" ";
		}
		
	}
}

void rotate_matrix(){
	vector< vector<int> >matrix_2d_t;
	vector<int>matrix_t;

	for (int i=matrix_2d.size()-1; i>=0; i--){
		for (int j=0; j<matrix_2d[i].size(); j++){
			if (matrix_2d_t.empty()||i==matrix_2d.size()-1){
				matrix_t.clear();
				matrix_t.push_back(matrix_2d[i][j]);
				matrix_2d_t.push_back(matrix_t);
			} else {
				matrix_2d_t[j].push_back(matrix_2d[i][j]);
			}
		}
	}
	matrix_2d.clear();
	for (vector< vector<int> >::iterator it=matrix_2d_t.begin(); it!=matrix_2d_t.end(); it++){
		matrix_2d.push_back(*it);
	}
}

void mirror_matrix(){
	// vector<int>matrix_t;
	// for (vector< vector<int> >::iterator it=matrix_2d.begin(); it!=matrix_2d.end(); it++){
	// 	matrix_t=*it;
	// 	reverse(matrix_t.begin(), matrix_t.end());
	// 	swap(matrix_t, *it);		
	// }
	reverse(matrix_2d.begin(),matrix_2d.end());
}

int main() {
	int r,c,n;
	stringstream ss;
	string input;
    string num_s;
    int num;
	int i =0;
	int c0=0;
	vector<int> act;

	while (cin>>r>>c>>n&&r>0&&r<11&&c>0&&c<11&&n>0&&n<11)
	{
		while (i<r){
			c0=0;
			getline(cin, input);
			for (int j=0; j<input.size(); j++){
				num_s+=input[j];
				if (input[j]==' '){
					ss.clear();
					ss<<num_s;
					ss>>num;
					matrix.push_back(num);
					num_s.clear();
					if (++c0>=c)
						break;
				}
			}
			ss.clear();
			ss<<num_s;
			ss>>num;
			if (c0>0){
				matrix.push_back(num);
				num_s.clear();
				matrix_2d.push_back(matrix);
				matrix.clear();
				i++;
			}
		}
		c0=0;
		getline(cin, input);
		for (int j=0; j<input.size(); j++){
			num_s+=input[j];
			if (input[j]==' '){
				ss.clear();
				ss<<num_s;
				ss>>num;
				act.push_back(num);
				num_s.clear();
				if (++c0>=n)
					break;
			}
		}
		ss.clear();
		ss<<num_s;
		ss>>num;
		act.push_back(num);

		for (int k=0; k<act.size(); k++){
			if (act[k]==0){
				rotate_matrix();
				//display_matrix();
			} else if (act[k]==1){	
				mirror_matrix();
				//display_matrix();
			}
		}
		display_matrix();
		break;
	}
	
	return 0;
}
