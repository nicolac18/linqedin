#include <iostream>
#include <QApplication>

#include <QRegExp>
#include <QRegExpValidator>

#include "databaselinqedin.h"
#include "iodatabase.h"
#include "qtfinestraprincipale.h"
#include "qtfinestraamministratore.h"
#include "utenteexecutive.h"

using namespace std;

int main(int argc, char **argv) {

   QApplication app(argc, argv);

   QtFinestraPrincipale windows;
   windows.show();

   return app.exec();
}
