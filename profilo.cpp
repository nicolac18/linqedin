#include "profilo.h"

Profilo::Profilo(string n, string c, QDate d, string e): nome(n), cognome (c), dataDiNascita(d), emailSecondaria(e) {}

Profilo::Profilo(const Profilo& p): nome(p.nome), cognome(p.cognome), dataDiNascita(p.dataDiNascita), emailSecondaria(p.emailSecondaria),
      tDiStudio(p.tDiStudio), lingue(p.lingue), competenze(p.competenze), expProfessionali(p.expProfessionali) {}

bool Profilo::operator== (const Profilo& p) const {
   // non confronta tDiStudio, lingue, competenze, expProfessionali
   return nome== p.nome && cognome==p.cognome && dataDiNascita== p.dataDiNascita && emailSecondaria== p.emailSecondaria;
}


// metodi di modifica dati
void Profilo::modificaNome(string n) {
   nome= n;
}

void Profilo::modificaCognome(string c) {
   cognome= c;
}

void Profilo::modificaDataDiNascita(QDate d) {
   dataDiNascita= d;
}

void Profilo::modificaEmail(string e) {
   emailSecondaria= e;
}


// metodi di inserimento dati
void Profilo::aggiungiEmail(string e) {
   if (emailSecondaria== "")
      emailSecondaria= e;
}

void Profilo::aggiungiTitoloDiStudio(const TitoloDiStudio t) {
   tDiStudio.push_back(t);
}

void Profilo::aggiungiLingua(const Lingua l) {
   lingue.push_back(l);
}

void Profilo::aggiungiCompetenza(const Competenza c) {
   competenze.push_back(c);
}

void Profilo::aggiungiEsperienzaProfessionale(const EsperienzaProfessionale e) {
   expProfessionali.push_back(e);
}


// metodi rimozione
void Profilo::rimuoviEmailSecondaria() {
   emailSecondaria= "";
}

void Profilo::rimuoviTitoloDiStudio(int i) {
   vector<TitoloDiStudio>::iterator it=tDiStudio.begin()+i;
   tDiStudio.erase(it);
}

void Profilo::rimuoviLingua(int i) {
   vector<Lingua>::iterator it=lingue.begin()+i;
   lingue.erase(it);
}

void Profilo::rimuoviCompetenza(int i) {
   vector<Competenza>::iterator it=competenze.begin()+i;
   competenze.erase(it);
}

void Profilo::rimuoviEsperienzaProfessionale(int i) {
   vector<EsperienzaProfessionale>::iterator it=expProfessionali.begin()+i;
   expProfessionali.erase(it);
}


// metodi getter
string Profilo::getNome() const {
   return nome;
}

string Profilo::getCognome() const {
   return cognome;
}

QDate Profilo::getDataDiNascita() const {
   return dataDiNascita;
}

string Profilo::getEmailSecondaria() const {
   return emailSecondaria;
}

vector<TitoloDiStudio>& Profilo::getTitoloDiStudio() const {
   return const_cast<vector<TitoloDiStudio>&>(tDiStudio);
}

TitoloDiStudio& Profilo::getTitoloDiStudio(int i) const {
   return const_cast<TitoloDiStudio&>(tDiStudio[i]);
}

vector<Lingua>& Profilo::getLingua() const {
   return const_cast<vector<Lingua>&>(lingue);
}

Lingua& Profilo::getLingua(int i) const {
   return const_cast<Lingua&>(lingue.at(i));
}

vector<Competenza>& Profilo::getCompetenza() const {
   return const_cast<vector<Competenza>&>(competenze);
}

Competenza& Profilo::getCompetenza(int i) const {
   return const_cast<Competenza&>(competenze.at(i));
}

vector<EsperienzaProfessionale>& Profilo::getEsperienzaProfessionale() const {
   return const_cast<vector<EsperienzaProfessionale>&>(expProfessionali);
}

EsperienzaProfessionale& Profilo::getEsperienzaProfessionale(int i) const {
  return const_cast<EsperienzaProfessionale&>(expProfessionali.at(i));
}


// metodi writer
void Profilo::scriviTitoliDiStudio(QXmlStreamWriter& stream) const {
   vector<TitoloDiStudio>::const_iterator it;
   for (it= tDiStudio.begin(); it!=tDiStudio.end(); ++it)
      (*it).scrivi(stream);
}

void Profilo::scriviLingue(QXmlStreamWriter& stream) const {
   vector<Lingua>::const_iterator it;
   for (it= lingue.begin(); it!=lingue.end(); ++it)
      (*it).scrivi(stream);
}

void Profilo::scriviCompetenze(QXmlStreamWriter& stream) const {
   vector<Competenza>::const_iterator it;
   for (it= competenze.begin(); it!=competenze.end(); ++it)
      (*it).scrivi(stream);
}

void Profilo::scriviEsperienzeProfessionali(QXmlStreamWriter& stream) const {
   vector<EsperienzaProfessionale>::const_iterator it;
   for (it= expProfessionali.begin(); it!=expProfessionali.end(); ++it)
      (*it).scrivi(stream);
}


//vector<string> Profilo::getInfo() const {
//   vector<string> tmp;
//   tmp.push_back(nome);
//   tmp.push_back(cognome);
//   tmp.push_back(emailSecondaria);
//   tmp.push_back(dataDiNascita.toString(Qt::DateFormat(1)).toStdString());
//   return tmp;
//}

//vector<string> Profilo::getTitoloDiStudio() const {
//   vector<string> tmp;
//   vector<TitoloDiStudio>::const_iterator it;
//   for (it= this->tDiStudio.begin(); it!=tDiStudio.end(); ++it) {
//      tmp.push_back(it->getTitolo());
//      tmp.push_back(it->getSpecializzazione());
//   }
//   return tmp;
//}

//vector<string> Profilo::getLingue() const {
//   return lingue;
//}

//vector<string> Profilo::getCompetenze() const {
//   return competenze;
//}

//vector<string> Profilo::getEsperienzeProfessionali() const {
//   vector<string> tmp;
//   vector<EsperienzaProfessionale>::const_iterator it;
//   for (it= expProfessionali.begin(); it!=expProfessionali.end(); ++it) {
//      tmp.push_back(it->getAl());
//      tmp.push_back(it->getDal());
//      tmp.push_back(it->getDescrizione());
//   }
//   return tmp;
//}
