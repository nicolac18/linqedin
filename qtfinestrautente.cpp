#include "qtfinestrautente.h"

QtFinestraUtente::QtFinestraUtente(LinQedInUtente& u, QWidget *parent): QDialog(parent), lUtente(u) {

   this->setWindowTitle(QString("LinQedIn Utente"));
   this->setMinimumSize(800, 700);

   layout= new QHBoxLayout(this);

   // groupBox info
   gBoxInfo= new QGroupBox(QString("Informazioni"), this);
   layoutInfo= new QGridLayout();

      // idUtente
      gBoxIdUtente= new QGroupBox(QString("Id Utente"), this);
      layoutIdUtente= new QGridLayout();

      labelIdUtente= new QLabel(QString("IdUtente (email):"));
      layoutIdUtente->addWidget(labelIdUtente, 0, 0, 1, 1);
      lineEditIdUtente= new QLineEdit(QString::fromStdString(lUtente.getUtente().getId()));
      lineEditIdUtente->setMinimumWidth(150);
      layoutIdUtente->addWidget(lineEditIdUtente, 0, 1, 1, 1);

      labelPassword= new QLabel(QString("Password:"));
      layoutIdUtente->addWidget(labelPassword, 1, 0, 1, 1);
      lineEditPassword= new QLineEdit(); lineEditPassword->setDisabled(true);
      layoutIdUtente->addWidget(lineEditPassword, 1, 1, 1, 1);

      gBoxIdUtente->setLayout(layoutIdUtente);

      layoutInfo->addWidget(gBoxIdUtente, 0, 0, 1, 2);


      // profilo
      gBoxProfilo= new QGroupBox(QString("Profilo"), this);
      layoutProfilo= new QGridLayout();

      labelNome= new QLabel(QString("Nome:"));
      layoutProfilo->addWidget(labelNome, 0, 0, 1, 1);
      lineEditNome= new QLineEdit(QString::fromStdString(lUtente.getUtente().getProfilo().getNome()));
         lineEditIdUtente->home(true); lineEditIdUtente->setReadOnly(true);
      layoutProfilo->addWidget(lineEditNome, 0, 1, 1, 1);

      labelCognome= new QLabel(QString("Cognome:"));
      layoutProfilo->addWidget(labelCognome, 1, 0, 1, 1);
      lineEditCognome= new QLineEdit(QString::fromStdString(lUtente.getUtente().getProfilo().getCognome()));
      layoutProfilo->addWidget(lineEditCognome, 1, 1, 1, 1);

      labelDataDiNascita= new QLabel(QString("Data di nascita:"));
      layoutProfilo->addWidget(labelDataDiNascita, 2, 0, 1, 1);
      dateEditDataDiNascita= new QDateEdit(this);
      dateEditDataDiNascita->setDisplayFormat("dd.MM.yyyy");
      dateEditDataDiNascita->setMinimumDate(QDate(1,1,1900)); dateEditDataDiNascita->setMaximumDate(QDate(1,1,2015));
      dateEditDataDiNascita->setDate(lUtente.getUtente().getProfilo().getDataDiNascita());
      layoutProfilo->addWidget(dateEditDataDiNascita, 2, 1, 1, 1);

      labelEmailDue= new QLabel(QString("Email secondaria:"));
      layoutProfilo->addWidget(labelEmailDue, 3, 0, 1, 1);
      lineEditEmailDue= new QLineEdit(QString::fromStdString(lUtente.getUtente().getProfilo().getEmailSecondaria()));
      layoutProfilo->addWidget(lineEditEmailDue, 3, 1, 1, 1);

      gBoxProfilo->setLayout(layoutProfilo);

      layoutInfo->addWidget(gBoxProfilo, 1, 0, 1, 2);


      // tipologia
      gBoxTipologia= new QGroupBox(QString("Tipologia"), this);
      layoutTipologia= new QGridLayout();

      labelTipologia= new QLabel(QString("Tipologia:"));
      layoutTipologia->addWidget(labelTipologia, 0, 0, 1, 1);

      lineEditTipologia= new QLineEdit(QString::fromStdString(lUtente.getUtente().getTipo())); lineEditTipologia->setReadOnly(true);

      layoutTipologia->addWidget(lineEditTipologia, 0, 1, 1, 1);

      gBoxTipologia->setLayout(layoutTipologia);

      layoutInfo->addWidget(gBoxTipologia, 2, 0, 1, 2);


      buttonSalva= new QPushButton("Salva"); buttonSalva->setEnabled(false);
      layoutInfo->addWidget(buttonSalva, 3, 0, 1, 1);
      buttonAggiungi= new QPushButton("+");
      layoutInfo->addWidget(buttonAggiungi, 4, 0, 1, 1);
      buttonRimuovi= new QPushButton("-");
      layoutInfo->addWidget(buttonRimuovi, 4, 1, 1, 1);


      // tDiStudio
      gBoxTDiStudio= new QGroupBox(QString("Titoli di studio"), this);
      layoutTDiStudio= new QVBoxLayout();

      tableTDiStudio= new QTableWidget(0, 2);
      tableTDiStudio->setMinimumWidth(150);
      header= QStringList()<<"Titolo"<< "Specializzazione";
      tableTDiStudio->setHorizontalHeaderLabels(header);
      layoutTDiStudio->addWidget(tableTDiStudio);

      gBoxTDiStudio->setLayout(layoutTDiStudio);

      layoutInfo->addWidget(gBoxTDiStudio, 0, 2, 1, 1);


      // lingue
      gBoxLingue= new QGroupBox(QString("Lingue"), this);
      layoutLingue= new QVBoxLayout();

      tableLingue= new QTableWidget(0, 1);
      header= QStringList()<<"Lingua";
      tableLingue->setHorizontalHeaderLabels(header);
      layoutLingue->addWidget(tableLingue);

      gBoxLingue->setLayout(layoutLingue);

      layoutInfo->addWidget(gBoxLingue, 1, 2, 1, 1);


      // competenze
      gBoxCompetenze= new QGroupBox(QString("Competenze"), this);
      layoutCompetenze= new QVBoxLayout();

      tableCompetenze= new QTableWidget(0, 1);
      header= QStringList()<<"Competenza";
      tableCompetenze->setHorizontalHeaderLabels(header);
      layoutCompetenze->addWidget(tableCompetenze);

      gBoxCompetenze->setLayout(layoutCompetenze);

      layoutInfo->addWidget(gBoxCompetenze, 2, 2, 1, 1);


      // esperienze professionali
      gBoxExpProfessionali= new QGroupBox(QString("Esperienze professionali"), this);
      layoutExpProfessionali= new QVBoxLayout;

      tableExpProfessionali= new QTableWidget(0, 3);
      header= QStringList()<<"Dal"<< "Al"<< "Descrizione";
      tableExpProfessionali->setHorizontalHeaderLabels(header);
      layoutExpProfessionali->addWidget(tableExpProfessionali);

      gBoxExpProfessionali->setLayout(layoutExpProfessionali);

      layoutInfo->addWidget(gBoxExpProfessionali, 3, 2, 1, 1);

      layoutInfo->setColumnStretch(2, 1);

   gBoxInfo->setLayout(layoutInfo);


   // groupBox rete di contatti
   gBoxRete= new QGroupBox(QString("Rete di contatti"), this);
   layoutRete= new QVBoxLayout();

      // rete di contatti
      tableRete= new QTableWidget(0, 1);
      tableRete->setMaximumWidth(200);
      tableRete->setColumnWidth(0, 200);
      header= QStringList()<<"IdUtente";
      tableRete->setHorizontalHeaderLabels(header);
      layoutRete->addWidget(tableRete);

      buttonAggiungiRete= new QPushButton("Aggiungi");
      layoutRete->addWidget(buttonAggiungiRete);

   gBoxRete->setLayout(layoutRete);


   layout->addWidget(gBoxInfo);
   layout->addWidget(gBoxRete);

   layout->setStretch(0, 1);

   this->setLayout(layout);

   riempiTableTDiStudio();
   riempiTableLingue();
   riempiTableCompetenze();
   riempiTableExpProfessionali();

   riempiTableRete();


   connect(lineEditNome, SIGNAL(textChanged(QString)), this, SLOT(attivaSalva(QString)));
   connect(lineEditCognome, SIGNAL(textChanged(QString)), this, SLOT(attivaSalva(QString)));
   connect(dateEditDataDiNascita, SIGNAL(dateChanged(QDate)), this, SLOT(attivaSalva(QDate)));
   connect(lineEditEmailDue, SIGNAL(textChanged(QString)), this, SLOT(attivaSalva(QString)));

   connect(buttonSalva, SIGNAL(clicked()), this, SLOT(salva()));
   connect(buttonAggiungiRete, SIGNAL(clicked()), this, SLOT(aggiungiRete()));

}


// metodi privati
void QtFinestraUtente::riempiTableTDiStudio() {
   int row= tableTDiStudio->rowCount();
   for (unsigned int i= 0; i<lUtente.getUtente().getProfilo().getTitoloDiStudio().size(); ++i) {
         tableTDiStudio->setRowCount(tableTDiStudio->rowCount()+1);

         QTableWidgetItem* itemTitolo= new QTableWidgetItem (QString::fromStdString(lUtente.getUtente().getProfilo().getTitoloDiStudio(i).getTitolo()));
         tableTDiStudio->setItem(row, 0, itemTitolo);

         QTableWidgetItem* itemSpecializzazione= new QTableWidgetItem (QString::fromStdString(lUtente.getUtente().getProfilo().getTitoloDiStudio(i).getSpecializzazione()));
         tableTDiStudio->setItem(row, 1, itemSpecializzazione);

         ++row;
   }
}

void QtFinestraUtente::riempiTableLingue() {
   int row= tableLingue->rowCount();
   for (unsigned int i= 0; i<lUtente.getUtente().getProfilo().getLingua().size(); ++i) {
         tableLingue->setRowCount(row+1);

         QTableWidgetItem* itemLingua= new QTableWidgetItem (QString::fromStdString(lUtente.getUtente().getProfilo().getLingua(i).getLingua()));
         tableLingue->setItem(row, 0, itemLingua);

         ++row;
   }
}

void QtFinestraUtente::riempiTableCompetenze() {
   int row= tableCompetenze->rowCount();
   for (unsigned int i= 0; i<lUtente.getUtente().getProfilo().getCompetenza().size(); ++i) {
         tableCompetenze->setRowCount(row+1);

         QTableWidgetItem* itemCompetenza= new QTableWidgetItem (QString::fromStdString(lUtente.getUtente().getProfilo().getCompetenza(i).getCompetenza()));
         tableCompetenze->setItem(row, 0, itemCompetenza);

         ++row;
   }
}

void QtFinestraUtente::riempiTableExpProfessionali() {
   int row= tableExpProfessionali->rowCount();
   for (unsigned int i= 0; i<lUtente.getUtente().getProfilo().getEsperienzaProfessionale().size(); ++i) {
         tableExpProfessionali->setRowCount(row+1);

         QTableWidgetItem* itemDal= new QTableWidgetItem (lUtente.getUtente().getProfilo().getEsperienzaProfessionale(i).getDal().toString("dd.MM.yyyy"));
         tableExpProfessionali->setItem(row, 0, itemDal);

         QTableWidgetItem* itemAl= new QTableWidgetItem (lUtente.getUtente().getProfilo().getEsperienzaProfessionale(i).getAl().toString("dd.MM.yyyy"));
         tableExpProfessionali->setItem(row, 1, itemAl);

         QTableWidgetItem* itemDesc= new QTableWidgetItem (QString::fromStdString(lUtente.getUtente().getProfilo().getEsperienzaProfessionale(i).getDescrizione()));
         tableExpProfessionali->setItem(row, 2, itemDesc);

         ++row;
   }
}


void QtFinestraUtente::riempiTableRete() {
   int row= 0;
   vector<Contatto> tmp= lUtente.getUtente().getRete();

   for (unsigned int i= 0; i<tmp.size(); ++i) {
      tableRete->setRowCount(row+1);

      QTableWidgetItem* item= new QTableWidgetItem (QString::fromStdString(tmp[i].getContatto()));
      tableRete->setItem(row, 0, item);
   }
}

void QtFinestraUtente::aggiungiRiga() {
   if (tableTDiStudio->isItemSelected())
}

void QtFinestraUtente::rimuoviRiga() {

}


// private slots
// attiva salva
void QtFinestraUtente::attivaSalva(QString) {
   if (!buttonSalva->isEnabled())
      buttonSalva->setEnabled(true);
}

void QtFinestraUtente::attivaSalva(QDate) {
   attivaSalva(QString());
}


// public slots
// salva
void QtFinestraUtente::salva() {
   lUtente.modificaNome(lineEditNome->text().toStdString());
   lUtente.modificaCognome(lineEditCognome->text().toStdString());
   lUtente.modificaDataDiNascita(dateEditDataDiNascita->date());
   lUtente.modificaEmailSecondaria(lineEditEmailDue->text().toStdString());
}

// aggiungi rete
void QtFinestraUtente::aggiungiRete() {

}
