#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_iniciar_clicked();

    void timerEvent(QTimerEvent *event);
    void on_parar_clicked();

    void on_iniciar_customContextMenuRequested(const QPoint &pos);

    void on_iniciar_windowIconTextChanged(const QString &iconText);

    void on_parar_windowIconTextChanged(const QString &iconText);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
