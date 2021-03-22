//
//https://server.179.ru/tasks/training/recursion.html
//

#include <iostream>
#include <vector>

void fnA(int a)//task A
        {
            if(a>1) fnA(a-1);
            std::cout << a; 
        }

void fnB(int a, int b)//task B
    {
        if (a>b)
            {
                std::cout << a;
                fnB(a-1,b);
            }
    
       if (a<b)
            {
                std::cout << a;
                fnB(a+1,b);
            }
        if (a==b) std::cout << a;
    }

void fnD(int n, int k = 2)//task D
        {
            if (k == n) std::cout << "YES";
            if (k > n) std::cout << "NO";
            if (k < n) fnD(n, k*2);
           
        }
void fnD2(int n)
    {
        if(n > 1 && n % 2 != 0) std::cout << "NO";
        if(n > 1 && n % 2 == 0) fnD2(n/2);
        if(n==1) std::cout << "YES";
        if(n==0) std::cout << "NO";
    }


int main() {
    int Aa = 5;
    
    int Ab = 2;
    int Bb = 15;
    
    std::cout <<"task A" << std::endl;
    fnA(Aa);
    std::cout << std::endl;
    
    std::cout <<"task B" << std::endl;
    fnB(Ab,Bb);
    std::cout << std::endl;
    //add task C here
    
    std::cout <<"task D" << std::endl;
    int Nd=7;
    fnD(Nd);
    fnD2(Nd);
    
  return 0;
}
