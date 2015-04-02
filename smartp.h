#ifndef SMARTP_H
#define SMARTP_H

#include <iostream>

#include "databaseitem.h"
#include "databaselinqedin.h"

using namespace std;

// dichiarazione incompleta di classe
class DatabaseItem;

class Smartp {
      friend class DatabaseLinQedIn;
//      friend class Iteratore;
private:
   DatabaseItem* di;

public:

   Smartp (DatabaseItem* p= 0);
   ~Smartp ();

   Smartp (const Smartp&);
   Smartp& operator= (const Smartp&);
   DatabaseItem& operator* () const;
   DatabaseItem* operator-> () const;
   bool operator== (const Smartp&) const;
   bool operator!= (const Smartp&) const;
};

#endif // SMARTP_H
