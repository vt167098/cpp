#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n,m;
    while (cin>>n>>m){
        int *x=new int[m];
        int *y=new int[m];
        vector< vector<int>> c;
        vector< vector<int>>::iterator it;
        for (int i=0; i<m; i++){
            cin>>x[i]>>y[i];
        }    
        for (int i=0; i<m; i++){
            bool next=false;
            for (it=c.begin(); it!=c.end(); it++){
                vector<int> c0 = *it;
                vector<int>::iterator it0;
                it0=find(c0.begin(), c0.end(), x[i]);
                if (it0==c0.end()){
                    it0=find(c0.begin(), c0.end(), y[i]);
                    if (it0==c0.end()){
                        vector<int> c1;
                        c1.push_back(x[i]);
                        c1.push_back(y[i]);
                        c.push_back(c1);        
                    } else {
                        c0.push_back(y[i]);
                        c.erase(it);
                        c.push_back(c0);
                    }
                    next=true;
                    break;
                } else {
                    vector<int>::iterator it1;
                    it1=find(c0.begin(), c0.end(), y[i]);
                    if (it1==c0.end()){
                        c0.push_back(y[i]);
                        c.erase(it);
                        c.push_back(c0);
                        next=true; 
                        break;       
                    }
                }
            }
            if (it==c.end()&&!next){
                vector<int> c0;
                c0.push_back(x[i]);
                c0.push_back(y[i]);
                c.push_back(c0);
            }
                
        }
        cout<<c.size()<<endl;
    }
    //cout<<endl;
    
    return 0;
}