#include <organizma.hpp>

Organizma::Organizma()
{
    this->ilk = 0;
    this->son = 0;
    this->verisayisi = 0;
}
Organizma::~Organizma()
{
    Sistemnode* gecici = ilk;
    cout << gecici->getveri()<< endl;
    while(gecici!=0)
    {
        Sistemnode* sil = gecici;
        gecici = gecici->getsonraki();
        delete sil;
    } 
    //cout <<"ilk dizizsinin ilk verisi  "<<this->ilk->getveri()->getir(0);
    //cout << "  olan dizi listesi silindi"<< endl;
        
}


void Organizma::ekle(Sistem* veri)
{   
    Sistemnode* yeni = new Sistemnode(veri);
    if(ilk == 0)
    {
        this->son = yeni;
        this->ilk = yeni;
        verisayisi++;
        return;
    }
    Sistemnode* gecici = this->ilk;
    while(gecici->getsonraki()!=0)
    {
        gecici=gecici->getsonraki();
    }
    this->son = gecici->getsonraki();
    gecici->setsonraki(yeni);
    yeni->setonceki(gecici);
    verisayisi++;
}
Sistem* Organizma::getir(int index)
{
    if(index >= verisayisi)
    {
        cout << "sadece "<< verisayisi << " dizi vardır"<< endl;
        return 0;
    }
    Sistemnode* gecici = ilk;
    for (int i = 0; i < index; i++)
    {
        gecici = gecici->getsonraki();
    }
    return gecici->getveri();
}
void Organizma::yazdir()
{
    cout <<setw(15)<<"veri"<<setw(15)<<"adres"<<setw(15)<<"onceki"<<setw(15)<<"sonraki"<<endl;
    Sistemnode* gecici = this->ilk;
    while(gecici!=0)
    {
        cout <<setw(15)<<gecici->getveri()->getir(0)<<setw(15)<<gecici->getveri()<<setw(15)<<gecici->getonceki()<<setw(15)<<gecici->getsonraki()<<endl;
        gecici = gecici->getsonraki();
    }
    cout << endl;
}

/*sınıfın get ve set metodları */
int Organizma::getverisayisi()
{
    return this->verisayisi;
}
Sistemnode* Organizma::getilk()
{
    return this->ilk;
}
Sistemnode* Organizma::getson()
{
    return this->son;
}
void Organizma::setverisaayisi(int verisayisi)
{
    this->verisayisi = verisayisi;
}
void Organizma::setilk(Sistemnode* ilk)
{
    this->ilk = ilk;
}
void Organizma::setson(Sistemnode* son)
{
    this->son = son;
}