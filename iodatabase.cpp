#include "iodatabase.h"

IODatabase::IODatabase() {}

IODatabase::~IODatabase() {}

void IODatabase::loadDatabase(string s, DatabaseLinQedIn* db) {
   QString path= QString::fromStdString(s);

   QFile file(path);
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      cout<< "errore";
      return;
   }

   QXmlStreamReader stream(&file);
   stream.readNext();
   if (stream.isStartDocument()) {

      stream.readNext();
      if (stream.isStartElement()) {
         if (stream.name()== "DatabaseLinQedIn")

            while (!stream.isEndDocument()) {

               stream.readNextStartElement();   // utente
               string tipo= stream.attributes().at(0).value().toString().toStdString();  // tipo

               Profilo p; string e, n, c, es; QDate d; vector<string> r;
               while (!stream.isEndElement()) {
                  stream.readNext();

                  // profilo
                  if (stream.name().toString().toStdString()== "email")
                     e= stream.text().toString().toStdString();

                  if (stream.name().toString().toStdString()== "nome")
                     n= stream.text().toString().toStdString();

                  if (stream.name().toString().toStdString()== "cognome")
                     c= stream.text().toString().toStdString();

                  if (stream.name().toString().toStdString()== "datadinascita") {
                     QString tmp= stream.text().toString();
                     d= QDate::fromString(tmp, "yyyy.MM.dd");
                  }

                  if (stream.name().toString().toStdString()== "emailsecondaria")
                     es= stream.text().toString().toStdString();

                  // titolo di studio
                  if (stream.name().toString().toStdString()== "titolodistudio") {
                     stream.readNext(); string t= stream.text().toString().toStdString();
                     stream.readNext(); string s= stream.text().toString().toStdString();
                     p.aggiungiTitoloDiStudio (TitoloDiStudio(t, s));
                  }

                  // lingua
                  if (stream.name().toString().toStdString()== "lingua")
                     p.aggiungiLingua(Lingua(stream.text().toString().toStdString()));

                  // competenza
                  if (stream.name().toString().toStdString()== "competenza")
                     p.aggiungiCompetenza(Competenza(stream.text().toString().toStdString()));

                  // esperienza professionale
                  if (stream.name().toString().toStdString()== "esperienzaprofessionale") {
                     stream.readNext(); QString dal= stream.text().toString();
                     stream.readNext(); QString al= stream.text().toString();
                     stream.readNext(); string exp= stream.text().toString().toStdString();
                     p.aggiungiEsperienzaProfessionale(EsperienzaProfessionale(QDate::fromString(dal, "yyyy.MM.dd"), QDate::fromString(al, "yyyy.MM.dd"), exp));
                  }

                  // rete
                  if (stream.name().toString().toStdString()== "contatto")
                     r.push_back(stream.text().toString().toStdString());
               }

               IdUtente id(e);
               p.modificaNome(n);
               p.modificaCognome(c);
               p.modificaDataDiNascita(d);
               p.modificaEmail(es);

               // inserimento utenti
               if (tipo== "basic") {
                  UtenteBasic* ut= new UtenteBasic(id,p);
                  vector<string>::const_iterator it;
                  for (it= r.begin(); it!= r.end(); ++it)
                     ut->aggiungiContatto(*it);
                  db->inserisciUtente(ut);
               }
               else if (tipo== "business") {
                  UtenteBusiness* ut= new UtenteBusiness(id, p);
                  vector<string>::const_iterator it;
                  for (it= r.begin(); it!= r.end(); ++it)
                     ut->aggiungiContatto(*it);
                  db->inserisciUtente(ut);
               }
               else if (tipo== "executive") {
                  UtenteExecutive* ut= new UtenteExecutive(id, p);
                  vector<string>::const_iterator it;
                  for (it= r.begin(); it!= r.end(); ++it)
                     ut->aggiungiContatto(*it);
                  db->inserisciUtente(ut);
               }
            }

         else
            return;
      }
   }
   file.close();
}


void IODatabase::saveDatabase(DatabaseLinQedIn* db, string s) {

   QString path= QString::fromStdString(s);

   QFile file(path);
   if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
      cout<< "errore";
      return;
   }

   QXmlStreamWriter stream(&file);
   stream.setAutoFormatting(true);

   // inizio documento xml
   stream.writeStartDocument();

   stream.writeStartElement("DatabaseLinQedIn");

   DatabaseLinQedIn::Iteratore itDb;
   for (itDb= db->begin(); itDb!= db->end(); ++itDb) {

      stream.writeStartElement("utente");

      Utente* u= *itDb;
      u->scrivi(stream);

      stream.writeEndElement();
   }

   stream.writeEndElement();

   // fine documento xml
   stream.writeEndDocument();

   file.close();
}
