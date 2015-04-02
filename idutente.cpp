#include "idutente.h"

IdUtente::IdUtente(string e, string p): email(e), password(p) {}

IdUtente::IdUtente(const IdUtente& i): email(i.email), password(i.password) {}

IdUtente::~IdUtente() {}

bool IdUtente::operator==(const IdUtente& i) const {
   return email== i.email && password== i.password;
}

void IdUtente::modificaEmail(string s) {
   email= s;
}

string IdUtente::getEmail() const {
   return email;
}
