// Example program
#include <iostream>
#include <thread>

std::string resource{};

void foo(){
    while(1){
        resource = "foo";
        std::cout << resource << std::endl;
    }
}

void bar(){
    while(1){
        resource = "bar";
        std::cout << resource << std::endl;
    }
}

int main()
{
    std::thread th1(foo);
    std::thread th2(bar);
    
    while(1){}
    
    th1.join();
    th2.join();
}