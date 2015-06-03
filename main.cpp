#include <iostream>
#include <QApplication>

#include <QRegExp>
#include <QRegExpValidator>

#include "databaselinqedin.h"
#include "iodatabase.h"
#include "qtfinestraprincipale.h"
#include "qtfinestraamministratore.h"
#include "utenteexecutive.h"

using namespace std;

int main(int argc, char **argv) {

   DatabaseLinQedIn* dbL= new DatabaseLinQedIn;
   string s= "/Users/Nicola/QtCreator/LinQedIn/db.xml";

//   IdUtente id1("nicola.carraro.18@gmail.com");
//   Profilo p1("Nicola", "Carraro", QDate(1991, 9, 18));
//   p1.aggiungiCompetenza(Competenza("C++"));
//   p1.aggiungiLingua(Lingua("italiano"));
//   p1.aggiungiEsperienzaProfessionale(EsperienzaProfessionale(QDate(1980, 6, 1), QDate(2010, 9, 30), "musei civici"));
//   p1.aggiungiTitoloDiStudio(TitoloDiStudio("diploma", "perito tecnico informatico"));
//   p1.aggiungiLingua(Lingua("inglese"));

//   UtenteBasic* u1= new UtenteBasic(id1, p1);

//   IdUtente id2("antolauri@alice.it");
//   Profilo p2("Laurenzio", "Carraro", QDate(1961, 7, 24));
//   UtenteBasic* u2= new UtenteBasic(id2, p2);

//   IdUtente id3("edoardo.carraro.16@gmail.com");
//   Profilo p3("Edoardo", "Carraro", QDate(2001, 7, 16));
//   UtenteBusiness* u3= new UtenteBusiness(id3, p3);

//   dbL->inserisciUtente(u1);
//   dbL->inserisciUtente(u2);
//   dbL->inserisciUtente(u3);

//   IODatabase::saveDatabase(dbL, s);

   QApplication app(argc, argv);

   QtFinestraPrincipale windows;
//   QtFinestraLogin windows(dbL, 1);
//   QtFinestraRegistrazione windows(dbL);
//   QtFinestraAmministratore windows(dbL);
   windows.show();

   return app.exec();
}
