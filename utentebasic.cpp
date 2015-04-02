#include "utentebasic.h"

UtenteBasic::UtenteBasic(IdUtente u, Profilo p): Utente(u, p) {}

UtenteBasic::UtenteBasic(const UtenteBasic& u): Utente(u) {}

UtenteBasic::~UtenteBasic() {}

void UtenteBasic::ricerca(DatabaseLinQedIn& db, string s, QList<QString>& l) {
   Utente* u= &(*(db.cercaUtente(s)));
   Utente::RicercaFuntore sf(1);
   sf(u, l);
}
