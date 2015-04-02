#ifndef LINGUA_H
#define LINGUA_H

#include <iostream>

using namespace std;

class Lingua {
private:
   string lingua;

public:
   Lingua(string);

   string getLingua() const;
};

#endif // LINGUA_H
