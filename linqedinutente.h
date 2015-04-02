#ifndef LINQEDINUTENTE_H
#define LINQEDINUTENTE_H

#include <iostream>
#include <QDate>

#include "databaselinqedin.h"
#include "utenteexecutive.h"

using namespace std;

class LinQedInUtente {
private:
   DatabaseLinQedIn* db;
   Utente& u;

public:
   LinQedInUtente(DatabaseLinQedIn*, Utente&);
   ~LinQedInUtente();

   void modificaId(string);

   // metodi di modifica dati
   void modificaNome(string);
   void modificaCognome(string);
   void modificaDataDiNascita(QDate);
   void modificaEmailSecondaria(string);

   // metodi di inserimento dati
   void aggiungiEmail(string);
   void aggiungiTitoloDiStudio(TitoloDiStudio);
   void aggiungiLingua(string);
   void aggiungiCompetenza(string);
   void aggiungiEsperienzaProfessionale(EsperienzaProfessionale);

   // metodi rete di contatti
   void aggiungiContatto(string);
   void rimuoviContatto(string);

   // metodo di ricerca

   // metodi getter
   Utente& getUtente() const;
};

#endif // LINQEDINUTENTE_H
