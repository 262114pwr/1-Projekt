#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    liczba_pon = 0; // zmienne prywatna potrzebne do liczenia
    liczba_wto = 0;
    liczba_sro = 0;
    liczba_czw = 0;
    liczba_pia = 0;
    liczba_sob = 0;
    liczba_nie = 0;
    limit_godz = 8;
    ilosc_przerw = 1;
    ilosc_do_przerwy = 1;
    dlugosc_przerwy = 5;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_input_limit_spinBox_valueChanged(int arg1)
{
   this->limit_godz = arg1;
}

void Widget::on_input_godzin_spinBox_valueChanged(int ilosc_godzin) // procedura
// reakcji na zmianę wartości w spinBoxie wprowadzającej godziny
{
    double procent_godzin = 0;
    int przerwa_output = 0;
    int czas_przerwy_output = 0;

    procent_godzin = (double(ilosc_godzin) / double(24)) *100 ; // procent z 24 h
    ui->outputWiget_procent_doba->setText(QString::number(procent_godzin, 'f' , 2));
    // wyświetlenie do 3 mjsca po przecinku
    if (ilosc_godzin >= limit_godz){ // jeśli godzin będzie więcej niż ustawiono wyświetli się komunikat:
        ui->label_invisible->setStyleSheet("QLabel {background-color : yellow; color : red; }");
        ui->label_invisible->setText("Uwaga!!!!");
    } else {
        ui->label_invisible->setStyleSheet("QLabel {background-color : none; color : none; }");
        ui->label_invisible->setText("");
    }

    przerwa_output = (double(ilosc_godzin)/double(ilosc_do_przerwy)) * ilosc_przerw;
    ui->output_przerwa->setText(QString::number(przerwa_output)); // ile przerw powinniśmy zrobić
    czas_przerwy_output = przerwa_output * dlugosc_przerwy;
    ui->output_czas_przerw->setText(QString::number(czas_przerwy_output)); // ile to czasu
}

void Widget::on_pushButton_clicked()
{
    int liczba_godzin_tydzien = 0; // wartości początkowe = 0
    double srednia_tydzien = 0;
    liczba_godzin_tydzien = liczba_pon + liczba_wto + liczba_sro + liczba_czw + liczba_pia + liczba_sob + liczba_nie;
    srednia_tydzien = double(liczba_godzin_tydzien)/double(7); // liczenie średniej
    ui->output_tydzien_godzin->setText(QString::number(liczba_godzin_tydzien)); // komunikaty
    ui->output_srednia->setText(QString::number(srednia_tydzien, 'f', 3));
}

void Widget::on_input_pon_spinBox_valueChanged(int arg1)
{
   this->liczba_pon = arg1; // przypisanie wpisanej do spinBoxa liczby do zmiennej liczba_dany dzień tygodnia
}


void Widget::on_input_wto_spinBox_2_valueChanged(int arg1)
{
    this ->liczba_wto = arg1;
}


void Widget::on_input_sro_spinBox_3_valueChanged(int arg1)
{
    this->liczba_sro = arg1;
}


void Widget::on_input_czw_spinBox_4_valueChanged(int arg1)
{
    this->liczba_czw = arg1;
}


void Widget::on_input_pia_spinBox_5_valueChanged(int arg1)
{
    this->liczba_pia = arg1;
}


void Widget::on_input_sob_spinBox_6_valueChanged(int arg1)
{
    this->liczba_sob = arg1;
}


void Widget::on_input_nie_spinBox_7_valueChanged(int arg1)
{
    this->liczba_nie = arg1;
}


void Widget::on_input_ilosc_przerw_spinBox_valueChanged(int arg1)
{
    this->ilosc_przerw =arg1;
}


void Widget::on_input_ilosc_do_przerwy_spinBox_valueChanged(int arg1)
{
    this->ilosc_do_przerwy = arg1;
}


void Widget::on_input_dlugosc_przerwy_spinBox_valueChanged(int arg1)
{
    this->dlugosc_przerwy = arg1;
}

void Widget::on_pushButton_3_clicked()
{
    liczba_pon = 0; // zmienne prywatna potrzebne do liczenia
    liczba_wto = 0;
    liczba_sro = 0;
    liczba_czw = 0;
    liczba_pia = 0;
    liczba_sob = 0;
    liczba_nie = 0;
    limit_godz = 8;
    ilosc_przerw = 1;
    ilosc_do_przerwy = 1;
    dlugosc_przerwy = 5;
    ui->output_przerwa->setText(QString::number(0));
    ui->output_czas_przerw->setText(QString::number(0)); // ile to czasu
    ui->output_tydzien_godzin->setText(QString::number(0)); // komunikaty
    ui->output_srednia->setText(QString::number(0));
    ui->input_godzin_spinBox->setValue(0);
    ui->input_pon_spinBox->setValue(0);
    ui->input_wto_spinBox_2->setValue(0);
    ui->input_sro_spinBox_3->setValue(0);
    ui->input_czw_spinBox_4->setValue(0);
    ui->input_pia_spinBox_5->setValue(0);
    ui->input_sob_spinBox_6->setValue(0);
    ui->input_nie_spinBox_7->setValue(0);
    ui->input_dlugosc_przerwy_spinBox->setValue(5);
    ui->input_ilosc_do_przerwy_spinBox->setValue(1);
    ui->input_limit_spinBox->setValue(8);
    ui->input_ilosc_przerw_spinBox->setValue(1);

}
