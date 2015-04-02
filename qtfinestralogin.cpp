#include "qtfinestralogin.h"

QtFinestraLogin::QtFinestraLogin(bool u, DatabaseLinQedIn* d, QDialog *parent): QDialog(parent), db(d), utente(u) {

   this->setWindowTitle(QString("LinQedIn Login"));

   layout= new QGridLayout(this);

   labelTitolo= new QLabel(QString("Login"),this);

   labelNomeUtente= new QLabel(QString("Nome utente (email):"),this);
   lineEditNomeUtente= new QLineEdit(this);

   buttonLogin= new QPushButton(QString("Login"),this);

   buttonEsci= new QPushButton(QString("Indietro"), this);

   layout->addWidget(labelTitolo, 0, 0, 1, 2, Qt::AlignHCenter);

   layout->addWidget(labelNomeUtente, 1, 0);
   layout->addWidget(lineEditNomeUtente, 1, 1);

   layout->addWidget(buttonLogin, 2, 1);
   buttonLogin->setDefault(true);

   layout->addWidget(buttonEsci, 3, 1);

   this->setLayout(layout);

   connect (buttonLogin, SIGNAL(clicked()), this, SLOT(login()));
   connect(buttonEsci, SIGNAL(clicked()), this, SLOT(esci()));

}

void QtFinestraLogin::login() {

   DatabaseLinQedIn::Iteratore it= db->cercaUtente(lineEditNomeUtente->text().toStdString());
   if (it!= db->end())
      apriQtFinestra((*it));
   else {
      QMessageBox messageBox(this);
      messageBox.setText("Il nome utente inserito non esiste");
      messageBox.exec();
   }
}

void QtFinestraLogin::apriQtFinestra(Utente& u) {
   if (utente) {
      LinQedInUtente lUtente(db,u);
      QtFinestraUtente finestraUtente(lUtente, this);
      this->close();
      finestraUtente.exec();
   }
   else {
      LinQedInAmministratore lAmministratore(db);
      QtFinestraAmministratore finestraAmministratore(lAmministratore, this);
      this->close();
      finestraAmministratore.exec();
   }
}

void QtFinestraLogin::esci() {
   this->close();
}
