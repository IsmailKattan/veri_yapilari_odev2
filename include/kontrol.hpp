#ifndef kontrol_hpp
#define kontrol_hpp

#include <organizma.hpp>
#include <sstream>

class Kontrol
{
private:
    int markline;

public:
    Kontrol();
    ~Kontrol();
    Sistem* sistemolustur();
    Organizma* organizmaolustur();
    
};



#endif