#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    string s1,s2;
    int n;
    while (true){
        int r_min=-1, r_max=-1, t_loop,q_len,s1_len,s2_len,pos1,pos2;
        cin>>s1;
        cin>>s2;
        cin>>n;

        s1_len = s1.size();
        s2_len = s2.size();
        q_len = s1_len-s2_len;
        for (int i = 0; i <s1_len; i++){
            t_loop =0;
            for (int j=0; j<s2_len; j++){
                pos1 = (i+j)%s1_len;
                t_loop+=abs(s1[pos1]-s2[j]);
            }
            for (int k=s2_len; k<s1_len; k++){
                pos2=(i+k)%s1_len;
                t_loop+=abs(s1[pos2]-'A'-n+1);
            }
            r_min = r_min<0||t_loop<r_min?t_loop:r_min;
            r_max = r_max<0||t_loop>r_max?t_loop:r_max;    
        }
        cout<<r_min<<" "<<r_max<<endl;
    }
    return 0;
}
