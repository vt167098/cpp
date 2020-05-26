#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct Student
{
    string id;
    string teachers[10];
    string match;
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
    map<int, Teacher>::iterator it;

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

    while (t_data.size()>0){
        for (int i=1; i<=t_data.size(); i++){
            Teacher t_temp = t_data[i];
            vector<int> m_list;
            for (int j=1; j<=s_data.size(); j++){
                Student s_temp = s_data[j];
                if (s_temp.teachers[i-1]==to_string(i)){
                    s_temp.match = to_string(i);
                    s_data[j]=s_temp;
                    m_list.push_back(j);
                }
            }
            if (m_list.size()==1){
                it = t_data.find(i);
                if (it != t_data.end())
                    t_data.erase(it);
            } else if (m_list.size()>1){
                for (int k=0; k<10; k++){
                    for (vector<int>::iterator it1=m_list.begin(); it1!=m_list.end(); it++){
                        if (t_temp.students[k]==to_string(*it1)){

                        }
                    }
                }
            }
        }
    }
	return 0;
}
