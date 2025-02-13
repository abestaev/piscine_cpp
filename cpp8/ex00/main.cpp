#include "easyfind.hpp"
#include <vector>

//conteneurs associatifs = base sur des arbres binaires ou tables de hachage
//conteneurs sequentiels = vector, deque, list, foward_list
//conteneurs associatifs = set, multiset, map, multimap, undordered_set, undordered_map


int main() {
    int array[] = {10, 20, 30, 40, 50};
    std::vector<int> v(array, array + sizeof(array) / sizeof(int));

    try {
        std::vector<int>::iterator it = easyfind(v, 30);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::vector<int>::iterator it = easyfind(v, 60);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        v.push_back(60);
        std::vector<int>::iterator it = easyfind(v, 60);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}