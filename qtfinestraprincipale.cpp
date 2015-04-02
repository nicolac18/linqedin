#include "qtfinestraprincipale.h"

QtFinestraPrincipale::QtFinestraPrincipale(QDialog* parent): QDialog(parent) {
   db= new DatabaseLinQedIn();

   IdUtente id1("nicola.carraro.18@gmail.com");
   Profilo p1("Nicola", "Carraro", QDate(1991, 9, 18));
   UtenteBasic u1(id1, p1);
   db->inserisciUtente(u1);

   this->setWindowTitle(QString("LinQedIn"));
   this->setMinimumSize(320, 240);

   layout= new QVBoxLayout(this);

   labelTitolo= new QLabel(QString("Benvenuto in LinQedIn!"));

   buttonRegistrati= new QPushButton(QString("Registrati"), this);
   buttonAccedi= new QPushButton(QString("Accedi"), this);
   buttonAmministratore= new QPushButton(QString("Accedi"), this);

   layoutUtente= new QVBoxLayout();
   layoutUtente->addWidget(buttonRegistrati);
   layoutUtente->addWidget(buttonAccedi);
   gBoxUtente= new QGroupBox(QString("Utente"), this);
   gBoxUtente->setLayout(layoutUtente);


   layoutAmministratore= new QVBoxLayout();
   layoutAmministratore->addWidget(buttonAmministratore);
   gBoxAmministratore= new QGroupBox(QString("Amministratore"), this);
   gBoxAmministratore->setLayout(layoutAmministratore);

   buttonEsci= new QPushButton(QString("Esci"), this);
   buttonEsci->setDefault(true);

   layout->addWidget(labelTitolo);
   layout->addSpacing(20);
   layout->addWidget(gBoxUtente);
   layout->addSpacing(20);
   layout->addWidget(gBoxAmministratore);
   layout->addSpacing(20);
   layout->addWidget(buttonEsci);

   this->setLayout(layout);


   // connect
   connect (buttonAccedi, SIGNAL(clicked()), this, SLOT(apriQtFinestraLoginUtente()));
   connect (buttonRegistrati, SIGNAL(clicked()), this, SLOT(apriQtFinestraRegistrazione()));
   connect (buttonAmministratore, SIGNAL(clicked()), this, SLOT(apriQtFinestraLoginAmministratore()));

   connect (buttonEsci, SIGNAL(clicked()), this, SLOT(esci()));
}

// public slots
void QtFinestraPrincipale::apriQtFinestraLoginUtente() {
   QtFinestraLogin finestraLogin(true, db, this);
   finestraLogin.exec();
}

void QtFinestraPrincipale::apriQtFinestraLoginAmministratore() {
   QtFinestraLogin finestraLogin(false, db, this);
   finestraLogin.exec();
}

void QtFinestraPrincipale::apriQtFinestraRegistrazione() {
   QtFinestraRegistrazione finestraRegistrazione(db, this);
   finestraRegistrazione.exec();
}

void QtFinestraPrincipale::esci() {
   this->close();
}
