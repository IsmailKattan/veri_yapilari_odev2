#include <sistem.hpp>
Sistem::Sistem()
{
    this->dizi=new int[150];
    verisayisi  = 0;
}
Sistem::~Sistem()
{
    delete[] dizi;
}
void Sistem::ekle(int veri)
{
    dizi[verisayisi] = veri;
    verisayisi++;
}
int Sistem::getir(int index)
{
    if(index<verisayisi&&index>=0)
        return dizi[index];
    else 
        cout << index << ". indexte verri bulunmamaktadır "<< endl;
}
void Sistem:: bosalt()
{
    delete[] dizi;
    verisayisi=0;
}
void Sistem::yazdir()
{
    for (int i = 0; i < this->verisayisi; i++)
    {
        if(dizi[i])
            cout <<" ";
        else
            cout<<"#"; 
    }
    cout <<endl;
}
int Sistem::getverisayisi()
{
    return this->verisayisi;
}


    // dinamikDizi()
	// {
	// 	m_boyut = 5;
	// 	m_adres = new int[m_boyut];
	// 	m_kullanilan = 0;
	// }
	// ~dinamikDizi()
	// {
	// 	delete[] m_adres;
	// }
	// int elemanGetir(int sira) const
	// {
	// 	if (sira >= boyut() || sira < 0)
	// 	{

	// 	}
	// 	return m_adres[sira];
	// }
	// int boyut() const
	// {
	// 	return m_boyut;
	// }
	// int kullanilan() const
	// {
	// 	return m_kullanilan;
	// }
	// int* adress() const
	// {
	// 	return m_adres;
	// }
    // void diziSil()
	// {
	// 	delete[] m_adres;
	// }
    