#pragma warning(disable : 4996)


#include <iostream>



#include <cstring> // strlen, strcpy

/////////////////////////////////

#include <cstddef> // size_t

struct Substring;

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
        return 
    }


    struct Proxystring {
        Proxystring(const String& string) : size_p(string.size), str_p(string.str) {}


        size_t size_p;
        char* str_p;
    };

    size_t size;
    char* str;



};



int main() {
    std::cout << "djj" << std::endl;
    String hello = "hello";
    // Substring hello1 = "hello";
     //std::cout << hello[0] << std::endl;
    return 0;
}



