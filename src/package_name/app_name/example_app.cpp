#include "package_name/module_name/example.h"


int main(int argc, char* argv[]){
    using namespace package_name::module_name;
    ExampleFunction(); 
    ExampleClass example_class;
    for(size_t i=0; i <3 ; ++i){
        example_class.ExampleMethod();
    }
    return 0;
}