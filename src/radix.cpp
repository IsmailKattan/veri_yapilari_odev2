#include<radix.hpp>
Radix ::Radix()
{
    this->kuyruk = new Doku();
    for (int i = 0; i < 10; i++)
    {
        this->kuyruklar[i]= new Doku();
    }
}
Radix :: ~Radix()
{
    delete kuyruk;
    for (int i = 0; i < 10; i++)
    {
        delete kuyruklar[i];
    }
}
string Radix:: oku(int satirno)
{
    string line;
    fstream dosya;
    dosya.open("veri.txt",ios::in);// read
    if (dosya.is_open())
    {
        for (int i = 0; i < satirno; i++)
        {
            getline(dosya,line);
        }
        dosya.close();
        
    }
    line=line+" ";
    // fstream dosya;
    // string line;
    // dosya.open("veriler.txt",ios::in);// read
    // if (dosya.is_open())
    // {   
        
        
        
            
        
    // }
    // dosya.close();
    
    return line;
}

int Radix:: kuyrukolusturvesirala(int satirno)
{
    delete kuyruk;
    for (int i = 0; i < 10; i++)
    {
        delete kuyruklar[i];
        kuyruklar[i]=new Doku();
    }
    kuyruk = new Doku();   
    string str = oku(satirno);
    int sayac = 0;
    int maxbasamak = 0;
    string kelime = "";
    for (auto x : str)
    { 
        
        if(x==' ')
        {
            this->kuyruk->ekle(stoi(kelime));
            kelime = "";
            if(maxbasamak<sayac)
            {
                maxbasamak=sayac;
            }
            sayac = 0;
        }
        else 
        {
            sayac++;
            kelime = kelime+x;
        }
    }
    
    return sirala(*kuyruk,maxbasamak);
}

int Radix::sirala(Doku &siralanacak, int basamaksayisi)
{
    Doku* gecici = &siralanacak;                            // siralanacak kuyruk geciciye atıldı
    Doku* kalantutacak = new Doku();
    //*gecici = siralanacak;                            
    for (int k = 0; k < basamaksayisi; k++)                // basamak sayisi kadar dönecek 
    {   
        for (int i = 0; i < gecici->getverisayisi(); i++)               // kalantutacak sırayla basamakları saklıyor
        {
            kalantutacak->ekle((gecici->getir(i))%kuvvetal(10,k+1)/(kuvvetal(10,k)));
        }
        
        for(int i = 0;gecici->getverisayisi()>0;i++)                           // veriler geciciden kuyruklara taşınır sonra kalantutacak ve gecici boşatılır  
        {
            kuyruklar[kalantutacak->getir(0)]->ekle(gecici->getir(0));
            gecici->cikar();
            kalantutacak->cikar();
        }

        for (int i = 0 ; i < 10; i++)                                 // veriler kuyruklardan geciciye taşınır sonra kuyruklar boşatılır         
        {   
            int j=0 ;
            while (kuyruklar[i]->getverisayisi()>0)
            {  
                
                gecici->ekle(kuyruklar[i]->getir(0));
                kuyruklar[i]->cikar();
                j++;
            }
        }

    }

    siralanacak = *gecici;
    delete kalantutacak;
    return siralanacak.getir((siralanacak.getverisayisi()/2));
}

int Radix::kuvvetal(int taban,int kuvvet)
{
    int sonuc = 1;
    for (int i = 0; i < kuvvet; i++)
    {
        sonuc = sonuc*taban;
    }
    return sonuc;
}

// 