#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "\033[1;3m[Subject Test: List]\033[0m" << std::endl;

    std::list<int> list;

    list.push_back(5);
    list.push_back(17);

    std::cout << list.back() << std::endl;

    list.pop_back();

    std::cout << list.size() << std::endl;

    list.push_back(3);
    
    list.push_back(5);
    list.push_back(737);
    //[...]
    list.push_back(0);

    std::list<int>::iterator it_list = list.begin();
    std::list<int>::iterator ite_list = list.end();

    ++it_list;
    --it_list;
    while (it_list != ite_list)
    {
        std::cout << *it_list << std::endl;
        ++it_list;
    }
    // std::stack<int> s(list);
    std::cout << "\033[1;3m[Subject Test: MutantStack]\033[0m" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\033[1;3m[Test with string]\033[0m" << std::endl;
    MutantStack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("!");

    MutantStack<std::string>::iterator itStr = strStack.begin();
    while (itStr != strStack.end())
    {
        std::cout << *itStr << std::endl;
        ++itStr;
    }
    
    return 0;
}