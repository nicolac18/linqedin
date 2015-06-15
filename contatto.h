#ifndef CONTATTO_H
#define CONTATTO_H

#include <iostream>

using namespace std;

class Contatto {
private:
   string id;

public:
   Contatto(string);
   ~Contatto();

   // metodi getter
   string getContatto() const;
};

#endif // CONTATTO_H
