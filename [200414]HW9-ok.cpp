#include<bits/stdc++.h>

using namespace std;

struct data {
	string name;
	long int price;
	long int num;
};

int main(void) {
	string name;
	long int price, num, sum(0);
	vector<data> list;
	map<string, long int> mMap;//<name, key>
	while(cin >> name) {
		if(name[0] == '0') {
			for(long int i = 0; i < list.size(); ++i) {//開始算總價 
				if(list[i].name[0] == 'X') {
					++list[i].num;
					sum += list[i].price * (list[i].num / 2);
				}
				else if(list[i].name[0] == 'Y') {
					sum += list[i].price * 1.5 * (list[i].num / 2);
					if(list[i].num & 1)
						sum += list[i].price;
				}
				else
					sum += list[i].price * list[i].num;
			}
			cout << sum << endl;
			list.clear();
			mMap.clear();
			sum = 0;
			continue;
		}
		cin >> price >> num;
		if(mMap.find(name) == mMap.end()) {//沒買過的商品
			mMap[name] = list.size();
			list.push_back({name, price, num});
		}
		else
			list[mMap[name]].num += num;
	}
	return 0;
}
