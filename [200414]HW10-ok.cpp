#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

void char_distance(string s1, string s2){
    int d=0;
    for (int i=0; i<s1.length(); i++){
        d+=abs((int)s1[i]-(int)s2[i]);
    }
    cout<<d<<endl;
}

int main(){
    int n;
    
    cin>>n;
    for (int k=0; k<n; k++){
        string s1,s2;
        
        cin>>s1>>s2;
        
        char_distance(s1, s2);
    }

    return 0;
}
