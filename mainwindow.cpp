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

void MainWindow::on_chordsButton_clicked()
{
    QString notes[12] = {"A", "A#/Bb", "B", "C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab"};

    QString s = ui->ChordsNoteComboBox->currentText();
    int cts = ui->ChordsTypeComboBox->currentIndex();
    QString o;
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
       o.append(notes[chord[i]]);
       if(i != chordLength-1 )
            o.append(", ");
    }

    ui->ChordsOutputLabel->setText(o);
}

void MainWindow::on_scalesButton_clicked()
{
    QString notes[12] = {"A", "A#/Bb", "B", "C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab"};

    QString s = ui->ScaleNoteComboBox->currentText();
    int cts = ui->ScaleTypeComboBox->currentIndex();
    QString o;
    int noteInt = -1;

    for(int i = 0; i < 12; i++){
        if(QString::compare(notes[i], s) == 0){
            noteInt = i;
            break;
        }
    }

    int * scale;

    switch(cts){
        case 0:
            scale = ionian(noteInt);
            break;
        case 1:
            scale = dorian(noteInt);
            break;
        case 2:
            scale = phrygian(noteInt);
            break;
        case 3:
            scale = lydian(noteInt);
            break;
        case 4:
            scale = mixolydian(noteInt);
            break;
        case 5:
            scale = aeolian(noteInt);
            break;
        case 6:
            scale = locrian(noteInt);
            break;
        default:
            scale = ionian(0);
    }

    for(int i = 0; i < 7; i++){
       o.append(notes[scale[i]]);
       if(i != 6 )
            o.append(", ");
    }

    ui->ScaleOutputLabel->setText(o);
}
