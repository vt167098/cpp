#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

string i2bs(long int n, int len)
{
    string binary;
    int a[len], i;
    
    for(i=0; i<len; i++)    
    {    
        a[i]=n%2;    
        n= n/2;  
    }    
    i=len;
    for(i=i-1 ;i>=0 ;i--)    
    {    
        binary+=to_string(a[i]);    
    }

    //reverse(binary.begin(), binary.end());

    return binary;
}

int main() {
    string s1,s2;
    int n;
    while (true){
        int r_min=-1, r_max=-1, t_loop;
        cin>>s1;
        cin>>s2;
        cin>>n;

        int s1_len = s1.size();
        int s2_len = s2.size();
        int loop = pow(2,s1_len);
        int q_len = s1_len-s2_len;
        for (int i = 1; i <loop; i++) {
            string bin2s = i2bs(i,s1_len);
            int s2_pos = 0;
            t_loop =0;
            int truecount = 0;
            int q_pos=0;
            int *arr = new int[q_len];
            for (int k=0; k<s1_len; k++) {
                if (bin2s[k]=='1'){
                    truecount++;
                    arr[q_pos]=k;
                    q_pos++;
                }
            }
            
            if (truecount==s1_len-s2_len){
                int pos1=0, pos2=0;
                for (int j=0;j<s1_len;j++){
                    if (j==arr[pos1]&&pos1<q_pos){
                        t_loop+=abs(s1[j]-'A'-n+1);
                        pos1++;
                    } else {
                        t_loop+=abs(s1[j]-s2[pos2]);
                        pos2++;
                    }
                }    
                r_min = r_min<0||t_loop<r_min?t_loop:r_min;
                r_max = r_max<0||t_loop>r_max?t_loop:r_max;    
            }
        }
        cout<<r_min<<" "<<r_max<<endl;
    }
    return 0;
}
