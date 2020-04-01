#include <iostream>

using namespace std;

int main() {
	int i,hour,minutes,second;
	char planet;
		
	cin>>i;
	while(i>0){
		cin>>planet>>hour>>minutes>>second;
		if (planet=='E'){
			planet='Z';
			second=hour*60*60+minutes*60+second;
			hour=(second-second%(48*30))/48/30;
			minutes=(second-second%30)/48-hour*48;
			second=(second-48*30*hour)%30;
			i--;	
		} else if (planet=='Z'){
			planet='E';
			second=hour*48*30+minutes*30+second;
			hour=(second-second%(60*60))/60/60;
			minutes=(second-second%60)/60-hour*60;
			second=(second-60*60*hour)%60;
			i--;
		}
	}
	cout<<planet<<" "<<hour<<" "<<minutes<<" "<<second;
	return 0;
}
