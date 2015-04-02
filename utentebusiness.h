#ifndef UTENTEBUSINESS_H
#define UTENTEBUSINESS_H

#include "utentebasic.h"

class UtenteBusiness: public UtenteBasic {
public:
   UtenteBusiness(IdUtente, Profilo);
   ~UtenteBusiness();

   void ricerca(DatabaseLinQedIn&, string, QList<QString>&);
};

#endif // UTENTEBUSINESS_H
