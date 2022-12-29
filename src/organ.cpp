#include <organ.hpp>


Organ::Organ()
{
    kok = new Hucre(0);
}
Organ::~Organ()
{
    postordercebosalt(kok);
    delete kok;
}
bool Organ::varmi(int veri)
{
    return varmi(veri,kok);
}

bool Organ :: varmi(int aranan,Hucre* aktif)
{
    if(aktif->getveri()<aranan)
    {
        if(aktif->getsag())
            return varmi(aranan,aktif->getsag());

        return false;
    }
    else if (aktif->getveri()>aranan)
    {
        if(aktif->getsol())
            return varmi(aranan,aktif->getsol());
        
        return false;
    }
    else 
        return true;
}

void Organ::ekle(int veri)
{
    //cout <<"welcome to ekle "<<endl;
    if(kok->getveri()==0)
    {
        kok->setveri(veri);
        return;
    }
    ekle(veri,kok);
    //cout << endl;
}

void Organ::ekle(int veri,Hucre* aktif)
{
    
    if (aktif->getveri()>=veri)
    {
        //cout <<"sol ";
        if(aktif->getsol()==NULL)
        {
            aktif->setsol(new Hucre(veri));
        }
        else
        {
            ekle(veri,aktif->getsol());
        }
    }
    else 
    {
        //cout << "sag ";
        if(aktif->getsag()==NULL)
        {
            aktif->setsag(new Hucre(veri));
        }
        else
        {
            ekle(veri,aktif->getsag());
        }
    }
    
//     //cout <<"welcome to ekle"<<endl;
//     if(aktif->getveri()>=veri)
//     {
//         //cout <<"aktif->getveri()>=veri : " <<"aktif->getveri()  = "<< aktif->getveri()<<"  veri  = "<<veri<<endl;
//         if(aktif->getsol())
//         {
//             ekle(veri,aktif->getsol());
//         }
//         else
//         {
//             aktif->setsol(new Hucre(veri));      // burdan hata çıkabilir
//             //cout<<"sola eklendi"<<endl;
//         }
//     }
//     else if(aktif->getveri()<veri)
//     {
//         //cout <<"aktif->getveri()<veri : " <<"aktif->getveri()  = "<< aktif->getveri()<<"  veri  = "<<veri<<endl;
//         if(aktif->getsag())
//         {
//             ekle(veri,aktif->getsag());
//         }
//         else 
//         {
//             aktif->setsag(new Hucre(veri));    // burdan hata çıkabilir
//             //cout <<"saga eklendi " << endl;
//         }
//     }
// 
}

void Organ::postordercebosalt(Hucre* aktif)
{
    if(aktif)
    {
        postordercebosalt(aktif->getsol());
        postordercebosalt(aktif->getsag());
        delete aktif;
        aktif=0;
    }
    
}
void Organ:: postordercebosalt()
{
    postordercebosalt(this->kok);
}

void Organ::postorder(Hucre* akrif)
{
    if (akrif)
    {
        postorder(akrif->getsol());
        postorder(akrif->getsag());
        cout << akrif->getveri()<<" ";
    }
}
void Organ:: postorder()
{
    postorder(this->kok);
}
int Organ::yukseklik(Hucre* aktif)
{

    if(aktif)
    {
        return 1+max(yukseklik(aktif->getsag()),yukseklik(aktif->getsol()));
    }
    return -1;
}



int Organ::avlmi()
{
    int sagyukseklik = yukseklik(kok->getsag());
    int solyukseklik = yukseklik(kok->getsol());
    if(sagyukseklik-solyukseklik==-1||sagyukseklik-solyukseklik==0||sagyukseklik-solyukseklik==1)
        return 1;
    else    
        return 0;
}
// {
//     Hucre* sag = kok->getsag();
//     Hucre* sol = kok->getsol();
//     int sagYuksaklik = yukseklik(sag);
//     int solYuksaklik = yukseklik(sol);
//     //if(abs(sagYuksaklik-solYuksaklik)<=1)
//     cout << sol<<setw(12)<<sag<<setw(12);
//     cout <<solYuksaklik<<setw(12)<<sagYuksaklik<<setw(12);
//     cout << abs((abs(sagYuksaklik))-(abs(solYuksaklik)));
//     if(abs((sagYuksaklik)-(solYuksaklik))<=1)
//         return 1;
//     return 0;
// }
