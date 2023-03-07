//
// Created by dell on 23.05.2022.
//

#ifndef A11_12_914_CLAUDIA_MOISIUC_QTTEST_H
#define A11_12_914_CLAUDIA_MOISIUC_QTTEST_H

#include <QApplication>
#include <QWidget.h>
#include "service.h"
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <vector>
#include <QMessageBox>

using namespace std;

class GUI: public QWidget
{
private:
    Service service;
    QListWidget* tutorials_widget;
    QListWidget* playlist_widget;
    QPushButton *add_button;
    QPushButton* delete_button;
    QPushButton* csv_html_button;
    QPushButton* update_button;
    QPushButton* filter_button;
    QPushButton* filter_user_button;
    QPushButton* transfer_button;
    QPushButton* play_button;
    QPushButton* next_button;
    QLineEdit* title_widget, *presenter_widget, *minutes_widget, *seconds_widget, *likes_widget, *link_widget;
    void bindGui();
    void populate();
    void initFields();
    int getSelectedIndex();
    void connectSignalsWithSlots();
    void deleteTutorial();
    void addTutorial();
    void updateTutorial();
    void populate_playlist();
    void addPlaylist();
    void next();
    void play();
    void filter();
    void open();
    void filter_user();
    void gradient();
public:
    GUI(Service service);
};