#ifndef IDUTENTE_H
#define IDUTENTE_H

#include <iostream>

using namespace std;

class IdUtente {
private:
   string email;
   string password;

public:
   IdUtente(string, string= "");
   IdUtente(const IdUtente&);

   ~IdUtente();

   bool operator==(const IdUtente&) const;

   void modificaEmail(string);

   // metodi getter
   string getEmail() const;
};

#endif // IDUTENTE_H
