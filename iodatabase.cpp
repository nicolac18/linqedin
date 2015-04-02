#include "iodatabase.h"

IODatabase::IODatabase() {}

IODatabase::~IODatabase() {}

void IODatabase::loadDatabase(string s, DatabaseLinQedIn& db) {
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
                  UtenteBasic ut(id,p);
                  vector<string>::const_iterator it;
                  for (it= r.begin(); it!= r.end(); ++it)
                     ut.aggiungiContatto(*it);
                  db.inserisciUtente(ut);
               }
               else if (tipo== "business") {
                  UtenteBusiness ut(id, p);
                  vector<string>::const_iterator it;
                  for (it= r.begin(); it!= r.end(); ++it)
                     ut.aggiungiContatto(*it);
                  db.inserisciUtente(ut);
               }
               else if (tipo== "executive") {
                  UtenteExecutive ut(id, p);
                  vector<string>::const_iterator it;
                  for (it= r.begin(); it!= r.end(); ++it)
                     ut.aggiungiContatto(*it);
                  db.inserisciUtente(ut);
               }
            }

         else
            return;
      }
   }
   file.close();
}


void IODatabase::saveDatabase(DatabaseLinQedIn& db, string s) {

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
   for (itDb= db.begin(); itDb!= db.end(); ++itDb) {

      stream.writeStartElement("utente");
      Utente* u= &(*itDb);

      // tipo utente
      if (dynamic_cast<UtenteBasic*>(u))
         stream.writeAttribute("tipo", "basic");
      else if (dynamic_cast<UtenteBusiness*>(u))
         stream.writeAttribute("tipo", "business");
      else if (dynamic_cast<UtenteExecutive*>(u))
         stream.writeAttribute("tipo", "executive");

      // idutente
      stream.writeTextElement("email", QString::fromStdString((*itDb).getId()));

      // profilo
      stream.writeTextElement("nome", QString::fromStdString((*itDb).getProfilo().getNome()));
      stream.writeTextElement("cognome", QString::fromStdString((*itDb).getProfilo().getCognome()));
      stream.writeTextElement("datadinascita", (*itDb).getProfilo().getDataDiNascita().toString("yyyy.MM.dd"));
      stream.writeTextElement("emailsecondaria", QString::fromStdString((*itDb).getProfilo().getEmailSecondaria()));

      // titolo di studio
      for (int i=0; i<(int)(*itDb).getProfilo().getTitoloDiStudio().size(); ++i) {
         stream.writeEmptyElement("titolodistudio");
         stream.writeTextElement("titolo", QString::fromStdString((*itDb).getProfilo().getTitoloDiStudio(i).getTitolo()));
         stream.writeTextElement("specializzazione", QString::fromStdString((*itDb).getProfilo().getTitoloDiStudio(i).getSpecializzazione()));
      }

      // lingua
      for (int i=0; i<(int)(*itDb).getProfilo().getLingua().size(); ++i) {
         stream.writeTextElement("lingua", QString::fromStdString((*itDb).getProfilo().getLingua(i).getLingua()));
      }

      // competenza
      for (int i=0; i<(int)(*itDb).getProfilo().getCompetenza().size(); ++i) {
         stream.writeTextElement("competenza", QString::fromStdString((*itDb).getProfilo().getCompetenza(i).getCompetenza()));
      }

      // esperienza professionale
      for (int i=0; i<(int)(*itDb).getProfilo().getEsperienzaProfessionale().size(); ++i) {
         stream.writeEmptyElement("esperienzaprofessionale");
         stream.writeTextElement("dal", QString::fromStdString((*itDb).getProfilo().getEsperienzaProfessionale(i).getDal()));
         stream.writeTextElement("al", QString::fromStdString((*itDb).getProfilo().getEsperienzaProfessionale(i).getDal()));
         stream.writeTextElement("descrizione", QString::fromStdString((*itDb).getProfilo().getEsperienzaProfessionale(i).getDescrizione()));
      }

      // rete
      stream.writeEmptyElement("rete");
      vector<Contatto>::const_iterator it;
      for (it= (*itDb).getRete().begin(); it!= (*itDb).getRete().end(); ++it) {
         stream.writeTextElement("contatto", QString::fromStdString((*it).getContatto()));
      }

      stream.writeEndElement();
   }
   stream.writeEndElement();

   // fine documento xml
   stream.writeEndDocument();

   file.close();
}
