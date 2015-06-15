#ifndef UTENTE_H
#define UTENTE_H

#include "contatto.h"
#include "databaselinqedin.h"
#include "idutente.h"
#include "profilo.h"

#include <iostream>
#include <QList>
#include <QString>
#include <QXmlStreamWriter>
#include <vector>

using namespace std;

class DatabaseLinQedIn;

class Utente {
      friend class IODatabase;

private:
   IdUtente idUtente;
   Profilo profilo;
   vector<Contatto> rete;

protected:
   class RicercaFuntore {
   public:
      int tipo;
      RicercaFuntore(int t= 0): tipo(t) {}

      void operator() (const Utente* u, QList<QString>&) const;
   };

public:
   Utente(IdUtente&, Profilo&);

   virtual ~Utente();

   bool operator==(const Utente&) const;

   // metodi rete di amici
   void aggiungiContatto(string);
   void rimuoviContatto(string);

   virtual void ricerca(DatabaseLinQedIn&, string, QList<QString>&) =0;

   //metodi getter
   string getId() const;
   IdUtente& getIdUtente() const;
   Profilo& getProfilo() const;
   vector<Contatto>& getRete() const;

   virtual string getTipo() const =0;

   // metodi writer
   virtual void scrivi(QXmlStreamWriter&) const =0;

};

#endif // UTENTE_H
