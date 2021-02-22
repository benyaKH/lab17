#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string &f,vector<string> &n,vector<int> &s,vector<char> &g){
    ifstream text(f.c_str()) ;
    char format[] = "%[^:]: %d %d %d" ;
    string data ;
    char name[100] ;
    int a,b,c ;
    while(getline(text,data)){
        sscanf(data.c_str(),format,name,&a,&b,&c);
        n.push_back(name) ;
        s.push_back(a+b+c);
        g.push_back(score2grade(a+b+c));
        
    }

}

void getCommand(string &c,string &k){
    string data ;
    cout<<"Please input your command: " ;
    getline(cin,data);
    int start = 0 ;
    int end = data.find_first_of(" ");
    c = data.substr(start,end-start) ;
    start = end+1 ;
    k = data.substr(start,end-start) ;
}

void searchName(vector<string> &n,vector<int> &s,vector<char> &g,string key){
    int check = 0 ;
    cout << "---------------------------------\n";
	    for(unsigned int i=0 ; i < n.size() ; i++){
            if(key==toUpperStr(n[i])){ 
                cout<< n[i]<<"'s score = "<< s[i] <<"\n";
                cout<< n[i]<<"'s grade = "<< g[i] <<"\n";
                check = 1 ;
            }
        }
    if(check== 0) cout<<"Cannot found.\n";

	cout << "---------------------------------\n";
}

void searchGrade(vector<string> &n,vector<int> &s,vector<char> &g,string key){
int check = 0 ;
    cout << "---------------------------------\n";
	    for(unsigned int i=0; i < g.size() ; i++){
            if(key[0]==g[i]){ 
                cout<<n[i]<<" ("<<s[i]<<") \n";
                check = 1 ;
            }
            
        }
    if(check== 0) cout<<"Cannot found.\n";
    cout << "---------------------------------\n";
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
