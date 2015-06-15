#include "qtfinestraprincipale.h"

QtFinestraPrincipale::QtFinestraPrincipale(QDialog* parent): QDialog(parent) {
   db= new DatabaseLinQedIn();

   this->setWindowTitle("LinQedIn");
   this->setMinimumSize(320, 240);

   layout= new QVBoxLayout(this);

   labelTitolo= new QLabel("Benvenuto in LinQedIn!");

   lineEditNomeUtente= new QLineEdit(this);
   lineEditNomeUtente->setPlaceholderText("inserisci nome utente o email");
   buttonAccedi= new QPushButton("Accedi", this);

   buttonRegistrati= new QPushButton("Registrati", this);

   buttonAmministratore= new QPushButton("Accedi", this);


   layoutUtente= new QVBoxLayout();   
   layoutUtente->addWidget(lineEditNomeUtente);
   layoutUtente->addWidget(buttonAccedi);

   layoutUtente->addSpacing(20);
   layoutUtente->addWidget(buttonRegistrati);

   gBoxUtente= new QGroupBox("Utente", this);
   gBoxUtente->setLayout(layoutUtente);


   layoutAmministratore= new QVBoxLayout();
   layoutAmministratore->addWidget(buttonAmministratore);

   gBoxAmministratore= new QGroupBox("Amministratore", this);
   gBoxAmministratore->setLayout(layoutAmministratore);

   buttonEsci= new QPushButton("Esci", this);

   layout->addWidget(labelTitolo);
   layout->addSpacing(20);
   layout->addWidget(gBoxUtente);
   layout->addSpacing(20);
   layout->addWidget(gBoxAmministratore);
   layout->addSpacing(20);
   layout->addWidget(buttonEsci);

   this->setLayout(layout);


   // connect
   connect (buttonAccedi, SIGNAL(clicked()), this, SLOT(apriQtFinestraUtente()));
   connect (buttonRegistrati, SIGNAL(clicked()), this, SLOT(apriQtFinestraRegistrazione()));
   connect (buttonAmministratore, SIGNAL(clicked()), this, SLOT(apriQtFinestraAmministratore()));

   connect (buttonEsci, SIGNAL(clicked()), this, SLOT(esci()));
}

// public slots
void QtFinestraPrincipale::apriQtFinestraUtente() {

   if (lineEditNomeUtente->text()!= "") {
      DatabaseLinQedIn::Iteratore it= db->cercaUtente(lineEditNomeUtente->text().toStdString());
      if (it!= db->end()) {
         LinQedInUtente lUtente(db,**it);
         QtFinestraUtente finestraUtente(lUtente, this);
         finestraUtente.exec();
      }

      else {
         QMessageBox messageBox(this);
         messageBox.setText("Il nome utente inserito non esiste");
         messageBox.exec();
      }
   }
}

void QtFinestraPrincipale::apriQtFinestraRegistrazione() {
   QtFinestraRegistrazione finestraRegistrazione(db, this);
   finestraRegistrazione.exec();
}

void QtFinestraPrincipale::apriQtFinestraAmministratore() {
   LinQedInAmministratore lAmministratore(db);
   QtFinestraAmministratore finestraAmministratore(lAmministratore, this);
   finestraAmministratore.exec();
}

void QtFinestraPrincipale::esci() {
   this->close();
}
