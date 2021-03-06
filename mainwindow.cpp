#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Chords.h"
#include "Scales.h"
#include "string.h"

#include <QMediaPlayer>
#include <QFileInfo>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    noteURls.append(QUrl("qrc:/notes/Notes/C4.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/Db4.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/D4.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/Eb4.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/E4.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/F4.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/Gb4.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/G4.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/Ab4.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/A4.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/Bb4.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/B4.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/C5.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/Db5.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/D5.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/Eb5.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/E5.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/F5.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/Gb5.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/G5.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/Ab5.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/A5.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/Bb5.wav"));
    noteURls.append(QUrl("qrc:/notes/Notes/B5.wav"));

    for(int i = 0; i < 27; i++){
        notelabels.at(i)->setVisible(false);
    }

    curChordPos = 0;

    PH_Chord n = PH_Chord();

    n.chord = new int[0];
    n.n = 0;

    for(int i = 0; i < 4; i++){
        chordProgression.append(n);
    }

    EarTrainingPlayer = new QMediaPlayer(this);
    totalGuesses = 0;
    correctGuesses = 0;
    newGuess = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::playNotes(){
    if(currentPianoNotesN == 0){ return; }

    QVector<QMediaPlayer> chrd;
    for(int i = 0; i < currentPianoNotesN; i++){
        QMediaPlayer * p = new QMediaPlayer(this);
        p->setMedia(noteURls.at(currentPianoNotes[i]));
        p->play();
    }
}

void MainWindow::updatePiano(int * noteArray, int n){
    int last = noteArray[0];
    int curNote;

    for(int i = 0; i < 27; i++){
        notelabels.at(i)->setVisible(false);
    }

    for(int i = 0; i < n; i++){

        curNote = noteArray[i];
        if(curNote < last)
            curNote += 12;

        last = curNote;
        notelabels.at(curNote)->setVisible(true);

    }

    currentPianoNotes = noteArray;
    currentPianoNotesN = n;
}


void MainWindow::on_chordsButton_clicked()
{
    int chordTypeIndex = ui->ChordsTypeComboBox->currentIndex();
    int noteInt = ui->ChordsNoteComboBox->currentIndex();
    int chordLength;

    int * chord = findChord(noteInt, chordTypeIndex, &chordLength);

    QString o;

    for(int i = 0; i < chordLength; i++){
       o.append(notes[chord[i]]);
       if(i != chordLength-1 )
            o.append(", ");
    }

    ui->ChordsOutputLabel->setText(o);
    updatePiano(chord, chordLength);
    playNotes();
}

void MainWindow::on_scalesButton_clicked()
{
    int scaleTypeIndex = ui->ScaleTypeComboBox->currentIndex();
    int noteInt = ui->ScaleNoteComboBox->currentIndex();
    int scaleLength;

    int * scale = findScale(noteInt, scaleTypeIndex, &scaleLength);

    QString o;

    for(int i = 0; i < scaleLength; i++){
       o.append(notes[scale[i]]);
       if(i != scaleLength - 1 )
            o.append(", ");
    }

    ui->ScaleOutputLabel->setText(o);

    updatePiano(scale, scaleLength);
}

void MainWindow::on_addChordButton_clicked()
{
    int chordTypeIndex = ui->ProgTypeComboBox->currentIndex();
    int noteInt = ui->ProgNoteComboBox->currentIndex();
    int chordLength;

    int * chord = findChord(noteInt, chordTypeIndex, &chordLength);

    updatePiano(chord, chordLength);

    // Add code to implement chord progression

    PH_Chord c = {chord, chordLength};

    chordProgression.replace(curChordPos, c);

    switch(curChordPos){
        case 0:
            ui->chord_1->setText(notes[noteInt]);
            break;
        case 1:
            ui->chord_2->setText(notes[noteInt]);
            break;
        case 2:
            ui->chord_3->setText(notes[noteInt]);
            break;
        case 3:
            ui->chord_4->setText(notes[noteInt]);
            break;
    }

    curChordPos = (curChordPos + 1) % 4;
}

void MainWindow::on_pushButton_clicked(){}

void MainWindow::on_chord_1_clicked()
{
    PH_Chord c = chordProgression.at(0);

    updatePiano(c.chord, c.n);

    curChordPos = 0;
}

void MainWindow::on_chord_2_clicked()
{
    PH_Chord c = chordProgression.at(1);

    updatePiano(c.chord, c.n);

    curChordPos = 1;
}

void MainWindow::on_chord_3_clicked()
{
    PH_Chord c = chordProgression.at(2);

    updatePiano(c.chord, c.n);

    curChordPos = 2;
}

void MainWindow::on_chord_4_clicked()
{
    PH_Chord c = chordProgression.at(3);

    updatePiano(c.chord, c.n);

    curChordPos = 3;
}

void MainWindow::on_remove_1_clicked()
{
    PH_Chord n = PH_Chord();
    n.n = 0;
    chordProgression.replace(0, n);

    ui->chord_1->setText("Chord 1");
}

void MainWindow::on_remove_2_clicked()
{
    PH_Chord n = PH_Chord();
    n.n = 0;
    chordProgression.replace(1, n);

    ui->chord_2->setText("Chord 2");
}

void MainWindow::on_remove_3_clicked()
{
    PH_Chord n = PH_Chord();
    n.n = 0;
    chordProgression.replace(2, n);

    ui->chord_3->setText("Chord 3");
}

void MainWindow::on_remove_4_clicked()
{
    PH_Chord n = PH_Chord();
    n.n = 0;
    chordProgression.replace(3, n);

    ui->chord_4->setText("Chord 4");
}

void MainWindow::on_playButton_clicked()
{
    playNotes();
}

void MainWindow::on_PlayNoteButton_clicked()
{
    if(newGuess == 1){
        ui->GuessLabel->setText("");
        ui->CorrectLabel->setText(notes[curNoteGuess]);
        totalGuesses++;
        updateScore();
    }

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    curNoteGuess = qrand() % 12;
    qInfo("%d", curNoteGuess);

    EarTrainingPlayer->setMedia(noteURls.at(curNoteGuess));
    EarTrainingPlayer->play();
    newGuess = 1;

    QPalette p = ui->EarTrainingState->palette();
    p.setColor(QPalette::Window, QColor(Qt::blue));
    ui->EarTrainingState->setPalette(p);
}

void MainWindow::on_RepeatButton_clicked()
{
    EarTrainingPlayer->play();
}

void MainWindow::on_GuessButton_clicked()
{
    if(newGuess == 0){
        return;
    }
    newGuess = 0;

    QPalette p = ui->EarTrainingState->palette();

    totalGuesses++;
    if(ui->GuessNoteComboBox->currentIndex() == curNoteGuess){
        correctGuesses++;
        p.setColor(QPalette::Window, QColor(Qt::green));
    } else {
        p.setColor(QPalette::Window, QColor(Qt::red));
    }

    ui->GuessLabel->setText(notes[ui->GuessNoteComboBox->currentIndex()]);
    ui->CorrectLabel->setText(notes[curNoteGuess]);

    updateScore();
    ui->EarTrainingState->setPalette(p);
}

void MainWindow::on_ResetButton_clicked()
{
    correctGuesses = 0;
    totalGuesses = 0;

    updateScore();

    QPalette p = ui->EarTrainingState->palette();
    p.setColor(QPalette::Window, QColor(Qt::blue));
    ui->EarTrainingState->setPalette(p);
}

void MainWindow::updateScore(){

    QString s;
    s.sprintf("%d/%d (%.2f%%)", correctGuesses, totalGuesses, ((double)correctGuesses/totalGuesses)*100);
    ui->ScoreLabel->setText(s);

}
