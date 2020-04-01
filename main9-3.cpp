#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

    map<string, string> map1;
    map<string, int> map2;
    map<string, string>::iterator it1;
    map<string, int>::iterator it2;
    map<string, string>::reverse_iterator it_r1;
    map<string, int>::reverse_iterator it_r2;
	string data1, data3, input;
	int data2;
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
					l++;
				} else if (l==1){
					ss>>data2;
					l++;
				} else if (l==2){
					ss>>data3;
					l++;
				}
				tmp.clear();
			}
		}
		ss.clear();
		ss<<tmp;
		ss>>data3;
	    map1.insert(pair<string, string>(data3, data1));
	    map2.insert(pair<string, int>(data1, data2));
	}

	while(!map1.empty()){
    	it = map1.begin();
    	cout<<it->first<<":";
	    for(it = map1.begin(); it != map1.end(); it++){
	    	
		}
	                cout<<iter->first<<" "<<iter->second<<endl;
//    for(iter_r = mapStudent.rbegin(); iter_r != mapStudent.rend(); iter_r++)
//                cout<<iter_r->first<<" "<<iter_r->second<<endl;

    //find and erase the element
    iter = mapStudent.find("r123");
    mapStudent.erase(iter);

    iter = mapStudent.find("r123");

    if(iter != mapStudent.end())
       cout<<"Find, the value is "<<iter->second<<endl;
    else
       cout<<"Do not Find"<<endl;
	}

    return 0;
}
