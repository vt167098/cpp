#include <iostream>
#include <regex>
#include <vector>
#include <algorithm>

using namespace std;

struct Product
{
    string item_no;
    int price;
    int qty;
};

bool sort_itemno (Product i,Product j) { return (i.item_no<j.item_no); }

int main(){
    int total = 0;
    struct Product prod, old_prod;
    vector <Product> prods;
    regex e ("^[A-Z]{1,1}\\d{9,9}$");
    int subtot, qtys;

    while(cin>>prod.item_no&&regex_match(prod.item_no,e)&&prod.item_no!="0000000000"){
        cin>>prod.price>>prod.qty;
        prods.push_back(prod);
    }
    sort(prods.begin(), prods.end(), sort_itemno);
    for (vector <Product>::iterator it=prods.begin(); it!=prods.end(); it++){
        prod =*it;
        if (it==prods.begin()){
            old_prod=prod;
            subtot = 0;
            qtys = 0;
        }
        if (old_prod.item_no!=prod.item_no){
            if (old_prod.item_no.substr(0,1)=="X"){
                subtot=((qtys/2)+(qtys%2))*old_prod.price;
            }
            total+=subtot;
            old_prod = prod;
            subtot = 0;
            qtys = 0;
        }
        if (prod.item_no.substr(0,1)=="Y"){
            if (prod.qty/2>0){
                subtot+=(prod.qty/2)*1.5*prod.price;
            } else {
                subtot+=prod.qty*prod.price;
            }
        } else if (prod.item_no.substr(0,1)=="X"){
            qtys+=prod.qty;    
        } else {
            subtot+=prod.qty*prod.price;
        }
    }
    if (old_prod.item_no.substr(0,1)=="X"){
        subtot=((qtys/2)+(qtys%2))*old_prod.price;
    }
    total+=subtot;
    cout<<total<<endl;

    return 0;
}