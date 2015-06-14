#include "qtfinestralingua.h"

QtFinestraLingua::QtFinestraLingua(LinQedInUtente& u, QDialog *parent): QDialog(parent), lUtente(u) {
   this->setWindowTitle("LinQedIn Inserisci Lingua");

   layout= new QGridLayout(this);

   labelLingua= new QLabel("Lingua:", this);
   layout->addWidget(labelLingua, 0, 0, 1, 1);
   lineEditLingua= new QLineEdit(this);
   layout->addWidget(lineEditLingua, 0, 1, 1, 1);

   buttonInserisci= new QPushButton("Inserisci");
   layout->addWidget(buttonInserisci, 1, 1, 1, 2);

   this->setLayout(layout);

   connect(buttonInserisci, SIGNAL(clicked()), this, SLOT(inserisci()));
}

// public slots
void QtFinestraLingua::inserisci() {
   lUtente.aggiungiLingua(lineEditLingua->text().toStdString());

   QMessageBox messageBox(this);
   messageBox.setText("Lingua inserita");
   messageBox.exec();
   this->close();
}
