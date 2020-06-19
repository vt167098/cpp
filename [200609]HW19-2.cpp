#include<iostream>
#include<algorithm>

using namespace std;

bool coverage(int x,int n, int k, int v[50001]){
  int next,count=0;
  for(int i=0;i<n;){
	next=v[i]+x;
	count++;
	if (count > k) {
	  return false;
	}
	if ((v[n-1]<=next)&&(count<=k))
    return true;
    do{
      i++;
	  }while (v[i] <= next);
  }
  return false;
}

int main(){
  int n,k;
  int L,R,M;
  int v[50001];
  while (cin>>n){
    cin >> k;
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    sort(v, v+n);
    if (k==1){
      cout<< v[n-1]-v[0]<<endl;
    }else{
        L=1;
        R=((v[n-1]-v[0])/k)+1;
        while(L<=R){
          M=(L+R)/2;
          if (coverage(M,n,k,v))
            R=M;
          else
            L=M+1;
          if (L==R)
            break;
        }
        cout << R <<endl;
    }
  }

  return 0;
}