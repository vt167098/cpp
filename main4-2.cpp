#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int num;
    int n;
    vector<int> nums;
    vector<vector<int> >nums2;
    bool scoreadd=true;
    int examcount = 0;
    int gap = 0;
    int scoremax = 0;
    
    cin>>n;
    while(cin>>num)
    {
    	if (num>=0||num<=100)
        	nums.push_back(num);
        if (getchar()=='\n'){
			for (int q=0; q<nums.size(); q++){
				//cout<<nums2[p][q]<<endl;
				if (nums[q]>=95){
					scoreadd = false;
				} else if(scoreadd){
					scoremax = scoremax<nums[q]||q==0?nums[q]:scoremax;
					gap = gap>(95-scoremax)?(95-scoremax):gap;
				}
			}
			examcount = 0;
			for (int q=0; q<nums.size(); q++){
				nums[q]=scoreadd?(nums[q]+gap):nums[q];
				//cout<<nums2[p][q]<<endl;
				examcount+=(nums[q]>54&&nums[q]<60?1:0);
			}
			cout<<examcount<<endl;
        	if(--n==0){
        		break;
			}else{
				nums.clear();
			}
		}
    }
	cout<<endl;
    return 0;
}
