#include "package_name/module_name/example.h"
#include <iostream>

namespace package_name{
namespace module_name{

struct ExampleClass::impl{
    int member_;
};

void ExampleFunction(){
    std::cout << "Call ExampleFunction()."<<std::endl;
}

ExampleClass::ExampleClass():data_(new impl)
{
    data_->member_=0;
    std::cout << "Call ExampleClass::ExampleClass()."<<std::endl;
}

ExampleClass::~ExampleClass(){
    std::cout << "Call ExampleClass::~ExampleClass()."<<std::endl;
}

void ExampleClass::ExampleMethod(){
    std::cout << "Call ExampleClass::ExampleMethod()."<<std::endl;
    std::cout << "data_->member_ =="<< data_->member_++ <<std::endl;
}

} //namespace module_name
} //namespace package_name