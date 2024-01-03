#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>

struct Data 
{
    void    *content;
};

class   Serializer
{
    public :
        Serializer();
        ~Serializer();
        Serializer(const Serializer & copy);
        Serializer & operator=(const Serializer & assign);

        static uintptr_t serialize(Data* ptr);
        static Data * deserialize(uintptr_t raw);
    private :
        
};

#endif