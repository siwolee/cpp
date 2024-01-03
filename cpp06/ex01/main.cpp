#include "Serializer.hpp"

int main()
{    
    int *content = new int(37);

    Data *data = new Data;
    data->content = content;

    uintptr_t   raw = Serializer::serialize(data);
    Data *new_data = Serializer::deserialize(raw);
    
    std::cout << "original data : " << data << std::endl;
    std::cout << "-> data ptr   : " << data->content << std::endl;
    std::cout << "-> data       : " << *(reinterpret_cast<int *> (data->content)) << std::endl;
    std::cout << "serialized    : " << raw << std::endl;
    std::cout << "deserialized  : " << new_data << std::endl;
    std::cout << "-> data ptr   : " << new_data->content << std::endl;
    std::cout << "-> data       : " << *(reinterpret_cast<int *> (new_data->content)) << std::endl;

    delete content;
    delete data;
}