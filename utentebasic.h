#ifndef UTENTEBASIC_H
#define UTENTEBASIC_H

#include "utente.h"

class UtenteBasic: public Utente {
public:
   UtenteBasic(IdUtente, Profilo);
   UtenteBasic(const UtenteBasic&);
   ~UtenteBasic();

   void ricerca(DatabaseLinQedIn&, string, QList<QString>&);
};

#endif // UTENTEBASIC_H
