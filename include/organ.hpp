#ifndef organ_hpp
#define organ_hpp


#include <doku.hpp>


#include<math.h>

class Organ
{
private:
    int satirtut;
    Hucre* kok;
    bool varmi(int aranan ,Hucre* aktif);
    void ekle(int veri , Hucre* aktiif);
    void postorder(Hucre* akrif);
    void postordercebosalt(Hucre* aktif);
public:
    Organ();
    ~Organ();
    bool varmi(int veri);
    void ekle(int veri);
    void postorder();
    void postordercebosalt();
    int avlmi();
    int yukseklik(Hucre* aktif);
    
};




#endif