#include "Serializer.hpp"

//serialization usage: stocker ou/et transmettre des données

int main ()
{
    Data data;
    data.s1 = "Hello";
    data.n = 42;

    std::cout << "s1: " << data.s1 << std::endl;
    std::cout << "n: " << data.n << std::endl;
    std::cout << "data:         " << &data << std::endl;

    uintptr_t *serialized = Serializer::serialize(&data);
    std::cout << "serialized:   " << serialized << std::endl;

    Data *deserialized = Serializer::deserialize(serialized);
    std::cout << "deserialized: " << deserialized << std::endl;

    std::cout << "s1: " << deserialized->s1 << std::endl;
    std::cout << "n: " << deserialized->n << std::endl;

    return 0;
}