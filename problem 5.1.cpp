#pragma warning(disable : 4996)


#include <iostream>



#include <cstring> // strlen, strcpy

/////////////////////////////////

#include <cstddef> // size_t

//struct Substring;

struct String {

    struct Proxystring;

    String(const char* str = "") : size(strlen(str))
        , str(strcpy(new char[strlen(str) + 1], str))
    {}

    String(size_t n, char c) {
        this->str = new char[n + 1];
        for (size_t i = 0; i < n; i++) {
            this->str[i] = c;
        }
        //this->str[n + 1] = '\0';
        this->size = strlen(str);
    }

    ~String() {
        delete[] str;
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


   Proxystring operator[](int begin) {
       /* char *m = new char[size - begin + 1];
        for(int i = begin; i <= (size - begin+1); ++i) {
            m[i-begin] = str[i];
            //std::cout << m[i-begin] << std::endl;
        }
        */
        //std::cout << m << std::endl;
        //Proxystring t1 (str, begin);
        //delete[] m;
        return Proxystring (str, begin);
    }

    struct Proxystring {
      // Proxystring(const String& string, int begin = 0) : size_p(string.size), str_p(string.str), begin_p(begin) {}
        
        Proxystring(const char* str = "", int begin = 0) : size_p(strlen(str))
        , str_p(strcpy(new char[strlen(str) + 1], str)), begin_p(begin)
        {}
        
        String operator[](int end) {
           // if (begin_p == end) return String();
            char *m = new char[end - begin_p + 1];
            for(int i = begin_p; i < end; ++i) {
                m[i-begin_p] = str_p[i];
                std::cout << m[i-begin_p] << std::endl;
            }
            
            str_p = m;
           // delete [] m;
            std::cout << "str_p= "<< str_p << std::endl;
            
            /*
            for(int i = 0; i < strlen(m)+1; ++i) {
                if (m[i]== '\0') std::cout << "zaebis" << std::endl;
                std::cout << "m["<< i << "]= "<< m[i] << std::endl;
            }
            */
            
            
            return String(str_p);
        }
        
        int begin_p;
        size_t size_p;
        char* str_p;
    };

    size_t size;
    char* str;



};



int main() {
    //std::cout << "djj" << std::endl;
    String hello = "hello";
    String * abc = new String("World");
    //String::Proxystring hello1(hello);
    
    char* kuku = new char[5];
    kuku[0] = 'k';
    kuku[1] = 'i';
    kuku[2] = 'k';
    kuku[3] = 'i';
    String::Proxystring hello2(kuku);
    String::Proxystring hello3();
    //hello3 = hello2;
    //std::cout << hello.size << std::endl;
    //std::cout << hello[2].str_p << std::endl;
   // String const ell  = hello[1][4];
    String const pusto  = hello[1][4];
    //std::cout << ell.str << std::endl;
    std::cout << pusto.str << std::endl;
    std::cout << "konec" << std::endl;
    return 0;
}



