#include <iostream>

using namespace std;

int effect(int a, int b, int c){
    return a*b*c;
}

int main(){
	int n,m,s;

    while(cin>>n&&n>1&&n<=20){
        for (int i=0; i<n; i++){
            while(cin>>m&&m>2&&m<=30){
                int s[m];
                int k=1;
                int el=0;
                int er=0;
                for (int j=0; j<m; j++){
                    cin>>s[j]; 
                }
                while (k<m-1)
                {
                    el+=effect(s[0],s[k],s[k+1]);
                    k++;
                }
                k=m-2;
                while (k>0)
                {
                    er+=effect(s[k-1],s[k],s[m-1]);
                    k--;
                }
                (er>el)?(cout<<er<<" "<<el<<endl):(cout<<el<<" "<<er<<endl);
                m=0;
            }
        }
        n=0;
    }
	
    return 0;
}
