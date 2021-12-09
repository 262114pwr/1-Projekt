#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QMainWindow> // do wykresu
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QTime>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private slots:
    void on_input_godzin_spinBox_valueChanged(int arg1);

    void on_input_pon_spinBox_valueChanged(int arg1);

    void on_input_wto_spinBox_2_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_input_sro_spinBox_3_valueChanged(int arg1);

    void on_input_czw_spinBox_4_valueChanged(int arg1);

    void on_input_pia_spinBox_5_valueChanged(int arg1);

    void on_input_sob_spinBox_6_valueChanged(int arg1);

    void on_input_nie_spinBox_7_valueChanged(int arg1);

    void on_input_limit_spinBox_valueChanged(int arg1);

    void on_input_ilosc_przerw_spinBox_valueChanged(int arg1);

    void on_input_ilosc_do_przerwy_spinBox_valueChanged(int arg1);

    void on_input_dlugosc_przerwy_spinBox_valueChanged(int arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Widget *ui;
    int limit_godz, ilosc_przerw, ilosc_do_przerwy, dlugosc_przerwy, ilosc_sekund, ilosc_godzin;
    int liczba_pon, liczba_wto, liczba_sro, liczba_czw, liczba_pia, liczba_sob, liczba_nie;
    QString czas_start_text, czas_stop_text;
    QBarSet *set0; // deklaracja zmiennych potrzebnych do wyswietlenie wykresu
    QBarSeries *series;
    QChart *chart;
    QStringList categories;
    QBarCategoryAxis *axisX;
    QValueAxis *axisY;
    QChartView *chartView;
    QMainWindow *chart_window;
    QTime czas_start, czas_stop;

};
#endif // WIDGET_H
