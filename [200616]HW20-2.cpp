#include <iostream>
#include <cmath>

using namespace std;

int dismax(int n, int m, string s1, string s2, int k, int t){
    if(m==0&&n==0) return 0;
    else if(m<0 || n<m || ((n-m)>t) ) return -99999999;
    // if(n==0 || m==0) return 0;
    else{
        return max(
            dismax(n-1, m, s1, s2, k, t)+abs(k-(s1[n-1]-'A'+1)),
            dismax(n-1, m-1, s1, s2, k, t)+abs(s1[n-1]-s2[m-1])
        );
    }
}

int dismin(int n, int m, string s1, string s2, int k, int t){
    if(m==0&&n==0) return 0;
    else if(m<0 || n<m || ((n-m)>t) ) return 99999999;
    // if(n==0 || m==0) return 0;
    else{
        return min(
            dismin(n-1, m, s1, s2, k, t)+abs(k-(s1[n-1]-'A'+1)),
            dismin(n-1, m-1, s1, s2, k, t)+abs(s1[n-1]-s2[m-1])
        );
    }
}

int main(){

    string str1, str2;
    int k;

    while(cin>>str1>>str2>>k){
    
        int n=str1.size();
        int m=str2.size();

        // cout << dismin(n, m, str1, str2, k, n-m) << " " << dismax(n, m, str1, str2, k, n-m) << endl;

        int **minarr = new int*[n+1];
        for (int i = 0; i < n+1; i++){
            minarr[i] = new int[m+1];
        }
        int **maxarr = new int*[n+1];
        for (int i = 0; i < n+1; i++){
            maxarr[i] = new int[m+1];
        }
        // // // cout << n << m << endl;
        int a,b;
        for(int i=0; i<=n; i++){
            for(int j=0;j<=m;j++){
                // cout << i << j;
                if(i==0&&j==0){
                    minarr[i][j] = 0;
                    maxarr[i][j] = 0;
                }else if(j<0 || i<j || ((i-j)>(n-m))){
                    minarr[i][j] = 999999;
                    maxarr[i][j] = -999999;
                }else{                                
                    a = minarr[i-1][j]+abs(k-(str1[i-1]-'A'+1));
                    b = (j==0)?999999:minarr[i-1][j-1]+abs(str1[i-1]-str2[j-1]);
                    minarr[i][j] = (a<b)?a:b;
                    
                    a = maxarr[i-1][j]+abs(k-(str1[i-1]-'A'+1));
                    b = (j==0)?-999999:maxarr[i-1][j-1]+abs(str1[i-1]-str2[j-1]);
                    maxarr[i][j] = (a>b)?a:b;
                    // cout << minarr[i+1][j+1] << " ";
                }
            }
            // cout << endl;
        }

        // cout << endl;
        // for(int i=0; i<n+1; i++){
        //     for(int j=0;j<m+1;j++){
        //         cout << minarr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // cout << endl;
        // for(int i=0; i<n+1; i++){
        //     for(int j=0;j<m+1;j++){
        //         cout << maxarr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        cout << minarr[n][m] << " " << maxarr[n][m] << endl;

        for (int i = 0; i < n+1; i++){
            delete[] minarr[i];
        }
        delete[] minarr;
        for (int i = 0; i < n+1; i++){
            delete[] maxarr[i];
        }
        delete[] maxarr;
    }

    return 0;
}