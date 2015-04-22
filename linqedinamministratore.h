#ifndef LINQEDINAMMINISTRATORE_H
#define LINQEDINAMMINISTRATORE_H

#include <iostream>
#include <QDate>

#include "databaselinqedin.h"
#include "utenteexecutive.h"

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

   DatabaseLinQedIn* getDatabase() const;

};

#endif // LINQEDINAMMINISTRATORE_H
