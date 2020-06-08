#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>

using namespace std;

struct Student
{
    int teachers[10];
    int match;
};

struct Teacher
{
    int students[10];
    int match;
};

vector<string> string_split(string s)
{
    const char delimiter = ',';
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
    vector<Student> s_data;
    vector<Teacher> t_data;

    for (int i=0; i<10; i++){
        string s;
        cin>>s;
        vector<string> ss = string_split(s);
        Student student;
        for (int j=1; j<=10; j++){
            student.teachers[j-1] = atoi(ss[j].c_str());
            student.match = 0;
        }
        s_data.push_back(student);
    }

    for (int i=0; i<10; i++){
        string s;
        cin>>s;
        vector<string> ss = string_split(s, '\\,');
        Teacher teacher;
        for (int j=1; j<=10; j++){
            teacher.students[j-1] = atoi(ss[j].c_str());
            teacher.match=0;
        }
        t_data.push_back(teacher);
    }

    int count=10;
    while(count>0){
        for (int i=0; i<10; i++){
            Student s = s_data[i];
            if (s.match==0){
                int h = 0;
                for (int j=0; j<10; j++){
                    int t = s.teachers[j];
                    if (t_data[t-1].match==0){
                        s_data[i].match = t;
                        t_data[t-1].match = i+1;
                        count--;
                    } else {
                        for (int k=0; k<10; k++){
                            if (t_data[t-1].students[k]==i+1){
                                s_data[t_data[t-1].match-1].match = 0;
                                s_data[i].match = t;
                                t_data[t-1].match = i+1;
                                count--;
                                break;
                            } else if (t_data[t-1].students[k]==t_data[t-1].match){
                                break;
                            }
                        }
                    }
                }
            }
        }
        cout<<endl;
    }

    return 0;
}
