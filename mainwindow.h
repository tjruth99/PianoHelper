#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

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
    void on_chordsButton_clicked();

    void on_scalesButton_clicked();

private:
    Ui::MainWindow *ui;
    QString notes[12] = {"A", "A#/Bb", "B", "C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab"};
    QVector<QLabel*> notelabels;

    void updatePiano(int * noteArray, int n);
};

#endif // MAINWINDOW_H
