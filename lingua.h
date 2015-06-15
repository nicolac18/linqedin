#ifndef LINGUA_H
#define LINGUA_H

#include <iostream>
#include <QXmlStreamWriter>

using namespace std;

class Lingua {
private:
   string lingua;

public:
   Lingua(string);

   // metodi getter
   string getLingua() const;

   // metodi writer
   void scrivi(QXmlStreamWriter&) const;
};

#endif // LINGUA_H
