#ifndef organizma_hpp
#define organizma_hpp

#include <sistemnode.hpp>

class Organizma
{
private:
    int verisayisi; 
    Sistemnode* ilk;
    Sistemnode* son; 
public:
    Organizma();
    ~Organizma();
    void ekle(Sistem* veri);
    Sistem* getir(int index);
    void yazdir();

    /*sınıfın get ve set metodları */
    int getverisayisi();
    Sistemnode* getilk();
    Sistemnode* getson();
    void setverisaayisi(int verisayisi);
    void setilk(Sistemnode* ilk);
    void setson(Sistemnode* son);
};



#endif