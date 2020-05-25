#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Student
{
    string id;
    string teachers[10];
};

struct Teacher
{
    string id;
    string students[10];
};

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
    map<int, Student> s_data;
    map<int, Teacher> t_data;

    for (int i=0; i<10; i++){
        string s;
        cin>>s;
        vector<string> ss = string_split(s, '\\,');
        Student t_list;
        t_list.id = ss[0];
        for (int j=0; j<10; j++){
            t_list.teachers[j] = ss[j+1];
        }

        s_data.insert(pair<int, Student>(i+1, t_list));
    }

    for (int i=0; i<10; i++){
        string s;
        cin>>s;
        vector<string> ss = string_split(s, '\\,');
        Teacher s_list;
        s_list.id = ss[0];
        for (int j=0; j<10; j++){
            s_list.students[j] = ss[j+1];
        }

        t_data.insert(pair<int, Teacher>(i+1, s_list));
    }

	return 0;
}
