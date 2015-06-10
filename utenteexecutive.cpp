#include "utenteexecutive.h"

UtenteExecutive::UtenteExecutive(IdUtente u, Profilo p): UtenteBusiness(u, p) {}

UtenteExecutive::~UtenteExecutive() {}

void UtenteExecutive::ricerca(DatabaseLinQedIn& db, string s, QList<QString>& l) {
   Utente* u= *(db.cercaUtente(s));
   Utente::RicercaFuntore sf(3);
   sf(u, l);
}

string UtenteExecutive::getTipo() const {
   return "Executive";
}

void UtenteExecutive::scrivi(QXmlStreamWriter& stream) const {
   stream.writeAttribute("tipo", "executive");
   Utente::scrivi(stream);
}
