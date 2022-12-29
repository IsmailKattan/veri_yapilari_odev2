#include <sistemnode.hpp>

Sistemnode::Sistemnode(Sistem* veri)
{
    this->onceki = 0;
    this->sonraki = 0;
    this->veri = veri;
}
Sistemnode::~Sistemnode()
{
    //cout << "ilk verisi  "<< this->veri->getir(0) << " olan  dizi silindi";
    //cout <<"  "<< endl;
}



/*sınıfın get ve set fonksiyonları*/
Sistemnode* Sistemnode::getonceki()
{
    return this->onceki;
}
Sistemnode* Sistemnode::getsonraki()
{
    return this->sonraki;
}
Sistem* Sistemnode::getveri()
{
    return this->veri;
}
void Sistemnode::setonceki(Sistemnode* once)
{
    this->onceki = once; 
}
void Sistemnode::setsonraki(Sistemnode* sonra)
{
    this->sonraki = sonra;
}
void Sistemnode::setveri(Sistem* vveri)
{
    this->veri = vveri;
}
