#ifndef COMPETENZA_H
#define COMPETENZA_H

#include <iostream>

using namespace std;

class Competenza {
private:
   string competenza;

public:
   Competenza(string);

   string getCompetenza() const;
};

#endif // COMPETENZA_H
