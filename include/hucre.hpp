#ifndef hucre_hpp
#define hucre_hpp

#include <iostream>
#include <iomanip>
using namespace std;

class Hucre
{
private:
    int veri; 
    Hucre* onceki;
    Hucre* sonraki;
    Hucre* sag;
    Hucre* sol;
public:
    Hucre(int veri);
    ~Hucre();
    /*sınıfın get ve set fonksiyonları*/ 
    Hucre* getsonraki();
    Hucre* getonceki();
    Hucre* getsag();
    Hucre* getsol();
    int getveri();
    void setsonraki(Hucre* sonraki);
    void setonceki(Hucre* sonraki);
    void setsag(Hucre* sag);
    void setsol(Hucre* sol);
    void setveri(int veri);
};

#endif