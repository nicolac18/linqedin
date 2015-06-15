#ifndef LINQEDINAMMINISTRATORE_H
#define LINQEDINAMMINISTRATORE_H

#include "databaselinqedin.h"
#include "utenteexecutive.h"

#include <iostream>
#include <QDate>

using namespace std;

class LinQedInAmministratore {
private:
   DatabaseLinQedIn* db;

public:
   LinQedInAmministratore(DatabaseLinQedIn*);
   ~LinQedInAmministratore();

   void inserisciUtente(int, string, string, string, QDate);
   void rimuoviUtente(string);
   void rimuoviUtente(string, string);

   DatabaseLinQedIn::Iteratore cercaUtente(string);
   DatabaseLinQedIn::Iteratore cercaUtente(string, string);

   void cambiaTipoUtente(string, int);

   // metodi getter
   DatabaseLinQedIn* getDatabase() const;

};

#endif // LINQEDINAMMINISTRATORE_H
