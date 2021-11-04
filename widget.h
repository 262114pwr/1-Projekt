#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    static int liczba_pon, liczba_wto, liczba_sro, liczba_czw, liczba_pia, liczba_sob, liczba_nie;

private slots:
    void on_input_godzin_spinBox_valueChanged(int arg1);

    void on_input_godzin_spinBox_textChanged(const QString &arg1);

    void on_input_pon_spinBox_valueChanged(int arg1);

    void on_input_wto_spinBox_2_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_input_sro_spinBox_3_valueChanged(int arg1);

    void on_input_czw_spinBox_4_valueChanged(int arg1);

    void on_input_pia_spinBox_5_valueChanged(int arg1);

    void on_input_sob_spinBox_6_valueChanged(int arg1);

    void on_input_nie_spinBox_7_valueChanged(int arg1);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
