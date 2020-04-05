#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Cost
{
    /* data */
    int r;
    int c;
    int cost;
};

int distance(int r1, int c1, int** m1, int m, int n){
    int x1=0;
    int y1=0;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (r1!=i || c1!=j){
            	x1 += abs(i-r1)*10*m1[i][j];
	            y1 += abs(j-c1)*10*m1[i][j];
                //cout<<r1<<" "<<c1<<"=>"<<m1[i][j]<<"("<<i<<","<<j<<")"<<endl;
            }
        }
    }
	return x1+y1;
}

bool compare(Cost c1, Cost c2){
    return c1.cost<c2.cost;
}

int main() {
	int n,i,r,c;
	int u=0;
    struct Cost cost_row; 

    while (cin >> n&&n<350){
        for (int n0=0; n0<n; n0++){
            while (cin>>r>>c&&r>=1&&r<=100&&c>=1&&c<=100){
                int m[r][c];
                int* m0[r];
                struct Cost cost_list[r*c]; 
                for (int i=0; i<r; i++){
                    for (int j=0; j<c; j++){
                        scanf("%d", &m[i][j]);
                    }
                    m0[i] = m[i];
                }
                for (int i=0; i<r; i++){
                    for (int j=0; j<c; j++){
                        cost_row.r = i;
                        cost_row.c = j;
                        cost_row.cost = distance(i,j,m0,r,c);
                        cost_list[i*c+j]=cost_row;
                    }
                }
                sort(cost_list, cost_list+(r*c), compare);
                cout<<cost_list[0].r+1<<" "<<cost_list[0].c+1<<" "<<cost_list[0].cost<<endl;
                break;
            }
            }
        break;
    };
	return 0;
}

