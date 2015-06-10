#include "databaselinqedin.h"

// ##### definizioni classe Iteratore
// operatore uguaglianza
bool DatabaseLinQedIn::Iteratore::operator==(const Iteratore& i) const {
   return idi== i.idi;
}

// operatore disuguaglianza
bool DatabaseLinQedIn::Iteratore::operator!=(const Iteratore& i) const {
   return idi!= i.idi;
}

// incremento prefisso
DatabaseLinQedIn::Iteratore& DatabaseLinQedIn::Iteratore::operator++() {
   if (idi!= 0)
      idi= idi->next.di;
   return *this;
}

// incremento postfisso
DatabaseLinQedIn::Iteratore& DatabaseLinQedIn::Iteratore::operator++(int) {
   Iteratore aux= *this;
   if (idi)
      idi= idi->next.di;
   return aux;
}

// operatore di dereferenziazione
Utente* DatabaseLinQedIn::Iteratore::operator*() const {
   return idi->info;
}


// ##### definizioni classe DatabaseLinQedIn
// costruttore
DatabaseLinQedIn::DatabaseLinQedIn(): primo(0) {}

// costruttore di copia
DatabaseLinQedIn::DatabaseLinQedIn(DatabaseLinQedIn& d): primo(d.primo) {}

// distruttore
DatabaseLinQedIn::~DatabaseLinQedIn() {}

// begin
DatabaseLinQedIn::Iteratore DatabaseLinQedIn::begin() const {
    Iteratore tmp;
    tmp.idi= primo.di;
    return tmp;
}

// end
DatabaseLinQedIn::Iteratore DatabaseLinQedIn::end() const {
    Iteratore tmp;
    tmp.idi= 0;
    return tmp;
}

// operatore di indicizzazione
DatabaseLinQedIn::DatabaseItem& DatabaseLinQedIn::operator [] (DatabaseLinQedIn::Iteratore it) const {
    return *(it.idi);
}

// è vuoto?
bool DatabaseLinQedIn::isEmpty() const {
    return (primo== 0);
}

// inserimento utente
bool DatabaseLinQedIn::inserisciUtente(Utente* u) {
   if (cercaUtente(u->getId())== this->end()) {  // ==> no duplicati
      primo= new DatabaseItem(*u, primo);
      return true;
   }
   return false;
}

// rimozione utente
bool DatabaseLinQedIn::rimuoviUtente(string id) {
   Iteratore it= this->begin(), itPrec= this->begin();
   if (it.idi->info->getId()== id) {   // primo elemento
      primo= primo->next;
      return true;
   }
   ++it;
   while (it!= this->end()) {    // elementi successivi
      if (it.idi->info->getId()== id) {
         itPrec.idi->next= it.idi->next;
         return true;
      }
      ++it;
      ++itPrec;
   }
   return false;
}

// cerca utente
DatabaseLinQedIn::Iteratore DatabaseLinQedIn::cercaUtente(string id) {
   Iteratore it= this->begin();
   while (it!= this->end()) {
      if ((*it)->getId()== id)
         return it;
      ++it;
   }
   return this->end();
}

// cerca utente
DatabaseLinQedIn::Iteratore DatabaseLinQedIn::cercaUtente(string n, string c) {
   Iteratore it= this->begin();
   while (it!= this->end()) {
      if ((*it)->getProfilo().getNome()== n && (*it)->getProfilo().getCognome()== c) {
         return it;
      }
      ++it;
   }
   return this->end();
}


// ##### definizioni classe Smartp
// costruttore
DatabaseLinQedIn::Smartp::Smartp(DatabaseItem* p): di(p) {
   if (di)
      di->riferimenti++;
}

// distruttore
DatabaseLinQedIn::Smartp::~Smartp() {
   if (di) {
      di->riferimenti--;
      if (di->riferimenti== 0)
         delete di;
   }
}

// costruttore di copia
DatabaseLinQedIn::Smartp::Smartp(const Smartp &s): di(s.di) {
   if (di)
      di->riferimenti++;
}

// assegnazione
DatabaseLinQedIn::Smartp& DatabaseLinQedIn::Smartp::operator=(const Smartp &s) {
   if (*this!= s) {
      DatabaseItem* t= di;
      di= s.di;
      if (di)
         di->riferimenti++;
      if (t) {
         t->riferimenti--;
         if (t->riferimenti== 0)
            delete t;
      }
   }
   return *this;
}

// dereferenziazione
DatabaseLinQedIn::DatabaseItem& DatabaseLinQedIn::Smartp::operator*() const {
   return const_cast <DatabaseItem&> (*di);
}

// selezione membro
DatabaseLinQedIn::DatabaseItem* DatabaseLinQedIn::Smartp::operator->() const {
   return const_cast <DatabaseItem*> (di);
}

// uguaglianza
bool DatabaseLinQedIn::Smartp::operator== (const Smartp &s) const {
   return di== s.di;
}

// disuguaglianza
bool DatabaseLinQedIn::Smartp::operator!= (const Smartp &s) const {
   return di!= s.di;
}


// ##### definizioni classe DatabaseItem
// costruttore
DatabaseLinQedIn::DatabaseItem::DatabaseItem(Utente& i): info(&i), riferimenti(0) {}

// costruttore
DatabaseLinQedIn::DatabaseItem::DatabaseItem(Utente& i, const Smartp& s): info(&i), next(s), riferimenti(0) {}
