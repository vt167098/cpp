#include <iostream>
#include <vector>
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
    int num;
	int i =0;
	int c0=0;
	vector<int> act;

	while (cin>>r>>c>>n&&r>=1&&r<=10&&c>=1&&c<=10&&n>=1&&n<=10)
	{
		while (i<r){
			c0=0;
            while(cin>>num&&num>=0&&num<=9){
                if (num>=0&&num<=9){
                    matrix.push_back(num);
                    if (++c0>=c)
                        break;
                }
            }
			if (c0>0){
				matrix_2d.push_back(matrix);
				matrix.clear();
				i++;
			}
		}
		i=0;
		while (i<n){
			c0=0;
            while(cin>>num&&num>=0&&num<=1){
                if (num>=0&&num<=1){
                    act.push_back(num);
                    if (++i>=n)
                        break;
                }
            }
		}

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
