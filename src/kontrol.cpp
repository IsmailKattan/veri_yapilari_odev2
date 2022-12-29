#include <kontrol.hpp>

Kontrol::Kontrol()
{
    this->markline=1;
}

Sistem* Kontrol::sistemolustur()
{
    Sistem* sistem = new Sistem();
    for (int i = 1; i <= 100; i++)
    {
        Radix* organveri = new Radix();
        Organ* organ = new Organ();
        for (int j = 0; j < 20; j++)
        {
            organ->ekle(organveri->kuyrukolusturvesirala(markline));
            markline++;
        }
        sistem->ekle(organ->avlmi());
        if (organ->avlmi())
            cout<<" ";
        else
            cout <<"#"; 
        
        delete organveri;
        delete organ;
    }
    return sistem;
}

Organizma* Kontrol::organizmaolustur()
{   
    
    Organizma* o = new Organizma();
    string line;
    int sayac=0;
    fstream dosya;
    dosya.open("veri.txt",ios::in);// read
    if (dosya.is_open())
    {
        while (getline(dosya,line))
        {
            sayac++;
        }
        dosya.close();
    }
    for (int i = 0; i < sayac/2000; i++)
    {
        o->ekle(sistemolustur());
        cout <<endl;
    }
    o->yazdir();
    return o;
}
// string Kontrol:: oku()
// {
//     fstream dosya;
//     string line;
//     dosya.open("veriler.txt",ios::in);// read
//     if (dosya.is_open())
//     {   
        
//         int sayac = 0;
//         Sistem* sistem = new Sistem();
//         Radix* organveri = new Radix();
//         Organ* organ = new Organ();
//         Organizma* organizma = new Organizma();
//         while(getline(dosya,line))
//         {
//             line = line+" ";
//             organ->ekle(organveri->kuyrukolusturvesirala(line));
//             if((sayac+1)%20==0)
//             {
//                 //sistem->ekle(organ->avlmi());
//                 //organ->postorder();
//                 //sistem->yazdir();
//                 //cout<< endl;
//                 organ->postordercebosalt();
//                 cout << " fuck"<< endl;
                
//             }
//             if((sayac+1)%2000==0)
//             {
//                 sistem->yazdir();
//                 cout<<"n"<<endl;
//             }
//            sayac++;
//         }
        
            
        
//     }
//     dosya.close();
    
//     return line;
// }