#ifndef DATABASELINQEDIN_H
#define DATABASELINQEDIN_H

#include "utente.h"

#include <iostream>

using namespace std;

class Utente;

class DatabaseLinQedIn {
      friend class Iteratore;
private:
   class DatabaseItem;

//   dichiarazione classe Smartp
   class Smartp {
      friend class SmartUtente;
   public:
      DatabaseItem* di;

      Smartp(DatabaseItem* p= 0);
      ~Smartp();

      Smartp(const Smartp&);
      Smartp& operator=(const Smartp&);
      DatabaseItem& operator*() const;
      DatabaseItem* operator->() const;
      bool operator==(const Smartp&) const;
      bool operator!=(const Smartp&) const;
   };

   class DatabaseItem {
   public:
      Utente* info;
      Smartp next;
      int riferimenti;

      DatabaseItem(Utente&);
      DatabaseItem(Utente&, const Smartp&);
//      ~DatabaseItem();
   };

   Smartp primo;

public:
   DatabaseLinQedIn();
   DatabaseLinQedIn(DatabaseLinQedIn&);
   ~DatabaseLinQedIn();

   // dichiarazione classe pubblica Iteratore
   class Iteratore {
         friend class DatabaseLinQedIn;
   private:
      DatabaseItem* idi;

   public:
      bool operator==(const Iteratore&) const;
      bool operator!=(const Iteratore&) const;
      Iteratore& operator++();
      Iteratore& operator++(int);
      Utente* operator*() const;
   };

   Iteratore begin() const;
   Iteratore end() const;
   DatabaseItem& operator [] (Iteratore) const;

   bool isEmpty() const;

   bool inserisciUtente(Utente*);
   bool rimuoviUtente(string);
   Iteratore cercaUtente(string);
   Iteratore cercaUtente(string, string);
};

#endif // DATABASELINQEDIN_H
