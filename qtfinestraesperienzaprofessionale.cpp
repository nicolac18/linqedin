#include "qtfinestraesperienzaprofessionale.h"

QtFinestraEsperienzaProfessionale::QtFinestraEsperienzaProfessionale(LinQedInUtente& u, QDialog *parent): QDialog(parent), lUtente(u) {

   this->setWindowTitle("LinQedIn Inserisci Esperienza Professionale");

   layout= new QGridLayout(this);

   labelDal= new QLabel("Dal:", this);
   layout->addWidget(labelDal, 0, 0, 1, 1);
   dateEditDal= new QDateEdit(this);
   dateEditDal->setDisplayFormat("dd.MM.yyyy");
   dateEditDal->setMinimumDate(QDate(1,1,1900)); dateEditDal->setMaximumDate(QDate(1,1,2015));
   layout->addWidget(dateEditDal, 0, 1, 1, 1);

   labelAl= new QLabel("Al:", this);
   layout->addWidget(labelAl, 1, 0, 1, 1);
   dateEditAl= new QDateEdit(this);
   dateEditAl->setDisplayFormat("dd.MM.yyyy");
   dateEditAl->setMinimumDate(QDate(1,1,1900)); dateEditAl->setMaximumDate(QDate(1,1,2015));
   layout->addWidget(dateEditAl, 1, 1, 1, 1);

   labelDescrizione= new QLabel("Descrizione:", this);
   layout->addWidget(labelDescrizione, 2, 0, 1, 1);
   lineEditDescrizione= new QLineEdit(this);
   layout->addWidget(lineEditDescrizione, 2, 1, 1, 1);

   buttonInserisci= new QPushButton("Inserisci");
   layout->addWidget(buttonInserisci, 3, 1, 1, 2);

   this->setLayout(layout);

   connect(buttonInserisci, SIGNAL(clicked()), this, SLOT(inserisci()));
}

// public slots
void QtFinestraEsperienzaProfessionale::inserisci() {
   EsperienzaProfessionale tmp (dateEditDal->date(), dateEditAl->date(), lineEditDescrizione->text().toStdString());

   lUtente.aggiungiEsperienzaProfessionale(tmp);

   QMessageBox messageBox(this);
   messageBox.setText("Esperienza professionale inserita");
   messageBox.exec();
   this->close();
}

