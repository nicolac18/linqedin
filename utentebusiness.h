#ifndef UTENTEBUSINESS_H
#define UTENTEBUSINESS_H

#include "utentebasic.h"

#include <iostream>
#include <QXmlStreamWriter>

class UtenteBusiness: public UtenteBasic {
public:
   UtenteBusiness(IdUtente, Profilo);
   ~UtenteBusiness();

   void ricerca(DatabaseLinQedIn&, string, QList<QString>&);

   // metodi getter
   string getTipo() const;

   // metodi writer
   void scrivi(QXmlStreamWriter&) const;
};

#endif // UTENTEBUSINESS_H
