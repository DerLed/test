#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int main() {
    string s;
    string buffer;
    string output;
    string KEY;
    int flag = 0;
    
    multimap <string, string> dictionary;
   
    
    int N;
    cin >> N >> ws;
   
                    for ( int i =0; i<N; i++)
                    {
                        string NEW;
                        vector <string> translation;
                        getline(cin, s);
                        for (int j = 0; j < s.size(); j++)
                            {
                               
                            
                                if (s[j] != ',' && s[j] !='-' && s[j] !=' ') 
                                   {
                                       buffer+=s[j];
                                   }
                            
                                if ( (s[j] == ' ' && !buffer.empty()) || j == (s.size()-1) )
                                   {
                                       translation.push_back(buffer);
                                       buffer.clear();
                                   }
                                
                             }
                        for (int j = 1; j < translation.size(); j++)
                            {
                                dictionary.emplace(translation[j],translation[0]);
                            }
                        translation.clear();
                    }   
    


    int count = 0;
    int sss = 1;
     for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
  {
      
    
       if (sss == 1)
       {
           
           KEY = it->first;
           output = it->first + " - " + it->second;
           count++;
       }
       //else if (it == dictionary.end())
       else if (sss == dictionary.size()) // последний элемент
       {
         
           if (KEY != it->first)
             {
                 cout << output << "\n";
                 cout << it->first + " - " + it->second;
             }
           
          else 
             {
                 output+=", " + it->second;
                  cout << output << "\n";
             }
           
           
       
       }  
         
       else  
       {  
            
         if (KEY != it->first)
             {
                 cout << output << "\n";
                 output.clear();
             
                 KEY = it->first;
                 output = it->first + " - " + it->second;
             }
           
          else 
             {
                 output+=", " + it->second;
             }
           
       }
         
       
      sss++;  
      
  }
    
  return 0;
}
