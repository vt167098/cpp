#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <regex>

using namespace std;

vector<string> string_split(string s, const char delimiter)
{
    size_t start=0;
    size_t end=s.find_first_of(delimiter);
    
    vector<string> output;
    
    while (end <= string::npos)
    {
	    output.emplace_back(s.substr(start, end-start));

	    if (end == string::npos)
	    	break;

    	start=end+1;
    	end = s.find_first_of(delimiter, start);
    }
    
    return output;
}

int main() {
    string str;
    int n;

    cin>>str;
    vector<string> str1 = string_split(str, '*');
    vector<string> str2 = string_split(str1[0], 'n');
    vector<string> str3 = string_split(str1[1], 'n');

    regex e1 ("("+str2[0]+"+)");
    str2[1] = str2[1].substr(0,str2[1].length()-1);
    regex e2 (str2[1]+".)");
    regex e3 ("("+str3[0]+"+)");
    str3[1] = str3[1].substr(0,str3[1].length()-1);
    regex e4 (str3[1]+".)");

    smatch sm1,sm2,sm3,sm4;

    cin>>n;

    while(n--){
        string test,t1,t2,t3,t4;
        cin>>test;

        regex_match(test, sm1, e2);
        cout<<sm1.size()<<endl;
        for (auto x:sm1) std::cout << x << " ";
        t1 = sm1.suffix().str();

        regex_match(test, sm2, e1);
        cout<<sm2.size()<<endl;
        for (auto x:sm2) std::cout << x << " ";
        t2 = sm2.suffix().str();

        regex_match(test, sm3, e4);
        cout<<sm3.size()<<endl;
        for (auto x:sm3) std::cout << x << " ";
        t3 = sm3.suffix().str();

        regex_match(test, sm4, e3);
        cout<<sm4.size()<<endl;
        for (auto x:sm4) std::cout << x << " ";
        t4 = sm4.suffix().str();
    }

	return 0;
}
