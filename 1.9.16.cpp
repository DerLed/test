#include <iostream>
#include <vector>

void queen (std::vector <std::vector <int>> &a, int str = 0, int stol = 0, int count = 0) {
    
            for (int i = 0; i < a.size(); i++) {

                if (a[i][stol] != 1) {
                        set (a);
                        queen(a, )
                }
                
                
            }
    
    
    
    
    
    
    
    
}


void set (std::vector <std::vector <int>> &a, int x, int y) {  ///что бы получить доступ к массиву
    for (int i = 0; i < a.size(); i++) {                       ///и его изменить надо ставить & 
        for (int j = 0; j < a[i].size(); j++) {
           if (x-y==i-j || x+y==i+j || x==i || y==j) 
                a[i][j] = 1;
        }
    }
}



int main() {
    int n;
    std::cin >> n;
    std::vector <std::vector<int>> array;
    for (int i = 0; i < n; i++) {
        std::vector <int> temp;
        for (int j = 0; j < n; j++) {
            temp.push_back(0);
        }
        array.push_back(temp);
    }

set (array, 3, 4);    
  
    for (int i = 0; i < array.size(); i++) {
        for (int j = 0; j < array[i].size(); j++) {
            std::cout << array[i][j] << " ";
        }
       std::cout << std::endl;
    }
   
   
    //std::cout << array[0].size();
    
queen(array);
 
  return 0;
}
