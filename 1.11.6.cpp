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
    
    multimap <string, string> dictionary;
   
    
    int N;
    cin >> N >> ws;
   
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
                        for (int j = 1; j < translation.size(); j++)
                            {
                             dictionary.emplace(translation[j],translation[0]);
                            }
                        
                    }   
  return 0;
}
