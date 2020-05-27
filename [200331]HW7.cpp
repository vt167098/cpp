//
//  main.cpp
//  hw7
//
//  Created by 童培軒 on 2020/3/31.
//  Copyright © 2020 童培軒. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
    string Z,E;
    int N;
    int a,b,c,tmp1,tmp2,i;
    string place;
    cin>>N;
    for(i=0;i<N;i++){
        cin>>place>>a>>b>>c;
        if (place=="Z") {
            tmp1=(a*48)*30+b*30+c;
            c=tmp1%60;
            tmp2=tmp1/60;
            b=tmp2%60;
            a=tmp1/3600;
            cout<<"E"<<" "<<a<<" "<<b<<" "<<c<<endl;
        }
        else if(place=="E") {
            tmp1=(a*60)*60+b*60+c;
            c=tmp1%30;
            tmp2=tmp1/30;
            b=tmp2%48;
            a=tmp1/1440;
            cout<<"Z"<<" "<<a<<" "<<b<<" "<<c<<endl;        }
    }
    return 0;
}
