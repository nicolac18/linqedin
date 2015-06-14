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

// metodi di rimozione dati
void LinQedInUtente::rimuoviEmail() {
   u.getProfilo().rimuoviEmailSecondaria();
}

void LinQedInUtente::rimuoviTitoloDiStudio(int i) {
   u.getProfilo().rimuoviTitoloDiStudio(i);
}

void LinQedInUtente::rimuoviLingua(int i) {
   u.getProfilo().rimuoviLingua(i);
}

void LinQedInUtente::rimuoviCompetenza(int i) {
   u.getProfilo().rimuoviCompetenza(i);
}

void LinQedInUtente::rimuoviEsperienzaProfessionale(int i) {
   u.getProfilo().rimuoviEsperienzaProfessionale(i);
}

// metodi rete di contatti
void LinQedInUtente::aggiungiContatto(string s) {
   u.aggiungiContatto(s);
}

void LinQedInUtente::rimuoviContatto(string s) {
   u.rimuoviContatto(s);
}

// metodo di ricerca
void LinQedInUtente::cerca(string n, string c, string& id, QList<QString>& list) {
   Utente* tmp= *(db->cercaUtente(n, c));
   if (tmp!= 0) {
      id= tmp->getId();
      u.ricerca(*db, tmp->getId(), list);
   }
}

// metodi getter
Utente& LinQedInUtente::getUtente() const {
   return const_cast<Utente&>(this->u);
}

