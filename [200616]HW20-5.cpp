#include <iostream>
#include <cmath>

using namespace std;

int main(){

    string s1, s2;
    int n;

    while(cin>>s1>>s2>>n){
    
        int s1_len=s1.size();
        int s2_len=s2.size();

        int **r_min = new int*[s1_len+1];
        for (int i = 0; i < s1_len+1; i++){
            r_min[i] = new int[s2_len+1];
        }
        int **r_max = new int*[s1_len+1];
        for (int i = 0; i < s1_len+1; i++){
            r_max[i] = new int[s2_len+1];
        }
        int r1,r2;
        for(int i=0; i<=s1_len; i++){
            for(int j=0;j<=s2_len;j++){
                if(i==0&&j==0){
                    r_min[i][j] = 0;
                    r_max[i][j] = 0;
                }else if(j<0 || i<j || ((i-j)>(s1_len-s2_len))){
                    r_min[i][j] = 9999;
                    r_max[i][j] = -9999;
                }else{                                
                    r1 = r_min[i-1][j]+abs(n-(s1[i-1]-'A'+1));
                    r2 = (j==0)?9999:r_min[i-1][j-1]+abs(s1[i-1]-s2[j-1]);
                    r_min[i][j] = (r1<r2)?r1:r2;
                    
                    r1 = r_max[i-1][j]+abs(n-(s1[i-1]-'A'+1));
                    r2 = (j==0)?-9999:r_max[i-1][j-1]+abs(s1[i-1]-s2[j-1]);
                    r_max[i][j] = (r1>r2)?r1:r2;
                }
            }
        }

        cout << r_min[s1_len][s2_len] << " " << r_max[s1_len][s2_len] << endl;

    }

    return 0;
}