#ifndef sistem_hpp
#define sistem_hpp

#include <radix.hpp>
#include <organ.hpp>
class Sistem
{
private:

    int* dizi;
    int verisayisi;
public:
    Sistem();
    ~Sistem();
    void ekle(int veri);
    int getir(int index);
    void bosalt();
    void yazdir();
    int getverisayisi();
};



#endif