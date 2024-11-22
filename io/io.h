#pragma once 

#include <iostream>

namespace tsg
{
    enum NUMERIC_TYPE{
        DEC = 0,
        OCT = 1,
        HEX = 2
    };
    
    using print_output = std::ostream&;

    template <typename T>
    void print(const T& value){
        std::cout << value << std::endl;
    }

    template <typename T, typename ...Args>
    void print(const char* str, const T& value, Args... args){
        while(str && *str){
            if(('{' == *str) && ('}' == *(str + 1))){
                std::cout << value;
                print(++(++str), args...);
            } else {
                std::cout << *str++;
            }
        }
    }

    void new_line() {
        std::cout << std::endl;
    };

    void numeric_mode(const NUMERIC_TYPE& type) {        
        switch (type)
        {
        case NUMERIC_TYPE::DEC:
            std::cout << std::dec;
            break;
        case NUMERIC_TYPE::OCT:
            std::cout << std::oct;
            break;
        case NUMERIC_TYPE::HEX:
            std::cout << std::hex;
            break;        
        default:
            break;
        }
    }


    class streamable {
    protected:  
        virtual print_output print() const = 0;
        friend std::ostream& operator<<(std::ostream& os, const streamable& s);
    };

    std::ostream& operator<<(std::ostream& os, const streamable& s){
        return s.print();
    };
}