#include <iostream>

using namespace std;

//交換陣列a中下標為i和j的兩個元素的值  
void swap(int *a,int i,int j)  
{  
    a[i]^=a[j];  
    a[j]^=a[i];  
    a[i]^=a[j];  
}  
  
//將陣列a中的下標i到下標j之間的所有元素逆序倒置  
void reverse(int a[],int i,int j)  
{  
    for(; i<j; ++i,--j) {  
        swap(a,i,j);  
    }  
}  
  
long print(int a[],int length, int b[], int c[])  
{  
    long w_sum = 0;
    long total = 0;
    for(int i=0; i<length-1; i++){  
        w_sum+=b[a[i]];
        total+=w_sum*c[a[i+1]];
        // cout<<a[i]<<" "<<w_sum<<" "<<b[a[i]]<<" "<<c[a[i+1]]<<" "<<a[i+1]<<endl;
    }
    // cout<<total<<endl;  
    return total;
}  
  
//求取全排列,列印結果  
void combination(int a[],int length, int b[], int c[])  
{  
    if(length<2) return;  
  
    bool end=false;  
    long min = -1;
    while(true) {  
        long cost = print(a,length,b,c);  
        if (min<0 || min>cost)
            min = cost;
  
        int i,j;  
        //找到不符合趨勢的元素的下標i  
        for(i=length-2; i>=0; --i) {  
            if(a[i]<a[i+1]){ 
                break;  
            } else { 
                if(i==0){
                    cout<<min<<endl;
                    return;
                }  
            }    
        }  
  
        for(j=length-1; j>i; --j) {  
            if(a[j]>a[i]) break;  
        }  

        swap(a,i,j);  
        reverse(a,i+1,length-1);
    }
}

int main() {
    int n;
    while (cin>>n){
        int *s=new int[n];
        int *w=new int[n];
        int *f=new int[n];
        for (int i=0; i<n; i++){
            s[i]=i; 
            cin>>w[i];
        }    
        for (int i=0; i<n; i++)
            cin>>f[i];
        
        combination(s, n, w, f);
    }
    cout<<endl;
    
    return 0;
}