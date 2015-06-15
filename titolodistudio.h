#ifndef TITOLODISTUDIO_H
#define TITOLODISTUDIO_H

#include <iostream>
#include <QXmlStreamWriter>

using namespace std;

class TitoloDiStudio {
private:
   string titolo;
   string specializzazione;

public:
   TitoloDiStudio(string, string);
   ~TitoloDiStudio();

   // metodi getter
   string getTitolo() const;
   string getSpecializzazione() const;

   // metodi writer
   void scrivi(QXmlStreamWriter&) const;
};

#endif // TITOLODISTUDIO_H
