#include "utentebusiness.h"

UtenteBusiness::UtenteBusiness(IdUtente u, Profilo p): UtenteBasic(u, p) {}

UtenteBusiness::~UtenteBusiness() {}

void UtenteBusiness::ricerca(DatabaseLinQedIn& db, string s, QList<QString>& l) {
   Utente* u= *(db.cercaUtente(s));
   Utente::RicercaFuntore sf(2);
   sf(u, l);
}

void UtenteBusiness::scrivi(QXmlStreamWriter& stream) const {
   stream.writeAttribute("tipo", "business");
   Utente::scrivi(stream);
}
