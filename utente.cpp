#include "utente.h"

// definizioni classe RicercaFuntore
void Utente::RicercaFuntore::operator() (const Utente* u, QList<QString>& list) const  {
   switch(tipo) {
   case 1:
      list.push_back("Nome: "+ QString::fromStdString(u->profilo.getNome()));
      list.push_back("Cognome: "+ QString::fromStdString(u->profilo.getCognome()));
      list.push_back("Anno di Nascita: "+ u->profilo.getDataDiNascita().toString("dd.MM.yyyy"));
      break;
   case 2:
      list.push_back("Nome: "+ QString::fromStdString(u->profilo.getNome()));
      list.push_back("Cognome: "+ QString::fromStdString(u->profilo.getCognome()));
      list.push_back("Anno di Nascita: "+ u->profilo.getDataDiNascita().toString("dd.MM.yyyy"));

      for (int i= 0; i< (int)(u->profilo.getTitoloDiStudio().size()); ++i) {
         QString tDiStudio= QString::fromStdString(u->profilo.getTitoloDiStudio(i).getTitolo()).append( "Specializzazione: ")
                  .append(QString::fromStdString(u->profilo.getTitoloDiStudio(i).getSpecializzazione()));
         list.push_back("Titolo di studio"+ QString(i+1)+ ": "+ tDiStudio);
      }

      for (int i= 0; i< (int)(u->profilo.getLingua().size()); ++i)
         list.push_back("Lingua"+ QString(i+1)+ ": "+ QString::fromStdString(u->profilo.getLingua(i).getLingua()));

      for (int i= 0; i< (int)(u->profilo.getCompetenza().size()); ++i)
         list.push_back("Competenza"+ QString(i+1)+ ": "+ QString::fromStdString(u->profilo.getCompetenza(i).getCompetenza()));

      for (int i= 0; i< (int)(u->profilo.getEsperienzaProfessionale().size()); ++i) {
         QString expPro= QString::fromStdString(u->profilo.getEsperienzaProfessionale(i).getDescrizione()).append( "Dal: ")
                  .append(QString::fromStdString(u->profilo.getEsperienzaProfessionale(i).getDal())).append( "Al: ")
                  .append(QString::fromStdString(u->profilo.getEsperienzaProfessionale(i).getAl()));
         list.push_back("Esperienza Professionale"+ QString(i+1)+ ": "+ expPro);
      }
      break;

   case 3:
      list.push_back("Nome: "+ QString::fromStdString(u->profilo.getNome()));
      list.push_back("Cognome: "+ QString::fromStdString(u->profilo.getCognome()));
      list.push_back("Anno di Nascita: "+ u->profilo.getDataDiNascita().toString("dd.MM.yyyy"));

      for (int i= 0; i< (int)(u->profilo.getTitoloDiStudio().size()); ++i) {
         QString tDiStudio= QString::fromStdString(u->profilo.getTitoloDiStudio(i).getTitolo()).append( "Specializzazione: ")
                  .append(QString::fromStdString(u->profilo.getTitoloDiStudio(i).getSpecializzazione()));
         list.push_back("Titolo di studio"+ QString(i+1)+ ": "+ tDiStudio);
      }

      for (int i= 0; i< (int)(u->profilo.getLingua().size()); ++i)
         list.push_back("Lingua"+ QString(i+1)+ ": "+ QString::fromStdString(u->profilo.getLingua(i).getLingua()));

      for (int i= 0; i< (int)(u->profilo.getCompetenza().size()); ++i)
         list.push_back("Competenza"+ QString(i+1)+ ": "+ QString::fromStdString(u->profilo.getCompetenza(i).getCompetenza()));

      for (int i= 0; i< (int)(u->profilo.getEsperienzaProfessionale().size()); ++i) {
         QString expPro= QString::fromStdString(u->profilo.getEsperienzaProfessionale(i).getDescrizione()).append( "Dal: ")
                  .append(QString::fromStdString(u->profilo.getEsperienzaProfessionale(i).getDal())).append( "Al: ")
                  .append(QString::fromStdString(u->profilo.getEsperienzaProfessionale(i).getAl()));
         list.push_back("Esperienza Professionale"+ QString(i+1)+ ": "+ expPro);
      }
      vector<Contatto>::const_iterator it;
      for (it= u->rete.begin(); it!= u->rete.end(); ++it)
         list.push_back("Contatto: "+ QString::fromStdString(it->getContatto()));
      break;
   }
}


// definizioni classe Utente
// costruttore
Utente::Utente(IdUtente& u, Profilo& p): idUtente(u), profilo(p) {}

// costruttore di copia
//Utente::Utente(const Utente& u): idUtente(u.idUtente), profilo(u.profilo), rete(u.rete) {}

// distruttore
Utente::~Utente() {}

// operatore di uguaglianza
bool Utente::operator== (const Utente& u) const {
   // non confronta rete
   return idUtente== u.idUtente && profilo== u.profilo;
}


// metodi rete di amici
void Utente::aggiungiContatto(string s) {
   rete.push_back(s);
}

void Utente::rimuoviContatto(string s) {
   vector<Contatto>::iterator it;
   for (it= rete.begin(); it!= rete.end(); ++it) {
      if (it->getContatto()== s)
         rete.erase(it);
   }
}


// metodi getter
string Utente::getId() const {
   return idUtente.getEmail();
}

IdUtente& Utente::getIdUtente() const {
   return const_cast<IdUtente&>(this->idUtente);
}

Profilo& Utente::getProfilo() const {
   return const_cast<Profilo&>(this->profilo);
}

vector<Contatto>& Utente::getRete() const {
   return const_cast<vector<Contatto>&>(this->rete);
}
