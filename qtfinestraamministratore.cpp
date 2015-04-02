#include "qtfinestraamministratore.h"

QtFinestraAmministratore::QtFinestraAmministratore(LinQedInAmministratore& a, QWidget *parent): QDialog(parent), lAmministratore(a) {

   this->setWindowTitle(QString("LinQedIn Amministratore"));

   layout= new QHBoxLayout(this);

   // groupBox operazioni utente
   gBoxUtente= new QGroupBox(QString("Operazioni utente"), this);
   layoutUtente= new QGridLayout();


      // inserisci, rimuovi
      buttonInserisci= new QPushButton(QString("Inserisci"));
      layoutUtente->addWidget(buttonInserisci, 0, 0, 1, 1);
      buttonRimuovi= new QPushButton(QString("Rimuovi"));
      layoutUtente->addWidget(buttonRimuovi, 1, 0, 1, 1);


      // toolBox
      tBox= new QToolBox(this);


      // cerca
      gBoxCerca= new QGroupBox(this);
      layoutCerca= new QGridLayout();

      labelCercaId= new QLabel(QString("Id:"));
      layoutCerca->addWidget(labelCercaId, 0, 0, 1, 1);
      lineEditCercaId= new QLineEdit();
      layoutCerca->addWidget(lineEditCercaId, 0, 1, 1, 1);

      labelCercaNome= new QLabel(QString("Nome:"));
      layoutCerca->addWidget(labelCercaNome, 1, 0, 1, 1);
      lineEditCercaNome= new QLineEdit();
      layoutCerca->addWidget(lineEditCercaNome, 1, 1, 1, 1);
      labelCercaCognome= new QLabel(QString("Cognome:"));
      layoutCerca->addWidget(labelCercaCognome, 2, 0, 1, 1);
      lineEditCercaCognome= new QLineEdit();
      layoutCerca->addWidget(lineEditCercaCognome, 2, 1, 1, 1);

      buttonCerca= new QPushButton(QString("Cerca"));
      layoutCerca->addWidget(buttonCerca, 3, 0, 1, 2);

      gBoxCerca->setLayout(layoutCerca);


      // cambia tipo
      gBoxCambiaTipo= new QGroupBox( this);
      layoutCambiaTipo= new QVBoxLayout();

      lineEditCambiaTipo= new QLineEdit();
      lineEditCambiaTipo->setPlaceholderText(QString("inserire id"));
      layoutCambiaTipo->addWidget(lineEditCambiaTipo);

      comboBoxCambiaTipo= new QComboBox();
      QStringList list= (QStringList()<< "Utente Basic"<< "Utente Business"<< "Utente Executive");
      comboBoxCambiaTipo->addItems(list);
      layoutCambiaTipo->addWidget(comboBoxCambiaTipo);
      buttonCambiaTipo= new QPushButton(QString("Cambia"));
      layoutCambiaTipo->addWidget(buttonCambiaTipo);

      gBoxCambiaTipo->setLayout(layoutCambiaTipo);


      // rimuovi
      gBoxRimuovi= new QGroupBox( this);
      layoutRimuovi= new QVBoxLayout();

      lineEditRimuoviId= new QLineEdit();
      lineEditRimuoviId->setPlaceholderText(QString("inserire id"));
      layoutRimuovi->addWidget(lineEditRimuoviId);

      buttonRimuovi= new QPushButton(QString("Rimuovi"));
      layoutRimuovi->addWidget(buttonRimuovi);

      gBoxRimuovi->setLayout(layoutRimuovi);


      tBox->addItem(gBoxCerca, QString("Cerca utente"));
      tBox->addItem(gBoxCambiaTipo, QString("Cambia tipo utente"));
      tBox->addItem(gBoxRimuovi, QString("Rimuovi utente"));


      layoutUtente->addWidget(tBox, 2, 0, 1, 1);


      // text browser
      textBrowser= new QTextBrowser();
      layoutUtente->addWidget(textBrowser, 0, 1, 3, 1);

   gBoxUtente->setLayout(layoutUtente);


   // groupBox operazioni database
   gBoxDatabase= new QGroupBox(QString("Operazioni database"), this);
   layoutDatabase= new QVBoxLayout();

      // bottoni database
      buttonCaricaDB= new QPushButton(QString("CaricaDB"));
      layoutDatabase->addWidget(buttonCaricaDB);
      buttonSalvaDB= new QPushButton(QString("SalvaDB"));
      layoutDatabase->addWidget(buttonSalvaDB);

      gBoxDatabase->setLayout(layoutDatabase);


   // layout principale
   layout->addWidget(gBoxUtente);
   layout->addWidget(gBoxDatabase);

   this->setLayout(layout);


   connect(buttonInserisci, SIGNAL(clicked()), this, SLOT(apriQtFinestraRegistrazione()));
   connect(buttonRimuovi, SIGNAL(clicked()), this, SLOT(apriQtFinestraRimozioneUtente()));
   connect(buttonCerca, SIGNAL(clicked()), this, SLOT(cercaUtente()));
   connect(buttonCambiaTipo, SIGNAL(clicked()), this, SLOT(cambiaTipoUtente()));
   connect(buttonRimuovi, SIGNAL(clicked()), this, SLOT(rimuoviUtente()));
   connect(buttonCaricaDB, SIGNAL(clicked()), this, SLOT(caricaDatabase()));
   connect(buttonSalvaDB, SIGNAL(clicked()), this, SLOT(salvaDatabase()));

}

// slot inserisci utente
void QtFinestraAmministratore::apriQtFinestraRegistrazione() {
   QtFinestraRegistrazione finestraRegistrazione(lAmministratore.getDatabase(), this);
//   QtFinestraRegistrazione finestraRegistrazione(db, this);
   finestraRegistrazione.exec();
}

// slot rimuovi utente
void QtFinestraAmministratore::rimuoviUtente() {
   lAmministratore.rimuoviUtente(lineEditRimuoviId->text().toStdString());

   QMessageBox messageBox(this);
   messageBox.setText("Rimozione utente da LinQedIn avvenuta con successo!");
   messageBox.exec();
   this->close();
}


// slot cerca utente
void QtFinestraAmministratore::cercaUtente() {
//   DatabaseLinQedIn::Iteratore it;
//   string id= lineEditCercaId->text().toStdString();
//   if (id!= "") {
//      it= db->cercaUtente(id);
//   }
//   else {
//      string nome= lineEditCercaNome->text().toStdString();
//      string cognome= lineEditCercaCognome->text().toStdString();
//      it= db->cercaUtente(nome, cognome);
//   }
//   textBrowser->insertPlainText(QString(QString::fromStdString((*it).getId())));
}

// slot cambia tipo utente
void QtFinestraAmministratore::cambiaTipoUtente() {
//   LinQedInAmministratore admin(*db);
//   string id= "antolauri@alice.it";       // DA MODIFICARE - PRENDERE ID DAL TEXT BROWSER
//   admin.cambiaTipoUtente(id, comboBoxCambiaTipo->currentIndex());
}


void QtFinestraAmministratore::caricaDatabase() {
//   QString filename= QFileDialog::getOpenFileName(this, QString("Apri"), QString(".xml"));
//   IODatabase::leggiDatabase(filename.toStdString(), *db);
}

void QtFinestraAmministratore::salvaDatabase() {
//   QString filename= QFileDialog::getSaveFileName(this, QString("Salva"), QString(".xml"));
//   IODatabase::scriviDatabase(*db, filename.toStdString());
}
