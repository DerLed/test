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
                       // cout << s[s.size()-1] << "\n";
                        for (int j = 0; j < s.size(); j++)
                            {
                               
                            
                                if (s[j] != ',' && s[j] !='-' && s[j] !=' ') 
                                   {
                                       buffer+=s[j];
                                   }
                            
                                if ( (s[j] == ' ' && !buffer.empty()) || j == (s.size()-1) )
                                   {
                                       translation.push_back(buffer);
                                       cout << "Write buffer " << buffer << "\n";
                                       buffer.clear();
                                   }
                                
                             }
                        for (int j = 1; j < translation.size(); j++)
                            {
                            cout << translation[j] << "\n";
                            dictionary.emplace(translation[j],translation[0]);
                            }
                        translation.clear();
                    }   
    
 //    for (auto it = dictionary.begin(); it != dictionary.end(); ++it)///вывод на экран
 // {
 //    cout << it->first << " - "<< it->second << endl;
 // }
   cout << " ----------- " <<"\n"; 
  for (auto now : dictionary)
  {
        cout << now.first << " - ";
       cout << now.second << "\n";
        
      
  }
    
     cout << " ----------- " <<"\n"; 
 /*   
    for (auto ch : dictionary)
          {
            pair <multimap<string,string>::iterator, multimap<string,string>::iterator> ret;//
            ret = dictionary.equal_range(ch);
            cout << ch << " =>";
                for (multimap<string,string>::iterator it=ret.first; it!=ret.second; ++it)
                    {
                      std::cout << ' ' << it->second;
                      std::cout << '\n';
                    }
          }
  */
    
    
    auto range = dictionary.equal_range("malum");
 
    for (auto i = range.first; i != range.second; ++i)
    {
        std::cout << i->second << '\n';
    }
    
    
  return 0;
}
