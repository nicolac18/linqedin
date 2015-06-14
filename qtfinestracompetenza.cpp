#include "qtfinestracompetenza.h"

QtFinestraCompetenza::QtFinestraCompetenza(LinQedInUtente& u, QDialog *parent): QDialog(parent), lUtente(u) {
   this->setWindowTitle("LinQedIn Inserisci Competenza");

   layout= new QGridLayout(this);

   labelCompetenza= new QLabel("Competenza:", this);
   layout->addWidget(labelCompetenza, 0, 0, 1, 1);
   lineEditCompetenza= new QLineEdit(this);
   layout->addWidget(lineEditCompetenza, 0, 1, 1, 1);

   buttonInserisci= new QPushButton("Inserisci");
   layout->addWidget(buttonInserisci, 1, 1, 1, 2);

   this->setLayout(layout);

   connect(buttonInserisci, SIGNAL(clicked()), this, SLOT(inserisci()));
}

// public slots
void QtFinestraCompetenza::inserisci() {
   lUtente.aggiungiCompetenza(lineEditCompetenza->text().toStdString());

   QMessageBox messageBox(this);
   messageBox.setText("Competenza inserita");
   messageBox.exec();
   this->close();
}
