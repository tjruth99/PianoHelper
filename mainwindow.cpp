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

    // There is a better solution to this, but want to get the basic logic working first
    notelabels.append(ui->notelabel_00);
    notelabels.append(ui->notelabel_01);
    notelabels.append(ui->notelabel_02);
    notelabels.append(ui->notelabel_03);
    notelabels.append(ui->notelabel_04);
    notelabels.append(ui->notelabel_05);
    notelabels.append(ui->notelabel_06);
    notelabels.append(ui->notelabel_07);
    notelabels.append(ui->notelabel_08);
    notelabels.append(ui->notelabel_09);
    notelabels.append(ui->notelabel_10);
    notelabels.append(ui->notelabel_11);
    notelabels.append(ui->notelabel_12);
    notelabels.append(ui->notelabel_13);
    notelabels.append(ui->notelabel_14);
    notelabels.append(ui->notelabel_15);
    notelabels.append(ui->notelabel_16);
    notelabels.append(ui->notelabel_17);
    notelabels.append(ui->notelabel_18);
    notelabels.append(ui->notelabel_19);
    notelabels.append(ui->notelabel_20);
    notelabels.append(ui->notelabel_21);
    notelabels.append(ui->notelabel_22);
    notelabels.append(ui->notelabel_23);
    notelabels.append(ui->notelabel_24);
    notelabels.append(ui->notelabel_25);
    notelabels.append(ui->notelabel_26);

    for(int i = 0; i < 27; i++){
        notelabels.at(i)->setVisible(false);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatePiano(int * noteArray, int n){
    for(int i = 0; i < 27; i++){
        notelabels.at(i)->setVisible(false);
    }

    for(int i = 0; i < n; i++){
        notelabels.at(noteArray[i])->setVisible(true);
    }
}

void MainWindow::on_chordsButton_clicked()
{
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
            chord = maj9(noteInt);
            chordLength = 5;
            break;
        case 3:
            chord = maj11(noteInt);
            chordLength = 6;
            break;
        case 4:
            chord = maj13(noteInt);
            chordLength = 7;
            break;
        case 5:
            chord = minor(noteInt);
            chordLength = 3;
            break;
        case 6:
            chord = min7(noteInt);
            chordLength = 4;
            break;
        case 7:
            chord = min9(noteInt);
            chordLength = 5;
            break;
        case 8:
            chord = min11(noteInt);
            chordLength = 6;
            break;
        case 9:
            chord = min13(noteInt);
            chordLength = 7;
            break;
        case 10:
            chord = d7(noteInt);
            chordLength = 4;
            break;
        case 11:
            chord = d9(noteInt);
            chordLength = 5;
            break;
        case 12:
            chord = d11(noteInt);
            chordLength = 6;
            break;
        case 13:
            chord = d13(noteInt);
            chordLength = 7;
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
    updatePiano(chord, chordLength);
}

void MainWindow::on_scalesButton_clicked()
{
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
