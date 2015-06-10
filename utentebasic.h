#ifndef UTENTEBASIC_H
#define UTENTEBASIC_H

#include <iostream>
#include <QXmlStreamWriter>

#include "utente.h"

class UtenteBasic: public Utente {
public:
   UtenteBasic(IdUtente, Profilo);
   UtenteBasic(const UtenteBasic&);
   ~UtenteBasic();

   void ricerca(DatabaseLinQedIn&, string, QList<QString>&);

   string getTipo() const;

   void scrivi(QXmlStreamWriter&) const;
};

#endif // UTENTEBASIC_H
