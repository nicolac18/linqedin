#include "qtfinestraamministratore.h"

QtFinestraAmministratore::QtFinestraAmministratore(LinQedInAmministratore& a, QWidget *parent): QDialog(parent), lAmministratore(a) {

   this->setWindowTitle("LinQedIn Amministratore");

   layout= new QGridLayout(this);

   // groupBox operazioni utente
   gBoxUtente= new QGroupBox("Operazioni utente", this);
   layoutUtente= new QGridLayout();


      // inserisci, rimuovi
      buttonInserisci= new QPushButton("Inserisci");
      layoutUtente->addWidget(buttonInserisci, 0, 0, 1, 1);
      buttonRimuovi= new QPushButton("Rimuovi");
      layoutUtente->addWidget(buttonRimuovi, 1, 0, 1, 1);


      // toolBox
      tBox= new QToolBox(this);


      // cerca
      gBoxCerca= new QGroupBox(this);
      layoutCerca= new QGridLayout();

      labelCercaId= new QLabel("Id:");
      layoutCerca->addWidget(labelCercaId, 0, 0, 1, 1);
      lineEditCercaId= new QLineEdit();
      layoutCerca->addWidget(lineEditCercaId, 0, 1, 1, 1);

      labelCercaNome= new QLabel("Nome:");
      layoutCerca->addWidget(labelCercaNome, 1, 0, 1, 1);
      lineEditCercaNome= new QLineEdit();
      layoutCerca->addWidget(lineEditCercaNome, 1, 1, 1, 1);
      labelCercaCognome= new QLabel("Cognome:");
      layoutCerca->addWidget(labelCercaCognome, 2, 0, 1, 1);
      lineEditCercaCognome= new QLineEdit();
      layoutCerca->addWidget(lineEditCercaCognome, 2, 1, 1, 1);

      buttonCerca= new QPushButton("Cerca");
      layoutCerca->addWidget(buttonCerca, 3, 0, 1, 2);

      gBoxCerca->setLayout(layoutCerca);


      // cambia tipo
      gBoxCambiaTipo= new QGroupBox( this);
      layoutCambiaTipo= new QVBoxLayout();

      lineEditCambiaTipo= new QLineEdit();
      lineEditCambiaTipo->setPlaceholderText("inserire id");
      layoutCambiaTipo->addWidget(lineEditCambiaTipo);

      comboBoxCambiaTipo= new QComboBox();
      QStringList list= (QStringList()<< "Utente Basic"<< "Utente Business"<< "Utente Executive");
      comboBoxCambiaTipo->addItems(list);
      layoutCambiaTipo->addWidget(comboBoxCambiaTipo);
      buttonCambiaTipo= new QPushButton("Cambia");
      layoutCambiaTipo->addWidget(buttonCambiaTipo);

      gBoxCambiaTipo->setLayout(layoutCambiaTipo);


      // rimuovi
      gBoxRimuovi= new QGroupBox( this);
      layoutRimuovi= new QVBoxLayout();

      lineEditRimuoviId= new QLineEdit();
      lineEditRimuoviId->setPlaceholderText("inserire id");
      layoutRimuovi->addWidget(lineEditRimuoviId);

      buttonRimuovi= new QPushButton("Rimuovi");
      layoutRimuovi->addWidget(buttonRimuovi);

      gBoxRimuovi->setLayout(layoutRimuovi);


      tBox->addItem(gBoxCerca, "Cerca utente");
      tBox->addItem(gBoxCambiaTipo, "Cambia tipo utente");
      tBox->addItem(gBoxRimuovi, "Rimuovi utente");


      layoutUtente->addWidget(tBox, 2, 0, 1, 1);


      // list widget
      listWidget= new QListWidget();
      aggiornaLista();

      layoutUtente->addWidget(listWidget, 0, 1, 3, 1);

   gBoxUtente->setLayout(layoutUtente);


   // groupBox operazioni database
   gBoxDatabase= new QGroupBox("Operazioni database", this);
   layoutDatabase= new QVBoxLayout();

      // bottoni database
      buttonCaricaDB= new QPushButton("CaricaDB");
      layoutDatabase->addWidget(buttonCaricaDB);
      buttonSalvaDB= new QPushButton("SalvaDB");
      layoutDatabase->addWidget(buttonSalvaDB);

      gBoxDatabase->setLayout(layoutDatabase);


   // layout principale
   layout->addWidget(gBoxUtente, 0, 0, 2, 1);
   layout->addWidget(gBoxDatabase, 0, 1, 1, 1);

   this->setLayout(layout);


   connect(buttonInserisci, SIGNAL(clicked()), this, SLOT(apriQtFinestraRegistrazione()));
   connect(buttonRimuovi, SIGNAL(clicked()), this, SLOT(apriQtFinestraRimozioneUtente()));
   connect(buttonCerca, SIGNAL(clicked()), this, SLOT(cercaUtente()));
   connect(buttonCambiaTipo, SIGNAL(clicked()), this, SLOT(cambiaTipoUtente()));
   connect(buttonRimuovi, SIGNAL(clicked()), this, SLOT(rimuoviUtente()));
   connect(buttonCaricaDB, SIGNAL(clicked()), this, SLOT(caricaDatabase()));
   connect(buttonSalvaDB, SIGNAL(clicked()), this, SLOT(salvaDatabase()));
   connect(listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(inserisciID(QListWidgetItem*)));
   connect(tBox, SIGNAL(currentChanged(int)), this, SLOT(resetCampi(int)));

}


// aggiorna lista
void QtFinestraAmministratore::aggiornaLista() {
   listWidget->clear();

   QStringList lTmp;
   DatabaseLinQedIn::Iteratore it;
   for (it= lAmministratore.getDatabase()->begin(); it!= lAmministratore.getDatabase()->end(); ++it)
      lTmp<< QString::fromStdString((*it)->getId());
   listWidget->addItems(lTmp);
}


//private slots
// slot inserisci ID
void QtFinestraAmministratore::inserisciID(QListWidgetItem* i) {
   if (tBox->currentIndex()== 0)
      lineEditCercaId->setText(i->text());
   else if (tBox->currentIndex()== 1)
      lineEditCambiaTipo->setText(i->text());
   else if (tBox->currentIndex()== 2)
      lineEditRimuoviId->setText(i->text());
}

// slots reset campi
void QtFinestraAmministratore::resetCampi(int) {
   lineEditCercaId->clear();
   lineEditCercaNome->clear();
   lineEditCercaCognome->clear();
   lineEditCambiaTipo->clear();
   lineEditRimuoviId->clear();
}


// publis slots
// slot inserisci utente
void QtFinestraAmministratore::apriQtFinestraRegistrazione() {
   QtFinestraRegistrazione finestraRegistrazione(lAmministratore.getDatabase(), this);
   finestraRegistrazione.exec();

   aggiornaLista();
}

// slot rimuovi utente
void QtFinestraAmministratore::rimuoviUtente() {
   lAmministratore.rimuoviUtente(lineEditRimuoviId->text().toStdString());

   QMessageBox messageBox(this);
   messageBox.setText("Rimozione utente da LinQedIn avvenuta con successo!");
   messageBox.exec();
   this->close();

   aggiornaLista();
}


// slot cerca utente
void QtFinestraAmministratore::cercaUtente() {
   if (lineEditCercaId->text()!= "") {
      DatabaseLinQedIn::Iteratore it= lAmministratore.cercaUtente(lineEditCercaId->text().toStdString());
      if (it!= lAmministratore.getDatabase()->end()) {
         listWidget->clear();
         listWidget->addItem(QString::fromStdString((*it)->getId()));
      }
   }

   else if (lineEditCercaNome->text()!= "" && lineEditCercaCognome->text()!= "") {
      DatabaseLinQedIn::Iteratore it= lAmministratore.cercaUtente(lineEditCercaNome->text().toStdString(), lineEditCercaNome->text().toStdString());
      if (it!= lAmministratore.getDatabase()->end()) {
         listWidget->clear();
         listWidget->addItem(QString::fromStdString((*it)->getId()));
      }
   }
}

// slot cambia tipo utente
void QtFinestraAmministratore::cambiaTipoUtente() {
   lAmministratore.cambiaTipoUtente(lineEditCambiaTipo->text().toStdString(), comboBoxCambiaTipo->currentIndex());
}

// slot carica database
void QtFinestraAmministratore::caricaDatabase() {
   QString filename ("/Users/Nicola/QtCreator/LinQedIn/db.xml");
//   QString filename= QFileDialog::getOpenFileName(this, "Apri", ".xml", "*.xml");
   IODatabase::loadDatabase(filename.toStdString(), lAmministratore.getDatabase());
}

// slot salva database
void QtFinestraAmministratore::salvaDatabase() {
   QString filename ("/Users/Nicola/Desktop/db.xml");
//   QString filename= QFileDialog::getSaveFileName(this, "Salva", ".xml", "*.xml");
   IODatabase::saveDatabase(lAmministratore.getDatabase(), filename.toStdString());
}
