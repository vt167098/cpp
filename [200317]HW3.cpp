#include <iostream>
#include <algorithm>

using namespace std;

struct Line
{
    /* data */
    int a;
    int b;
};

bool compare(Line s, Line e){
    return s.a<e.a?true:((s.a==e.a)?s.b>s.a:false);
}

int main() {
	int i;

	int loop=0;
	int count=0;

    while (cin>>i&&i>0&&i<=10000){
        Line l[i];
        while(loop<i){
            //scanf("%d %d",&(l[loop].a), &(l[loop].b));
            cin>>l[loop].a>>l[loop].b;
            loop++;
        }
        sort(l, l+i, compare);
        for (int j=0; j<i; j++){
            if (j==i-1){
                count+=l[j].b-l[j].a;
            } else {
                if (l[j].a<l[j+1].a && l[j].b<l[j+1].a){
                    count+=l[j].b-l[j].a;
                } else if (l[j].a<l[j+1].a && l[j].b>l[j+1].b){    
                    swap(l[j],l[j+1]);
                } else if (l[j].a==l[j+1].a && l[j].b>l[j+1].b){    
                    swap(l[j],l[j+1]);
                }
            }
        }
        cout<<count<<endl;
        break;
    }

	return 0;
}
