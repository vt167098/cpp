#include <iostream>
#include <bitset> 

using namespace std;
int findPrime(int n){
	for (int k=n;k>1;k--){
		if (k%2==0&&k!=2){
			continue;
		} else {
			for (int j=2; j<=k; j++){
				if (k%j==0&&j<k){
					break;
				} else if (j==k){
					return k;
				}	
			}
		}
	}
	return 0;
}

bitset<32> convBinary(const unsigned int val)
{
	bitset<32> b;
	for(int i = 32; i >= 0; i--)
	{
		if(val & (1 << i))
			b[i]=1;
		else
			b[i]=0;
	}
	return b;
}
int main(){
	int p,s;
	bitset<32> b,pb;
	
	while(cin>>p&&p>0){
		b = convBinary(p);
		//cout<<b<<endl;
		for (int i=p; i>1; i--){
			int p0 = findPrime(i);
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
