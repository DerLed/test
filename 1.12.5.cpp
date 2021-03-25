#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

bool comparison (std::pair <int, int> a, std::pair <int, int> b) {

         return (a.second == b.second) ? a.first < b. first : a.second > b.second;

}

int main() {
    int n;
    std::cin >> n;
    std::vector <std::pair <int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int temp;
        int temp2;
        std::cin >> temp >> temp2;
        a[i] = {temp, temp2}; // создание пары значение - номер
    }
    




    
    sort(a.begin(), a.end(), comparison);
    for (auto now : a) {
        std::cout << now.second << " "<< now.first << std::endl;
    }
    
    return 0;
}
