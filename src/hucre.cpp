#include <hucre.hpp>
#include <vector>

Hucre::Hucre(int veri)
{
    this->veri = veri;
    this->sonraki = 0;
    this->onceki = 0;
    this->sag = 0;
    this->sol = 0;
}
Hucre::~Hucre()
{
    //cout <<this->veri <<" veriye sahip hücre silindi "<< endl;
}



/*sınıfın get ve set sınıfları*/
Hucre* Hucre::getsonraki()
{
    return this->sonraki;
}
Hucre* Hucre::getonceki()
{
    return this->onceki;
}
Hucre* Hucre:: getsag()
{
    return this->sag;
}
Hucre* Hucre::getsol()
{
    return this->sol;
}
int Hucre::getveri()
{
    return this->veri;
}
void Hucre:: setsonraki(Hucre* sonraki)
{
    this->sonraki = sonraki; 
}
void Hucre:: setonceki(Hucre* onceki)
{
    this->onceki = onceki;
}
void Hucre:: setsag(Hucre* sag)
{
    this->sag = sag; 
}
void Hucre:: setsol(Hucre* sol)
{
    this->sol = sol;
}
void Hucre::setveri(int veri)
{
    this->veri = veri ;
}
