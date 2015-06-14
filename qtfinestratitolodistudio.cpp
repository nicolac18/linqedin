#include "qtfinestratitolodistudio.h"

QtFinestraTitoloDiStudio::QtFinestraTitoloDiStudio(LinQedInUtente& u, QDialog *parent): QDialog(parent), lUtente(u) {

   this->setWindowTitle("LinQedIn Inserisci Titolo di studio");

   layout= new QGridLayout(this);

   labelTitolo= new QLabel("Titolo:", this);
   layout->addWidget(labelTitolo, 0, 0, 1, 1);
   lineEditTitolo= new QLineEdit(this);
   layout->addWidget(lineEditTitolo, 0, 1, 1, 1);

   labelSpecializzazione= new QLabel("Specializzazione:", this);
   layout->addWidget(labelSpecializzazione, 1, 0, 1, 1);
   lineEditSpecializzazione= new QLineEdit(this);
   layout->addWidget(lineEditSpecializzazione, 1, 1, 1, 1);

   buttonInserisci= new QPushButton("Inserisci");
   layout->addWidget(buttonInserisci, 2, 0, 1, 2);

   this->setLayout(layout);

   connect(buttonInserisci, SIGNAL(clicked()), this, SLOT(inserisci()));
}

// public slots
void QtFinestraTitoloDiStudio::inserisci() {
   TitoloDiStudio tmp(lineEditTitolo->text().toStdString(), lineEditSpecializzazione->text().toStdString());
   lUtente.aggiungiTitoloDiStudio(tmp);

   QMessageBox messageBox(this);
   messageBox.setText("Titolo di studio inserito");
   messageBox.exec();
   this->close();
}
