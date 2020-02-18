#ifndef PACKAGE_NAME_MODULE_NAME_EXAMPLE_H_
#define PACKAGE_NAME_MODULE_NAME_EXAMPLE_H_

#include <memory>

namespace package_name
{
namespace module_name
{
void ExampleFunction();
class ExampleClass
{
public:
    ExampleClass();
    ~ExampleClass();
    void ExampleMethod();

private:
    struct impl;
    std::unique_ptr<impl> data_;
};
} // namespace module_name
} // namespace package_name

#endif //PACKAGE_NAME_MODULE_NAME_EXAMPLE_H_