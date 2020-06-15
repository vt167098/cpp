#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n,k;
    while (cin>>n>>k){
        int *s=new int[n];
        for (int i=0; i<n; i++){
            cin>>s[i];
        }    
        int r=k/n;
        cout<<r<<endl;
    }
    return 0;
}