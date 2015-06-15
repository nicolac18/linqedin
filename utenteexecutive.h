#ifndef UTENTEEXECUTIVE_H
#define UTENTEEXECUTIVE_H

#include "utentebusiness.h"

class UtenteExecutive: public UtenteBusiness {
public:
   UtenteExecutive(IdUtente, Profilo);
   ~UtenteExecutive();

   void ricerca(DatabaseLinQedIn&, string, QList<QString>&);

   // metodi getter
   string getTipo() const;

   // metodi writer
   void scrivi(QXmlStreamWriter&) const;
};

#endif // UTENTEEXECUTIVE_H
