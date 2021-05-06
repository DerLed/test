#pragma warning(disable : 4996)


#include <iostream>



#include <cstring> // strlen, strcpy

/////////////////////////////////

#include <cstddef> // size_t



struct String {

    struct Proxystring;

    String(const char* str = "") : size(strlen(str))
        , str(strcpy(new char[strlen(str) + 1], str))
    {
        std::cout << "/////alloc STR " << &str << std::endl;
        std::cout << "konstructor String " << this << std::endl;
    }

    String(size_t n, char c) {
        this->str = new char[n + 1];
        for (size_t i = 0; i < n; i++) {
            this->str[i] = c;
        }
        //this->str[n + 1] = '\0';
        this->size = strlen(str);
    }

    ~String() {
        std::cout << "/////delete " << &str << std::endl;
        delete[] str;
        
        std::cout << "destructor String " << this << std::endl;
    }

    String(const String& other) {
        new (this) String(other.str);
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            new (this) String(other.str);
        }
        return *this;
    }

    void append(const String& other)
    {
        size += other.size;
        char* m = new char[size + 1];
        strcpy(m, str);
        strcat(m, other.str);

        delete[] str;
        str = m;
    }


    Proxystring operator[] (int begin) const {
        return Proxystring (str, begin);
    }

    struct Proxystring {
        
        Proxystring(const char* str = "", int begin = 0) : size_p(strlen(str))
        , str_p(strcpy(new char[strlen(str) + 1], str)), begin_p(begin)
        {
            std::cout << "/////alloc PRX " << &str_p << std::endl;
            std::cout << "konstructor Proxystring " << this << std::endl;
        }
        
        String operator[](int end) {
            char *m = new char[end - begin_p + 1];
            std::cout << "/////alloc M " << &m << std::endl;
            for(int i = begin_p; i < end; ++i) {
                m[i-begin_p] = str_p[i];
            }
            //str_p = m;
            std::cout << "/////delete STR " << &str_p << std::endl;
            delete [] str_p;
            return String(m);
        }
        
        ~Proxystring() {
           // std::cout << "/////delete " << &str_p << std::endl;
        //delete[] str_p;
        std::cout << "destructor Proxystring " << this << std::endl;
        }
        
        int begin_p;
        size_t size_p;
        char* str_p;
    };

    size_t size;
    char* str;



};



int main() {
    String const hello("hello");
    std::cout << hello.str << std::endl;
   // String const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
    //std::cout << hell.str << std::endl;
    String const ell  = hello[1][4]; // теперь в ell хранится подстрока "ell"
    std::cout << ell.str << std::endl;
    return 0;
}



