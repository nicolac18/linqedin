#ifndef RETESOCIALE_H
#define RETESOCIALE_H

#include <iostream>
#include <list>
#include <vector>

//#include "utente.h"

using namespace std;

class Utente;

class ReteSociale {

private:
   list<Utente*> utenti;

public:
   ReteSociale();
   ReteSociale(const ReteSociale&);
   ~ReteSociale();

   void aggiungiUtente (Utente*);
   void rimuoviUtente (Utente*);

//   vector<string> getUtenti() const;
};

#endif // RETESOCIALE_H
