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
    QString notes[12] = {"C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab", "A", "A#/Bb", "B"};
    QVector<QLabel*> notelabels;
    int * currentPianoNotes;
    int currentPianoNotesN;

    void updatePiano(int * noteArray, int n);
};

#endif // MAINWINDOW_H
