#ifndef TITOLODISTUDIO_H
#define TITOLODISTUDIO_H

#include <iostream>

using namespace std;

class TitoloDiStudio {
private:
   string titolo;
   string specializzazione;

public:
   TitoloDiStudio(string, string);
   ~TitoloDiStudio();

   string getTitolo() const;
   string getSpecializzazione() const;
};

#endif // TITOLODISTUDIO_H
