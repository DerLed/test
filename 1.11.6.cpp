#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int main() {
    string s;
    string buffer;
    int flag = 0;
    
    map <string, vector <string>> dictionary;
   
    
    int N;
    cin >> N >> ws;
   // cout << N;
                    for ( int i =0; i<N; i++)
                    {
                        string NEW;
                        vector <string> translation;
                        getline(cin, s);
                        for (auto c : s)
                            {
                                if ( c == ' ' && !buffer.empty() )
                                   {
                                       translation.push_back(buffer);
                                       buffer.clear();
                                   }
                                else if (c!=',' && c!='-' && c!=' ') 
                                   {
                                       buffer+=c;
                                   }
                             }
                        
                        
                        
                        
                    }   
  return 0;
}
