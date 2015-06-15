#ifndef UTENTEBASIC_H
#define UTENTEBASIC_H

#include "utente.h"

#include <iostream>
#include <QXmlStreamWriter>

class UtenteBasic: public Utente {
public:
   UtenteBasic(IdUtente, Profilo);
   UtenteBasic(const UtenteBasic&);
   ~UtenteBasic();

   void ricerca(DatabaseLinQedIn&, string, QList<QString>&);

   // metodi getter
   string getTipo() const;

   // metodi writer
   void scrivi(QXmlStreamWriter&) const;
};

#endif // UTENTEBASIC_H
