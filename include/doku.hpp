#ifndef doku_hpp
#define doku_hpp



#include <hucre.hpp>

class Doku
{
private:
    int verisayisi;
    int kapasite;
    Hucre* ilk;
    Hucre* son;
public:
    Doku();
    ~Doku();
    void ekle(int veri);                               // done 
    void cikar();                                      // done
    int getir(int index);                              // done
    void yazdir();                                     // done 


    /*sınıfın get ve set metodları*/
    int getkapasite();
    int getverisayisi();
    Hucre* getilk();
    Hucre* getson();
    void setkapasite(int kapasite);
    void setverisayisi(int verisayisi);
    void setilk(Hucre* ilk);
    void setson(Hucre* son);
};


#endif