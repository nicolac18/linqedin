#include "smartp.h"

// costruttore
Smartp::Smartp (DatabaseItem* p): di (p) {
   if (di)
      di->riferimenti++;
}

// distruttore
Smartp::~Smartp () {
   if (di) {
      di->riferimenti--;
      if (di->riferimenti== 0)
         delete di;
   }
}

// costruttore di copia
Smartp::Smartp (const Smartp &s): di(s.di) {
   if (di)
      di->riferimenti++;
}

// assegnazione
Smartp& Smartp::operator= (const Smartp &s) {
   if (*this!= s) {
      DatabaseItem* t= di;
      di= s.di;
      if (di)
         di->riferimenti++;
      if (t) {
         t->riferimenti--;
         if (t->riferimenti== 0)
            delete t;
      }
   }
   return *this;
}

// dereferenziazione
DatabaseItem& Smartp::operator* () const {
   return const_cast <DatabaseItem&> (*di);
}

// selezione membro
DatabaseItem* Smartp::operator-> () const {
   return const_cast <DatabaseItem*> (di);
}

// uguaglianza
bool Smartp::operator== (const Smartp &s) const {
   return di== s.di;
}

// disuguaglianza
bool Smartp::operator!= (const Smartp &s) const {
   return di!= s.di;
}
