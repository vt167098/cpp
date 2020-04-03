#include <iostream>
#include <vector>
#include<sstream>
#include <algorithm>

using namespace std;

int main() {
	struct Animals
	{
		string animal;
		int qty;
	};
	struct Places
	{
		/* data */
		string place;
		vector<struct Animals> result;
	};
	vector<struct Places> data;
	
	int i;	
	string data1, data3, input, tmp;
	int data2;
	int qty;
	stringstream ss;
	struct Animals am;
	struct Places pl;
	
	getline(cin,input);
	ss<<input;
	ss>>i;
	
	for(int j=0;j<i&&j<1000;j++){
		getline(cin, input);
		tmp.clear();
		int l = 0;
		for (int k=0; k<input.size(); k++){
			if (input[k]==' '){
				ss.clear();
				ss<<tmp;
				if (l==0){
					ss>>am.animal;
					l++;
				} else if (l==1){
					ss>>am.qty;
					l++;
				} else if (l==2){
					ss>>pl.place;
					if (data.empty()){
						pl.result.push_back(am);
						data.push_back(pl);
					} else {
						int ds = data.size();
                        bool place_not_found = true;
						bool animal_not_found = true;
						for (int i=0; i<ds; i++){
							if (data[i].place == pl.place){
                                place_not_found = false;
								int rs=data[i].result.size();
								for (int j=0; j<rs; j++){
									if (data[i].result[j].animal == am.animal){
										data[i].result[j].qty += am.qty;
										animal_not_found = false;
									}
								}
							}
                            if (i==ds-1){	
                                if (place_not_found && animal_not_found){
                                    pl.result[0] = am;
                                    data.push_back(pl);
                                    animal_not_found = false;
                                }
                            }
                            if (animal_not_found && data[i].place == pl.place){
                                data[i].result.push_back(am);
                                animal_not_found = false;
                            }
						}
					}
					l++;
				}
				tmp.clear();
			} else {
				tmp+=input[k];
			}
		}
	}
	ss>>pl.place;
	if (data.empty()){
		pl.result.push_back(am);
		data.push_back(pl);
	} else {
		int ds = data.size();
		bool animal_not_found=true;
		for (int i=0; i<ds; i++){
			if (data[i].place==pl.place){
				int rs=data[i].result.size();
				for (int j=0; j<rs; j++){
					if (data[i].result[j].animal==am.animal){
						data[i].result[j].qty+=am.qty;
						animal_not_found=false;
					}
				}
			}	
		}
		if (animal_not_found){
			pl.result.push_back(am);
			data.push_back(pl);
		}
	}
	//cout<<rows.size()<<endl;

    for (vector<struct Places>::iterator it=data.begin(); it!=data.end(); it++){
        pl=*it;
        cout<<pl.place<<":";
        for (vector<struct Animals>::iterator it1=pl.result.begin(); it1!=pl.result.end(); it1++){
            am=*it1;
            cout<<am.animal<<" "<<am.qty;
            if (pl.result.end()!=it1+1)
                cout<<", ";
        }
        cout<<endl;
    }
	cout<<endl;
	return 0;
}
