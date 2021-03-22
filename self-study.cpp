//
//https://server.179.ru/tasks/training/recursion.html
//

#include <iostream>
#include <vector>

void fn(int a)//task A
        {
            if(a>1) fn(a-1);
            std::cout << a; 
        }

void fn2(int a, int b)//task B
    {
        if (a>b)
            {
                std::cout << a;
                fn2(a-1,b);
            }
    
       if (a<b)
            {
                std::cout << a;
                fn2(a+1,b);
            }
        if (a==b) std::cout << a;
    }

int main() {
    int Aa = 5;
    
    int Ab = 2;
    int Bb = 15;
    
    std::cout <<"task A" << std::endl;
    fn(Aa);
    std::cout << std::endl;
    
    std::cout <<"task B" << std::endl;
    fn2(Ab,Bb);
    
  return 0;
}
