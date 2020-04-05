#include <iostream>
#include <vector>
//#include <algorithm>

using namespace std;

int main() {
	struct Animals
	{
		string animal;
		int qty;
        string place;
	};
	struct Places
	{
		/* data */
		string place;
		vector<struct Animals> result;
	};
	vector<struct Places> data;
	
	int i;	
	struct Animals am;
	struct Places pl;
	
    while(cin>>i&&i>0&&i<=1000){
        for(int j=0;j<i;j++){
            while(cin>>am.animal){
                if (am.animal!=""){
                    break;
                }
            }
            while(cin>>am.qty&&am.qty>0&&am.qty<100){
                if (am.qty>0&&am.qty<100){
                    break;
                }
            }
            while(cin>>am.place){
                if (am.place!=""){
                    break;
                }
            }
            if (data.empty()){
                pl.place = am.place;
                pl.result.push_back(am);
                data.push_back(pl);
            } else {
                int ds = data.size();
                bool place_not_found = true;
                bool animal_not_found = true;
                for (int i=0; i<ds; i++){
                    if (data[i].place == am.place){
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
                            pl.place = am.place;
                            pl.result[0] = am;
                            data.push_back(pl);
                            animal_not_found = false;
                        }
                    }
                    if (animal_not_found && data[i].place == am.place){
                        data[i].result.push_back(am);
                        animal_not_found = false;
                    }
                }
            }
        }
        break;
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
	//cout<<endl;

	return 0;
}