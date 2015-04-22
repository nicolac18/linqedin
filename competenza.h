#ifndef COMPETENZA_H
#define COMPETENZA_H

#include <iostream>
#include <QXmlStreamWriter>

using namespace std;

class Competenza {
private:
   string competenza;

public:
   Competenza(string);

   string getCompetenza() const;

   // metodi writer
   void scrivi(QXmlStreamWriter&) const;
};

#endif // COMPETENZA_H
