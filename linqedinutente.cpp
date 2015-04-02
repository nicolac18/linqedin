#include "linqedinutente.h"

LinQedInUtente::LinQedInUtente(DatabaseLinQedIn* d, Utente& x): db(d), u(x) {}

LinQedInUtente::~LinQedInUtente() {}

void LinQedInUtente::modificaId(string s) {
   u.getIdUtente().modificaEmail(s);
}

// metodi di modifica dati
void LinQedInUtente::modificaNome(string s) {
   u.getProfilo().modificaNome(s);
}

void LinQedInUtente::modificaCognome(string s) {
   u.getProfilo().modificaCognome(s);
}

void LinQedInUtente::modificaDataDiNascita(QDate q) {
   u.getProfilo().modificaDataDiNascita(q);
}

void LinQedInUtente::modificaEmailSecondaria(string s) {
   u.getProfilo().modificaEmail(s);
}

// metodi di inserimento dati
void LinQedInUtente::aggiungiEmail(string s) {
   u.getProfilo().aggiungiEmail(s);
}

void LinQedInUtente::aggiungiTitoloDiStudio(TitoloDiStudio t) {
   u.getProfilo().aggiungiTitoloDiStudio(t);
}

void LinQedInUtente::aggiungiLingua(string s) {
   u.getProfilo().aggiungiLingua(s);
}

void LinQedInUtente::aggiungiCompetenza(string s) {
   u.getProfilo().aggiungiCompetenza(s);
}

void LinQedInUtente::aggiungiEsperienzaProfessionale(EsperienzaProfessionale e) {
   u.getProfilo().aggiungiEsperienzaProfessionale(e);
}

// metodi rete di contatti
void LinQedInUtente::aggiungiContatto(string s) {
   u.aggiungiContatto(s);
}

void LinQedInUtente::rimuoviContatto(string s) {
   u.rimuoviContatto(s);
}

// metodo di ricerca

// metodi getter
Utente& LinQedInUtente::getUtente() const {
   return const_cast<Utente&>(this->u);
}

