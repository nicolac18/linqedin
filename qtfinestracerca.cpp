#include "qtfinestracerca.h"

QtFinestraCerca::QtFinestraCerca(LinQedInUtente& u, QWidget *parent): QDialog(parent), lUtente(u) {

   this->setWindowTitle("LinQedIn Cerca");

   layout= new QGridLayout(this);

   labelNome= new QLabel("Nome:",this);
   layout->addWidget(labelNome, 0, 0, 1, 1);
   lineEditNome= new QLineEdit(this);
   layout->addWidget(lineEditNome, 0, 1, 1, 1);

   labelCognome= new QLabel("Cognome:",this);
   layout->addWidget(labelCognome, 1, 0, 1, 1);
   lineEditCognome= new QLineEdit(this);
   layout->addWidget(lineEditCognome, 1, 1, 1, 1);

   buttonCerca= new QPushButton("Cerca",this);
   layout->addWidget(buttonCerca, 2, 0, 1, 1);

   buttonAggiungi= new QPushButton("Aggiungi",this);
   buttonAggiungi->setEnabled(false);
   layout->addWidget(buttonAggiungi, 3, 0, 1, 1);

   buttonEsci= new QPushButton("Esci",this);
   layout->addWidget(buttonEsci, 4, 0, 1, 1);

   textBrowserCerca= new QTextBrowser(this);
   layout->addWidget(textBrowserCerca, 0, 2, 5, 1);

   layout->setColumnStretch(2, 1);

   this->setLayout(layout);

   connect(buttonAggiungi, SIGNAL(clicked()), this, SLOT(aggiungi()));
   connect(buttonCerca, SIGNAL(clicked()), this, SLOT(cerca()));
   connect(buttonEsci, SIGNAL(clicked()), this, SLOT(esci()));

}

// private
void QtFinestraCerca::riempiTextBrowser() {
   QList<QString>::const_iterator it;
   for (it= list.begin(); it!= list.end(); ++it)
      textBrowserCerca->append(*it);
}

// public slots
// aggiungi
void QtFinestraCerca::aggiungi() {
   lUtente.aggiungiContatto(id);
   QMessageBox messageBox(this);
   messageBox.setText("Utente aggiunto alla rete");
   messageBox.exec();
}

// cerca
void QtFinestraCerca::cerca() {
   if (!lineEditNome->text().isEmpty() && !lineEditCognome->text().isEmpty())
      lUtente.cerca(lineEditNome->text().toStdString(),lineEditCognome->text().toStdString(), id, list);
   if (!list.isEmpty()) {
      riempiTextBrowser();
      buttonAggiungi->setEnabled(true);
   }
}

// esci
void QtFinestraCerca::esci() {
   this->close();
}
