#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    chart_window = new QMainWindow(this); // nowy obiekt niejawnie
    liczba_pon = 0; // zmienne prywatne potrzebne do liczenia
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
    ilosc_sekund = 0;
    ilosc_godzin = 0;
    set0 = new QBarSet("Poniedziałek, Wtorek, Środa, Czwartek, Piątek, Sobota, Niedziela"); // ile wartosci
    series = new QBarSeries(); // utworzenie obiekty/zmienne
    chart = new QChart(); // 7 kategorii
    axisX = new QBarCategoryAxis();
    axisY = new QValueAxis();
    chartView = new QChartView(chart);


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
    } else { // zniknięcie uwagi
        ui->label_invisible->setStyleSheet("QLabel {background-color : none; color : none; }");
        ui->label_invisible->setText("");
    }

    przerwa_output = (double(ilosc_godzin)/double(ilosc_do_przerwy)) * ilosc_przerw; // ile przerw mamy
    ui->output_przerwa->setText(QString::number(przerwa_output));
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
    liczba_pon = 0; // reset wszystkiego
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
    ui->output_czas_przerw->setText(QString::number(0));
    ui->output_tydzien_godzin->setText(QString::number(0));
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

void Widget::on_pushButton_2_clicked()
{
   if (set0->count() != 0) // zmienna barset(slupki);
         set0->remove(0, set0->count()); // reset
   *set0 << liczba_pon << liczba_wto << liczba_sro << liczba_czw << liczba_pia << liczba_sob << liczba_nie;
   set0->setColor("magenta"); // 7 zmiennych; przelaczamy; 1 bar(set0) 7 pozycji
   series->append(set0); // dokladamy do serii, bo nie mozemy dodac samego bar
   chart->addSeries(series); //dodajemy serie do wykresu
   chart->setTitle("Czas przed komputerem w tygodniu");
   //chart->setAnimationOptions(QChart::SeriesAnimations); // jak sie pojawia

   categories << "Poniedziałek" << "Wtorek" << "Środa" << "Czwartek" << "Piątek" << "Sobota" << "Niedziela";
// napisy pod spodem
   axisX->append(categories); // podpis pod osia X; klasa dodaje kategorie do osi wykresu
   chart->addAxis(axisX, Qt::AlignBottom); // pod wykresem
   series->attachAxis(axisX); // serie dodajemy do osi X; Dołącza oś określoną przez oś do serii

   axisY->setRange(0,24); // ograniczenie
   chart->addAxis(axisY, Qt::AlignLeft); // Y po lewej
   series->attachAxis(axisY); // dodajemy serie do osi y
   chart->legend()->setVisible(false); // brak legendy

   // chartView->setRenderHint(QPainter::Antialiasing);
   chart_window->setCentralWidget(chartView); // nowe okienko na srodku
   chart_window->resize(820, 600); // o takiej wielkosci
   chart_window->show(); // pokazuje sie

}


void Widget::on_pushButton_4_clicked()
{
    this->czas_start = QTime::currentTime(); // rozpoczęcie odliczania
    czas_start_text = czas_start.toString("hh:mm"); // zamiana na str
    ui->lcdNumber_czas_start->display(czas_start_text); // wyswietlanie czasu
}


void Widget::on_pushButton_5_clicked()
{
    this->czas_stop = QTime::currentTime(); // zakonczenie odliczania
    czas_stop_text = czas_stop.toString("hh:mm"); // zamiana na str w formacie hh:mm
    ui->lcdNumber_czas_stop->display(czas_stop_text); // wyswietlanie czasu
    ilosc_sekund = czas_start.secsTo(czas_stop); // od start do stop liczenie sekund; ile sekund bylo
    ui->output_czas_sekundy->setText(QString::number(ilosc_sekund)); // wyswietlenie ilosci sekund
    ilosc_godzin = ilosc_sekund / 3600; // wyliczenie ilosci godzin
    ui->input_godzin_spinBox->setValue(ilosc_godzin); // ustawienie ilosc_godzin do wyliczen
}

