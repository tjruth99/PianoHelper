#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Chords.h"
#include "Scales.h"
#include "string.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString notes[12] = {"A", "A#/Bb", "B", "C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab"};

    QString s = ui->NoteComboBox->currentText();
    int cts = ui->ChordTypeComboBox->currentIndex();
    QString c;
    int noteInt = -1;
    int chordLength = 0;

    for(int i = 0; i < 12; i++){
        if(QString::compare(notes[i], s) == 0){
            noteInt = i;
            break;
        }
    }

    int * chord;

    switch(cts){
        case 0:
            chord = major(noteInt);
            chordLength = 3;
            break;
        case 1:
            chord = maj7(noteInt);
            chordLength = 4;
            break;
        case 2:
            chord = maj11(noteInt);
            chordLength = 5;
            break;
        case 3:
            chord = maj13(noteInt);
            chordLength = 6;
            break;
        case 4:
            chord = minor(noteInt);
            chordLength = 3;
            break;
        case 5:
            chord = min7(noteInt);
            chordLength = 4;
            break;
        case 6:
            chord = min11(noteInt);
            chordLength = 5;
            break;
        case 7:
            chord = min13(noteInt);
            chordLength = 6;
            break;
        default:
            chord = major(0);
    }

    for(int i = 0; i < chordLength; i++){
       c.append(notes[chord[i]]);
       if(i != chordLength-1 )
            c.append(", ");
    }

    ui->OutputLabel->setText(c);
}


