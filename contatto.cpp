#include "contatto.h"

Contatto::Contatto(string i): id(i) {}

Contatto::~Contatto() {}

string Contatto::getContatto() const {
   return id;
}
