#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <regex>
#include <math.h>
#include <bitset>

using namespace std;

int range(char a, char b, int r){
    regex e ("^[A-Z]$");
    string a1(1,a);
    string b1(1,b);
    int x = regex_match(a1,e)?((int)a-64):0;
    int y = regex_match(b1,e)?((int)b-64):0;
    return abs(x-y-r);
}

bitset<32> convBinary(const unsigned long val)
{
	bitset<32> b;
	for(int i = 31; i >= 0; i--)
	{
		if(val & (1 << i))
			b[i]=1;
		else
			b[i]=0;
	}
	return b;
}

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
        bitset<32> b;
        cin>>s1;
        cin>>s2;
        cin>>n;

        int s1_len = s1.size();
        int s2_len = s2.size();
        int loop = pow(2,s1_len);
        for (int i = 1; i <loop; i++) {
            b = convBinary(i);
            string bin2s = i2bs(i,s1_len);
            int s2_pos = 0;
            t_loop =0;
            if (b.count()==s1_len-s2_len){
                for (int j=0;j<s1_len;j++){
                    if (bin2s[j]=='0'&&s2_pos<=s2_len){
                        int ans = range(s1[j], s2[s2_pos], 0);
                        t_loop += ans;
                        s2_pos++;
                    } else {
                        int ans = range(s1[j], '0', n);
                        t_loop += ans;
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
