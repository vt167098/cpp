#include <iostream>
#include <regex>
#include <map>
#include <algorithm>

using namespace std;

struct PO
{
    int price;
    int qty;
};

int main(){
    int total = 0;
    map<string, PO> item;
    map<string, PO>::iterator it;
    regex e ("^[A-Z]{1,1}\\d{9,9}$");
    int subtot, price, qty;
    string item_no;
    PO po;

    while(cin>>item_no&&regex_match(item_no,e)&&item_no!="0000000000"){
        cin>>price>>qty;
        it = item.find(item_no);
        if (it!=item.end()){
            po = item[item_no];
            po.qty+=qty;
            if (item_no.substr(0,1)=="Y"){
                if (qty/2>0){
                    po.price+=(qty/2)*1.5*price;
                } else {
                    po.price+=qty*price;
                }
            } else if (item_no.substr(0,1)=="X"){
                if (po.qty==1){
                    po.price=qty*price;
                } else {
                    po.price=(po.qty/2)*price+(po.qty%2)*price;
                }   
            } else {
                po.price+=qty*price;
            }
            item[item_no] = po;
        } else {
            po.qty = qty;
            if (item_no.substr(0,1)=="Y"){
                if (qty/2>0){
                    po.price=(qty/2)*1.5*price;
                } else {
                    po.price=qty*price;
                }
            } else if (item_no.substr(0,1)=="X"){
                if (qty==1){
                    po.price=qty*price;
                } else {
                    po.price=(qty/2)*price+(qty%2)*price;
                }   
            } else {
                po.price=qty*price;
            }
            item.insert(pair<string, PO>(item_no, po));
        }
    }

    for (it=item.begin(); it!=item.end(); it++){
        item_no = it->first;
        po = it->second;
        total+=po.price;
    }
    cout<<total<<endl;

    return 0;
}