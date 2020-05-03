#include <iostream>
#include <bitset> 
#include <math.h> 

using namespace std;

bool findPrime(unsigned long n)
{
    // 檢查小於等於sqrt(n)的因數（除了1）
    unsigned long sqrt_n = sqrt(n);
    for (unsigned long d=2; d<=sqrt_n; ++d)
        if (n % d == 0)
            return false;
    return true;
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
int main(){
	unsigned long p, p0;
	bitset<32> b,pb;
	
	while(cin>>p&&p>0){
		b = convBinary(p);
		//cout<<b<<endl;
		for (unsigned long i=p; i>1; i--){
			p0 = findPrime(i)?i:0;
			if (p0!=0){
				pb = convBinary(p0);
				if (b.count()==pb.count()){
					cout<<p0<<endl;
					break;
				}
			}
		}
	}

    return 0;
}
