#include <doku.hpp>

Doku::Doku()
{
    this->ilk = 0;
    this->son = 0;
    this->verisayisi = 0;
    this->kapasite = 10; 
}
Doku::~Doku()
{
    //cout<<ilk->getveri()<<" ile başlayan doku silinmiştir"<< endl;
    Hucre* gecici = ilk;
    while(gecici!=0)
    {
        Hucre* sil = gecici;
        gecici = gecici->getsonraki();
        delete sil;
    } 

}

void Doku::ekle(int veri)
{
    Hucre* yeni =new Hucre(veri);
    if(ilk == 0)
    {
        this->son = yeni;
        this->ilk=yeni;
        verisayisi++;
        return ;
    }
    Hucre* gecici = this->ilk;
    while(gecici->getsonraki()!=0)
    {
        gecici = gecici->getsonraki();
    }
    this->son = gecici->getsonraki();
    gecici->setsonraki(yeni);
    yeni->setonceki(gecici);
    verisayisi++;
}

void Doku:: cikar()
{
    if(verisayisi == 0)
    {
        cout << "çıkartılacak veri bulunmamaktadır"<< endl;
        return ;
    }
    if(verisayisi == 1)
    {
        delete ilk;
        ilk =0;
        son =0;
        verisayisi--;
        return;
    }
    delete ilk;
    ilk=ilk->getsonraki();
    ilk->setonceki(0);
    verisayisi--;
}

int Doku::getir(int index)
{
    if (index>=verisayisi)
    {
        cout <<"sadece "<<verisayisi<<" veri vardır"<<endl;
        return 0;
    }
    Hucre* gecici = ilk;
    for (int i = 0; i < index; i++)
    {
        gecici =gecici->getsonraki();
        
    }
    return gecici->getveri();
}

void Doku:: yazdir()
{
    cout <<setw(12)<<"veri"<<setw(12)<<"adres"<<setw(12)<<"onceki"<<setw(12)<<"sonraki"<<endl;
    Hucre* gecici = this->ilk;
    while (gecici!=0)
    {
        cout <<setw(12)<<gecici->getveri()<<setw(12)<<gecici<<setw(12)<<gecici->getonceki()<<setw(12)<<gecici->getsonraki()<<endl;
        gecici = gecici->getsonraki();
    }
    cout << endl;
}

/*sınıfın get ve set metodları*/
int Doku::getkapasite()
{
    return this->kapasite;
}
int Doku::getverisayisi()
{
    return this->verisayisi;
}
Hucre* Doku::getilk()
{
    return this->ilk;
}
Hucre* Doku::getson()
{
    return this->son;
}
void Doku::setkapasite(int kapasite)
{
    this->kapasite = kapasite;
}
void Doku::setverisayisi(int verisayisi)
{
    this->verisayisi = verisayisi;
}
void Doku::setilk(Hucre* ilk)
{
    this->ilk = ilk;
}
void Doku::setson(Hucre* son)
{
    this->son = son;
}