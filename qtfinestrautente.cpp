#include "qtfinestrautente.h"

QtFinestraUtente::QtFinestraUtente(LinQedInUtente& u, QWidget *parent): QDialog(parent), lUtente(u) {

   this->setWindowTitle(QString("LinQedIn Utente"));
   this->setMinimumSize(800, 600);

   layout= new QHBoxLayout(this);

   // groupBox info
   gBoxInfo= new QGroupBox(QString("Informazioni"), this);
   layoutInfo= new QGridLayout();

      // idUtente
      gBoxIdUtente= new QGroupBox(QString("Id Utente"), this);
      layoutIdUtente= new QGridLayout();

      labelIdUtente= new QLabel(QString("IdUtente (email):"));
      layoutIdUtente->addWidget(labelIdUtente, 0, 0, 1, 1);
      lineEditIdUtente= new QLineEdit(QString::fromStdString(u.getUtente().getId()));
      layoutIdUtente->addWidget(lineEditIdUtente, 0, 1, 1, 1);

      labelPassword= new QLabel(QString("Password:"));
      layoutIdUtente->addWidget(labelPassword, 1, 0, 1, 1);
      lineEditPassword= new QLineEdit(); lineEditPassword->setDisabled(true);
      layoutIdUtente->addWidget(lineEditPassword, 1, 1, 1, 1);

      gBoxIdUtente->setLayout(layoutIdUtente);

      layoutInfo->addWidget(gBoxIdUtente, 0, 0, 1, 1);


      // profilo
      gBoxProfilo= new QGroupBox(QString("Profilo"), this);
      layoutProfilo= new QGridLayout();

      labelNome= new QLabel(QString("Nome:"));
      layoutProfilo->addWidget(labelNome, 0, 0, 1, 1);
      lineEditNome= new QLineEdit();  // DA INSERIRE DATI UTENTE
      layoutProfilo->addWidget(lineEditNome, 0, 1, 1, 1);

      labelCognome= new QLabel(QString("Cognome:"));
      layoutProfilo->addWidget(labelCognome, 1, 0, 1, 1);
      lineEditCognome= new QLineEdit();  // DA INSERIRE DATI UTENTE
      layoutProfilo->addWidget(lineEditCognome, 1, 1, 1, 1);

      labelDataDiNascita= new QLabel(QString("Data di nascita:"));
      layoutProfilo->addWidget(labelDataDiNascita, 2, 0, 1, 1);
      lineEditDataDiNascita= new QLineEdit();  // DA INSERIRE DATI UTENTE
      layoutProfilo->addWidget(lineEditDataDiNascita, 2, 1, 1, 1);

      labelEmailDue= new QLabel(QString("Email secondaria:"));
      layoutProfilo->addWidget(labelEmailDue, 3, 0, 1, 1);
      lineEditEmailDue= new QLineEdit();  // DA INSERIRE DATI UTENTE
      layoutProfilo->addWidget(lineEditEmailDue, 3, 1, 1, 1);

      gBoxProfilo->setLayout(layoutProfilo);

      layoutInfo->addWidget(gBoxProfilo, 1, 0, 1, 1);


      // tDiStudio
      gBoxTDiStudio= new QGroupBox(QString("Titoli di studio"), this);
      layoutTDiStudio= new QVBoxLayout();

      tableTDiStudio= new QTableWidget(0, 2);
      header= QStringList()<<"Titolo"<< "Specializzazione";
      tableTDiStudio->setHorizontalHeaderLabels(header);
      layoutTDiStudio->addWidget(tableTDiStudio);

      gBoxTDiStudio->setLayout(layoutTDiStudio);

      layoutInfo->addWidget(gBoxTDiStudio, 0, 1, 1, 1);


      // lingue
      gBoxLingue= new QGroupBox(QString("Lingue"), this);
      layoutLingue= new QVBoxLayout();

      tableLingue= new QTableWidget(0, 1);
      header= QStringList()<<"Lingua";
      tableLingue->setHorizontalHeaderLabels(header);
      layoutLingue->addWidget(tableLingue);

      gBoxLingue->setLayout(layoutLingue);

      layoutInfo->addWidget(gBoxLingue, 1, 1, 1, 1);


      // competenze
      gBoxCompetenze= new QGroupBox(QString("Competenze"), this);
      layoutCompetenze= new QVBoxLayout();

      tableCompetenze= new QTableWidget(0, 1);
      header= QStringList()<<"Competenza";
      tableCompetenze->setHorizontalHeaderLabels(header);
      layoutCompetenze->addWidget(tableCompetenze);

      gBoxCompetenze->setLayout(layoutCompetenze);

      layoutInfo->addWidget(gBoxCompetenze, 2, 1, 1, 1);


      // esperienze professionali
      gBoxExpProfessionali= new QGroupBox(QString("Esperienze professionali"), this);
      layoutExpProfessionali= new QVBoxLayout;

      tableExpProfessionali= new QTableWidget(0, 3);
      header= QStringList()<<"Dal"<< "Al"<< "Descrizione";
      tableExpProfessionali->setHorizontalHeaderLabels(header);
      layoutExpProfessionali->addWidget(tableExpProfessionali);

      gBoxExpProfessionali->setLayout(layoutExpProfessionali);

      layoutInfo->addWidget(gBoxExpProfessionali, 3, 1, 1, 1);

   gBoxInfo->setLayout(layoutInfo);


   // groupBox rete di contatti
   gBoxRete= new QGroupBox(QString("Rete di contatti"), this);
   layoutRete= new QVBoxLayout();

      // rete di contatti
      tableRete= new QTableWidget(0, 1);
      header= QStringList()<<"IdUtente";
      tableRete->setHorizontalHeaderLabels(header);
      layoutRete->addWidget(tableRete);

   gBoxRete->setLayout(layoutRete);


   layout->addWidget(gBoxInfo);
   layout->addWidget(gBoxRete);

   this->setLayout(layout);

}
