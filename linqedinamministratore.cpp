#include "linqedinamministratore.h"

LinQedInAmministratore::LinQedInAmministratore(DatabaseLinQedIn* d): db(d) {}

LinQedInAmministratore::~LinQedInAmministratore() {}


// inserisci utente
void LinQedInAmministratore::inserisciUtente(int tipo, string email, string nome, string cognome, QDate data) {

   IdUtente id1(email);
   Profilo p1(nome, cognome, data);

   switch (tipo) {
   case 1:
      db->inserisciUtente(UtenteBasic(id1,p1));
      break;
   case 2:
      db->inserisciUtente(UtenteBusiness(id1,p1));
      break;
   case 3:
      db->inserisciUtente(UtenteExecutive(id1,p1));
      break;
   default:
      return;
   }
}

// rimuovi utente
void LinQedInAmministratore::rimuoviUtente(string e) {
   Utente* u= &(*db->cercaUtente(e));
   if (u)
      db->rimuoviUtente(u->getId());
}

// rimuovi utente
void LinQedInAmministratore::rimuoviUtente(string n, string c) {
   Utente* u= &(*db->cercaUtente(n, c));
   if (u)
      db->rimuoviUtente(u->getId());
}

// cerca utente
Utente& LinQedInAmministratore::cercaUtente(string e) {
   DatabaseLinQedIn::Iteratore it= db->cercaUtente(e);
   return *it;
}

// cerca utente
Utente& LinQedInAmministratore::cercaUtente(string n, string c) {
   DatabaseLinQedIn::Iteratore it= db->cercaUtente(n, c);
   return *it;
}

void LinQedInAmministratore::cambiaTipoUtente(string e, int tipo) {
   Utente* u= &(*db->cercaUtente(e));
   if (u) {
      if (tipo== 0) {
         UtenteBasic* tmp= static_cast<UtenteBasic*>(u);
         db->rimuoviUtente(u->getId());
         db->inserisciUtente(UtenteBasic(*tmp));
         return;
      }

      else if (tipo== 1) {
         UtenteBusiness* tmp= static_cast<UtenteBusiness*>(u);
         db->rimuoviUtente(u->getId());
         db->inserisciUtente(UtenteBusiness(*tmp));
         return;
      }

      else if (tipo== 2) {
         UtenteExecutive* tmp= static_cast<UtenteExecutive*>(u);
         db-> rimuoviUtente(u->getId());
         db->inserisciUtente(UtenteExecutive(*tmp));
         return;
      }
   }
   return;
}


// metodi getter
DatabaseLinQedIn* LinQedInAmministratore::getDatabase() const {
   return const_cast<DatabaseLinQedIn*>(this->db);
}
