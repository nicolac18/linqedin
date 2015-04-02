#include "retesociale.h"

ReteSociale::ReteSociale() {}

ReteSociale::ReteSociale(const ReteSociale& r): utenti(r.utenti) {}

ReteSociale::~ReteSociale() {}

void ReteSociale::aggiungiUtente(Utente* u) {
   utenti.push_back(u);
}

void ReteSociale::rimuoviUtente(Utente* u) {
   utenti.remove(u);
}

//vector<string> ReteSociale::getUtenti() const {
//   vector<string> tmp;
//   list<Utente*>::const_iterator it;
//   for (it= utenti.begin(); it!=utenti.end(); ++it)
//      tmp.push_back((**it).getId());
//   return tmp;
//}
