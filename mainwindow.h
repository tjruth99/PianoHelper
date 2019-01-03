#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMediaPlayer>

struct PH_Chord{
    int * chord;
    int n;
};

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

    void on_addChordButton_clicked();

    void on_chord_1_clicked();

    void on_chord_2_clicked();

    void on_chord_3_clicked();

    void on_chord_4_clicked();

    void on_remove_1_clicked();

    void on_remove_2_clicked();

    void on_remove_3_clicked();

    void on_remove_4_clicked();

    void on_pushButton_clicked();

    void on_playButton_clicked();

    void on_PlayNoteButton_clicked();

    void on_RepeatButton_clicked();

    void on_GuessButton_clicked();

    void on_ResetButton_clicked();

private:
    Ui::MainWindow *ui;
    QString notes[12] = {"C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab", "A", "A#/Bb", "B"};
    QVector<QLabel*> notelabels;
    QVector<PH_Chord> chordProgression;
    int curChordPos;
    int * currentPianoNotes;
    int currentPianoNotesN;

    void updatePiano(int * noteArray, int n);
    void playNotes();
    void updateScore();

    QMediaPlayer * player;
    QVector<QUrl> noteURls;

    QMediaPlayer * EarTrainingPlayer;
    int correctGuesses;
    int totalGuesses;
    int curNoteGuess;
    int newGuess;
};

#endif // MAINWINDOW_H
