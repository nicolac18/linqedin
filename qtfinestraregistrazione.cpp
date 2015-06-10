#include "qtfinestraregistrazione.h"

QtFinestraRegistrazione::QtFinestraRegistrazione(DatabaseLinQedIn* d, QDialog *parent): QDialog(parent), db(d) {

   this->setWindowTitle(QString("LinQedIn Registrazione"));

   layout= new QGridLayout(this);

   labelEmail= new QLabel(QString("Email:"),this);
   lineEditEmail= new QLineEdit(this);

   labelNome= new QLabel(QString("Nome:"),this);
   lineEditNome= new QLineEdit(this);

   labelCognome= new QLabel(QString("Cognome:"),this);
   lineEditCognome= new QLineEdit(this);

   labelDataDiNascita= new QLabel(QString("Data di nascita:"),this);
   dateEditDataDiNascita= new QDateEdit(this);
   dateEditDataDiNascita->setDisplayFormat("dd.MM.yyyy");
   dateEditDataDiNascita->setMinimumDate(QDate(1,1,1900)); dateEditDataDiNascita->setMaximumDate(QDate(1,1,2015));

   labelTipoUtente= new QLabel(QString("Tipo utente:"),this);
   comboBoxTipoUtente= new QComboBox(this);
   QStringList list= (QStringList()<< "Utente Basic"<< "Utente Business"<< "Utente Executive");
   comboBoxTipoUtente->addItems(list);

   buttonRegistrati= new QPushButton(QString("Registrati"), this);

   buttonEsci= new QPushButton(QString("Indietro"), this);

   layout->addWidget(labelEmail, 1, 0);
   layout->addWidget(lineEditEmail, 1, 1);

   layout->addWidget(labelNome, 2, 0);
   layout->addWidget(lineEditNome, 2, 1);

   layout->addWidget(labelCognome, 3, 0);
   layout->addWidget(lineEditCognome, 3, 1);

   layout->addWidget(labelDataDiNascita, 4, 0);
   layout->addWidget(dateEditDataDiNascita, 4, 1);

   layout->addWidget(labelTipoUtente, 5, 0);
   layout->addWidget(comboBoxTipoUtente, 5, 1);

   layout->addWidget(buttonRegistrati, 6, 1);
   buttonRegistrati->setDefault(true);

   layout->addWidget(buttonEsci, 7, 1);

   this->setLayout(layout);

   connect(buttonRegistrati, SIGNAL(clicked()), this, SLOT(registrazione()));
   connect(buttonEsci, SIGNAL(clicked()), this, SLOT(esci()));
}

// public slots
void QtFinestraRegistrazione::registrazione() {

   IdUtente tmpI(lineEditEmail->text().toStdString());
   Profilo tmpP(lineEditNome->text().toStdString(),lineEditCognome->text().toStdString(),
                  QDate::fromString(dateEditDataDiNascita->text(), "dd.MM.yyyy"));

   bool inserito;
   if (comboBoxTipoUtente->currentIndex()== 0) {
      inserito= db->inserisciUtente(new UtenteBasic(tmpI, tmpP));
   }
   else if (comboBoxTipoUtente->currentIndex()== 1) {
      inserito= db->inserisciUtente(new UtenteBusiness(tmpI, tmpP));
   }

   else if (comboBoxTipoUtente->currentIndex()== 2) {
      inserito= db->inserisciUtente(new UtenteExecutive(tmpI, tmpP));
   }

   else
      inserito= false;

   QMessageBox messageBox(this);
   if (inserito) {
      messageBox.setText("Registrazione avvenuta con successo!");
      messageBox.exec();
      this->close();
   }
   else {
      messageBox.setText("Nome utente già presente.");
      messageBox.exec();
   }
}

void QtFinestraRegistrazione::esci() {
   this->close();
}
