#ifndef PROFILO_H
#define PROFILO_H

#include <iostream>
#include <QDate>
#include <vector>
#include <QXmlStreamWriter>

#include "competenza.h"
#include "esperienzaprofessionale.h"
#include "lingua.h"
#include "titolodistudio.h"

using namespace std;

class Profilo {
private:
   string nome;
   string cognome;
   QDate dataDiNascita;
   string emailSecondaria;

   vector<TitoloDiStudio> tDiStudio;
   vector<Lingua> lingue;
   vector<Competenza> competenze;
   vector<EsperienzaProfessionale> expProfessionali;


public:
   Profilo(string="", string="", QDate= QDate(), string="");
   Profilo(const Profilo&);

   bool operator==(const Profilo&) const;


   // metodi di modifica dati
   void modificaNome(string);
   void modificaCognome(string);
   void modificaDataDiNascita(QDate);
   void modificaEmail(string);


   // metodi di inserimento dati
   void aggiungiEmail(string);
   void aggiungiTitoloDiStudio(const TitoloDiStudio);
   void aggiungiLingua(const Lingua);
   void aggiungiCompetenza(const Competenza);
   void aggiungiEsperienzaProfessionale(const EsperienzaProfessionale);


   // metodi rimozione
   void rimuoviEmailSecondaria();
   void rimuoviTitoloDiStudio(int);
   void rimuoviLingua(int);
   void rimuoviCompetenza(int);
   void rimuoviEsperienzaProfessionale(int);


   // metodi getter
   string getNome() const;
   string getCognome() const;
   QDate getDataDiNascita() const;
   string getEmailSecondaria() const;

   vector<TitoloDiStudio>& getTitoloDiStudio() const;
   TitoloDiStudio& getTitoloDiStudio(int) const;

   vector<Lingua>& getLingua() const;
   Lingua& getLingua(int) const;
   Lingua& getL(int);

   vector<Competenza>& getCompetenza() const;
   Competenza& getCompetenza(int) const;

   vector<EsperienzaProfessionale>& getEsperienzaProfessionale() const;
   EsperienzaProfessionale& getEsperienzaProfessionale(int) const;


   // metodi writer
   void scriviTitoliDiStudio(QXmlStreamWriter&) const;
   void scriviLingue(QXmlStreamWriter&) const;
   void scriviCompetenze(QXmlStreamWriter&) const;
   void scriviEsperienzeProfessionali(QXmlStreamWriter&) const;

};

#endif // PROFILO_H
