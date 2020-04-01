#include <iostream>
#include <vector>
#include<sstream>
#include <algorithm>

using namespace std;

int main() {
	vector<string> data;
	vector<vector<string> > rows;
	int i;	
	string data1, data2, data3, input, tmp;
	int qty;
	stringstream ss;
	
	getline(cin,input);
	ss<<input;
	ss>>i;
	
	for(int j=0;j<i;j++){
		getline(cin, input);
		tmp.clear();
		int l = 0;
		for (int k=0; k<input.size(); k++){
			tmp+=input[k];
			ss.clear();
			if (input[k]==' '){
				ss<<tmp;
				if (l==0){
					ss>>data1;
					data.push_back(data1);
					l++;
				} else if (l==1){
					ss>>data2;
					data.push_back(data2);
					l++;
				} else if (l==2){
					ss>>data3;
					data.push_back(data3);
					l++;
				}
				tmp.clear();
			}
		}
		ss.clear();
		ss<<tmp;
		ss>>data3;
		data.push_back(data3);
		rows.push_back(data);
		data.clear();		
	}
	//cout<<rows.size()<<endl;
	vector<vector<string> >::iterator it;
	it=rows.begin();
	data=*it;
	string place=data[2];
	string animal=data[0];
	int count = 0;
	bool place_not_found=false;
	bool animal_not_found=false;
	cout<<place<<":";
	while(!rows.empty()){
		cout<<"loop start"<<endl;
		for (it=rows.begin(); it!=rows.end(); it++){
			data=*it;
			//cout<<data[0]<<data[1]<<data[2]<<"|"<<place<<"|"<<animal<<"|";
			if (data[2]==place&&data[0]==animal){
				system("pause");
//				if (it!=rows.end()){
//					data=*it;
//				} else 
//				if (rows.empty()){
//					cout<<animal<<" "<<count;		
//				} else 
					ss.clear();
					ss<<data[1];
					ss>>qty;
					count+=qty;
					rows.erase(it);
					if (it!=rows.end()) 
						data=*it;
					cout<<rows.size()<<endl;
			} else if (animal!=data[0]&&animal_not_found){
				cout<<animal<<" "<<count<<",";
				animal=data[0];
				ss.clear();
				ss<<data[1];
				ss>>qty;
				count=qty;
				animal_not_found=false;
				place_not_found=false;
			}	
			
			if (it==rows.end()){
				if (animal_not_found)
					place_not_found=true;
				else	
					animal_not_found=true;
//				it=rows.begin();
//				data=*it;
				break;
			}

		}	
		animal_not_found = true;
		if (place!=data[2]&&place_not_found){
			place=data[2];
			cout<<animal<<" "<<count<<endl<<place<<":";
			animal=data[0];
			count=0;
			it=rows.begin();
			place_not_found=false;
			animal_not_found=false;
		}
 		
//				cout<<rows.size()<<" "<<count<<"|";
				//break;
//		for (int m=0; m<rows.size(); m++){
//			for (int n=0; n<rows[m].size(); n++){
//				cout<<rows[m][n]<<" ";
//	    	}
//	    	cout<<rows[m].size()<<endl;
//			rows.erase(rows.begin());
//			cout<<rows.size()<<endl;
//			system("pause");
//		}
		
	}	
	cout<<animal<<" "<<count;	
	return 0;
}
