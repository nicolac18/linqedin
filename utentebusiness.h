#ifndef UTENTEBUSINESS_H
#define UTENTEBUSINESS_H

#include <iostream>
#include <QXmlStreamWriter>

#include "utentebasic.h"

class UtenteBusiness: public UtenteBasic {
public:
   UtenteBusiness(IdUtente, Profilo);
   ~UtenteBusiness();

   void ricerca(DatabaseLinQedIn&, string, QList<QString>&);

   void scrivi(QXmlStreamWriter&) const;
};

#endif // UTENTEBUSINESS_H
