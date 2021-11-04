#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
 int Widget::liczba_pon = 0; // zmienne globalne potrzebne do liczenia
 int Widget::liczba_wto = 0;
 int Widget::liczba_sro = 0;
 int Widget::liczba_czw = 0;
 int Widget::liczba_pia = 0;
 int Widget::liczba_sob = 0;
 int Widget::liczba_nie = 0;

void Widget::on_input_godzin_spinBox_valueChanged(int arg1) // procedura
// reakcji na zmianę wartości w spinBoxie wprowadzającej godziny
{
    double procent_godzin = 0;

    procent_godzin = (double(arg1) / double(24)) *100 ; // procent z 24 h
    ui->outputWiget_procent_doba->setText(QString::number(procent_godzin, 'f' , 3));
    // wyświetlenie do 3 mjsca po przecinku
    if (arg1 >= 8){ // jeśli godzin będzie więcej niż 8 wyświetli się komunikat:
        ui->label_invisible->setStyleSheet("QLabel {background-color : yellow; color : red; }");
        ui->label_invisible->setText("Uwaga!!!!");
    }
    ui->output_przerwa->setText(QString::number(arg1)); // ile przerw powinniśmy zrobić
    ui->output_czas_przerw->setText(QString::number(arg1*5)); // ile to czasu
}

void Widget::on_pushButton_clicked()
{
    int liczba_godzin_tydzien = 0; // wartości początkowe = 0
    double srednia_tydzien = 0;
    liczba_godzin_tydzien = liczba_pon + liczba_wto + liczba_sro + liczba_czw + liczba_pia + liczba_sob + liczba_nie;
    srednia_tydzien = double(liczba_godzin_tydzien)/168; // liczenie średniej
    ui->output_tydzien_godzin->setText(QString::number(liczba_godzin_tydzien)); // komunikaty
    ui->output_srednia->setText(QString::number(srednia_tydzien, 'f', 3));
}

void Widget::on_input_pon_spinBox_valueChanged(int arg1)
{
   liczba_pon = arg1; // przypisanie wpisanej do spinBoxa liczby do zmiennej liczba_dany dzień tygodnia
}


void Widget::on_input_wto_spinBox_2_valueChanged(int arg1)
{
    liczba_wto = arg1;
}


void Widget::on_input_sro_spinBox_3_valueChanged(int arg1)
{
    liczba_sro = arg1;
}


void Widget::on_input_czw_spinBox_4_valueChanged(int arg1)
{
    liczba_czw = arg1;
}


void Widget::on_input_pia_spinBox_5_valueChanged(int arg1)
{
    liczba_pia = arg1;
}


void Widget::on_input_sob_spinBox_6_valueChanged(int arg1)
{
    liczba_sob = arg1;
}


void Widget::on_input_nie_spinBox_7_valueChanged(int arg1)
{
    liczba_nie = arg1;
}

