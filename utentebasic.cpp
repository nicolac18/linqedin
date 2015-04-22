#include "utentebasic.h"

UtenteBasic::UtenteBasic(IdUtente u, Profilo p): Utente(u, p) {}

UtenteBasic::UtenteBasic(const UtenteBasic& u): Utente(u) {}

UtenteBasic::~UtenteBasic() {}

void UtenteBasic::ricerca(DatabaseLinQedIn& db, string s, QList<QString>& l) {
   Utente* u= *(db.cercaUtente(s));
   Utente::RicercaFuntore sf(1);
   sf(u, l);
}

void UtenteBasic::scrivi(QXmlStreamWriter& stream) const {
   stream.writeAttribute("tipo", "basic");
   Utente::scrivi(stream);
}
