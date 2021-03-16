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
    cin >> N;
                    for ( int i =0; i<N; i++)
                    {
                        string NEW;
                        vector <string> translation;
                        
                        while (cin >> s)
                            {
                            cout << s << "\n";
                                if (s[0] == '-') flag = 1;

                                if (flag == 0) NEW = s;
                                if (flag == 1 && s[0] != '-')
                                    {

                                        for (int n = 0; n < s.size(); i++)
                                                    {
                                                     if(s[i] != ',')
                                                         {
                                                            buffer += s[i];
                                                         }
                                                    }
                                        translation.push_back(buffer); 
                                        buffer.clear();
                                    }
                            }
                        flag = 0;
                        dictionary[NEW] = translation;

                    }
  // put your code here
  return 0;
}
