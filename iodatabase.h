#ifndef IODATABASE_H
#define IODATABASE_H

#include <iostream>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "databaselinqedin.h"
#include "utenteexecutive.h"
//#include "utente.h"

using namespace std;

class DatabaseLinQedIn;

class IODatabase {
private:
   static void scriviCampi(QXmlStreamWriter&, vector<string>);
public:
   IODatabase();
   ~IODatabase();

   static void loadDatabase(string, DatabaseLinQedIn&);
   static void saveDatabase(DatabaseLinQedIn&, string);

};

#endif // IODATABASE_H
