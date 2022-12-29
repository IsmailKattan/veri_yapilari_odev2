#ifndef sistemnode_hpp
#define sistemnode_hpp

#include <sistem.hpp>

class Sistemnode
{
private:
    Sistemnode* onceki;
    Sistemnode* sonraki;
    Sistem* veri;    
public:
    Sistemnode(Sistem* veri);
    ~Sistemnode();



    /*get ve set foksiyonlari*/
    Sistemnode* getonceki();
    Sistemnode* getsonraki();
    Sistem* getveri();
    void setonceki(Sistemnode* once);
    void setsonraki(Sistemnode* sonra);
    void setveri(Sistem* vveri);
};



#endif