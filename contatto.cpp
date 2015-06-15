#include "contatto.h"

Contatto::Contatto(string i): id(i) {}

Contatto::~Contatto() {}

// metodi getter
string Contatto::getContatto() const {
   return id;
}
