#include <iostream>

int main() {
    int n;
    int m;
    std::cin>>n;
   std::cin>>m;
    int array [n][m];
    int count = 1;
    int count_2 = 0;
    //int n1=0;
    //int m1 =0;
    
    int a=0;
    int b=0;
    
    int left_bound = 0;
    int upper_bound = 0;
    int right_bound = m-1;
    int lower_bound = n-1;
    
    
    
   /* 
    for (int i = 0; i < 11; i++) { //перебор строк
     for (int j = 0; j < 11; j++) { //вывод одной строки
     array[i][j]=0;
    }   
    }
    */
    int q=(n*m)+1;
    
    while (count < q)
    {
        
        
                    if(a == upper_bound && b < right_bound && count < q)
                        {
                            array [a][b] = count++;
                            b++;
                            count_2++;
                        }
                    if(a < lower_bound && b == right_bound && count < q)
                        {
                            array [a][b] = count++;
                            a++;
                            count_2++;
                        }
                    if(a == lower_bound && b > left_bound && count < q)
                        {
                            array [a][b] = count++;
                            b--;
                            count_2++;
                        }
                    if(a > upper_bound && b == left_bound && count < q)
                        {
                            array [a][b] = count++;
                            a--;
                            count_2++;
                        }
                    if(count_2 == (2 * (right_bound-left_bound)) + (2 * (lower_bound-upper_bound)) && right_bound != left_bound && lower_bound!=upper_bound)
                       {
                            left_bound++;
                            upper_bound++;
                            right_bound--;
                            lower_bound--;
                            count_2 = 0;
                            a++;
                            b++;
                       }
            if(right_bound == left_bound && upper_bound == lower_bound){
                            left_bound++;
                            upper_bound++;
                            
                            count_2 = 0;
                            //a++;
                            //b++;
                            array [a][b] = count++;
                }
        
        
        
    }
  
    for (int i = 0; i < n; i++) { //перебор строк
     for (int j = 0; j < m; j++) { //вывод одной строки
     printf("%4d", array[i][j]);
    }   
    std::cout <<"\n";
    }
  return 0;
}
