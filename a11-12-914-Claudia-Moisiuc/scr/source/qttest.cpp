//
// Created by dell on 23.05.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Qttest.h" resolved

#include "qttest.h"
//
// Created by dell on 14.05.2022.
//

#include <QPainter>
#include "../header/qttest.h"



GUI::GUI(Service s):service(std::move(s))
{
    bindGui();
    populate();
    connectSignalsWithSlots();
}

void GUI::gradient(){
    QPixmap pm(20, 20);
    QPainter pmp(&pm);
    pmp.fillRect(0, 0, 10, 10, Qt::lightGray);
    pmp.fillRect(10, 10, 10, 10, Qt::lightGray);
    pmp.fillRect(0, 10, 10, 10, Qt::darkGray);
    pmp.fillRect(10, 0, 10, 10, Qt::darkGray);
    pmp.end();
    QPalette pal = palette();
    pal.setBrush(backgroundRole(), QBrush(pm));
    setAutoFillBackground(true);
    setPalette(pal);
}

void GUI::bindGui(){

    tutorials_widget = new QListWidget();
    playlist_widget = new QListWidget();

    add_button = new QPushButton("ADD");
    delete_button = new QPushButton("DELETE");
    update_button = new QPushButton("UPDATE");
    filter_button = new QPushButton("FILTER");

    transfer_button = new QPushButton(">");
    play_button = new QPushButton("PLAY");
    next_button = new QPushButton("NEXT");
    filter_user_button = new QPushButton("FILTER USER");
    csv_html_button = new QPushButton("CSV/HTML");

    title_widget = new QLineEdit();
    presenter_widget = new QLineEdit();
    minutes_widget = new QLineEdit();
    seconds_widget = new QLineEdit();
    likes_widget = new QLineEdit();
    link_widget = new QLineEdit();

    auto* griid_layout = new QGridLayout();
    auto* main_layout = new QVBoxLayout(this);

    griid_layout->addWidget(tutorials_widget, 0, 0);
    griid_layout->addWidget(playlist_widget, 0, 5);
    griid_layout->addWidget(transfer_button, 0, 1);
    main_layout->addLayout(griid_layout);

    auto* form_layout = new QFormLayout();
    form_layout->addRow("TITLE", title_widget);
    form_layout->addRow("PRESENTER", presenter_widget);
    form_layout->addRow("MINUTES", minutes_widget);
    form_layout->addRow("SECONDS", seconds_widget);
    form_layout->addRow("LIKES", likes_widget);
    form_layout->addRow("LINK", link_widget);
    main_layout->addLayout(form_layout);

    auto* grid_layout = new QGridLayout();
    grid_layout->addWidget(add_button, 1, 0);
    grid_layout->addWidget(delete_button, 1, 1);
    grid_layout->addWidget(update_button, 1, 2);
    grid_layout->addWidget(filter_button, 1, 3);

    grid_layout->addWidget(play_button, 2, 0);
    grid_layout->addWidget(next_button, 2, 1);
    grid_layout->addWidget(filter_user_button, 2, 2);
    grid_layout->addWidget(csv_html_button, 3, 0);
    main_layout->addLayout(grid_layout);
}

void GUI::populate(){
    tutorials_widget->clear();
    vector<Tutorial> tutorials = service.getAllElem();
    for(Tutorial& t : tutorials){
        tutorials_widget->addItem(QString::fromStdString(t.getTitle() + "   |   " + t.getPresenter() + "   |   " + to_string(t.getDuration().get_minutes()) + " : " + to_string(t.getDuration().get_seconds()) + "   |   " + to_string(t.getLikes()) + "   |   " + t.getLink()));
    }
}

void GUI::populate_playlist(){
    playlist_widget->clear();
    vector<Tutorial> tutorials = service.getAllElemm();
    for(Tutorial& t : tutorials){
        playlist_widget->addItem(QString::fromStdString(t.getTitle() + "   |   " + t.getPresenter() + "   |   " + to_string(t.getDuration().get_minutes()) + " : " + to_string(t.getDuration().get_seconds()) + "   |   " + to_string(t.getLikes()) + "   |   " + t.getLink()));
    }
}

void GUI::initFields(){
    int indexi = getSelectedIndex();
    Tutorial t = service.getElem(indexi);

    title_widget->setText(QString::fromStdString(t.getTitle()));
    presenter_widget->setText(QString::fromStdString(t.getPresenter()));
    minutes_widget->setText(QString::fromStdString(to_string(t.getDuration().get_minutes())));
    seconds_widget->setText(QString::fromStdString(to_string(t.getDuration().get_seconds())));
    likes_widget->setText(QString::fromStdString(to_string(t.getLikes())));
    link_widget->setText(QString::fromStdString(t.getLink()));
}

int GUI::getSelectedIndex(){
    auto indexes = tutorials_widget->selectionModel()->selectedIndexes();
    if(indexes.empty())
        return -1;

    return indexes[0].row();
}

void GUI::connectSignalsWithSlots(){
    QObject::connect(update_button, &QPushButton::clicked, this, &GUI::updateTutorial);
    QObject::connect(add_button, &QPushButton::clicked, this, &GUI::addTutorial);
    QObject::connect(delete_button, &QPushButton::clicked, this, &GUI::deleteTutorial);
    QObject::connect(tutorials_widget, &QListWidget::clicked, this, &GUI::initFields);
    QObject::connect(transfer_button, &QPushButton::clicked, this, &GUI::addPlaylist);
    QObject::connect(next_button, &QPushButton::clicked, this, &GUI::next);
    QObject::connect(play_button, &QPushButton::clicked, this, &GUI::play);
    QObject::connect(filter_button,  &QPushButton::clicked, this, &GUI::filter);
    QObject::connect(csv_html_button,  &QPushButton::clicked, this, &GUI::open);
    QObject::connect(filter_user_button,  &QPushButton::clicked, this, &GUI::filter_user);
}

void GUI::deleteTutorial() {
    int indexi = getSelectedIndex();
    if(indexi == -1){
        QMessageBox::critical(this, QString::fromStdString(" Error : ( "),  QString::fromStdString(" Nothing selected "));
    }
    //service.removeTutorial(service.getElem(index).getTitle(), service.getElem(index).getPresenter(), service.getElem(index).getDuration().get_minutes(), service.getElem(index).getDuration().get_seconds(), service.getElem(index).getLikes(), service.getElem(index).getLink());
    service.removeTutorial(service.getElem(indexi).getTitle(), service.getElem(indexi).getPresenter());
    populate();
}

void GUI::addTutorial() {
    string title = this->title_widget->text().toStdString();
    string presenter = this->presenter_widget->text().toStdString();
    int min = stoi(this->minutes_widget->text().toStdString());
    int sec = stoi(this->seconds_widget->text().toStdString());
    Duration duration;
    duration.set_seconds(sec);
    duration.set_minutes(min);
    int likes = stoi(this->likes_widget->text().toStdString());
    string link = this->link_widget->text().toStdString();

    if(service.find(title, presenter) != -1)
        QMessageBox::critical(this, QString::fromStdString(" Error : ( "),  QString::fromStdString(" The element already exists "));

    service.addTutorial(title, presenter, duration, likes, link);

    populate();
}


void GUI::updateTutorial() {
    string title = this->title_widget->text().toStdString();
    string presenter = this->presenter_widget->text().toStdString();
    int min = stoi(this->minutes_widget->text().toStdString());
    int sec = stoi(this->seconds_widget->text().toStdString());
    Duration duration;
    duration.set_seconds(sec);
    duration.set_minutes(min);
    int likes = stoi(this->likes_widget->text().toStdString());
    string link = this->link_widget->text().toStdString();

    if(service.find(title, presenter) == -1)
        QMessageBox::critical(this, QString::fromStdString(" Error : ( "),  QString::fromStdString(" No such element "));

    service.updateTutorial(title, presenter, duration, likes, link);

    populate();
}


void GUI::addPlaylist(){
    string title = this->title_widget->text().toStdString();
    string presenter = this->presenter_widget->text().toStdString();
    int min = stoi(this->minutes_widget->text().toStdString());
    int sec = stoi(this->seconds_widget->text().toStdString());
    Duration duration;
    duration.set_seconds(sec);
    duration.set_minutes(min);
    int likes = stoi(this->likes_widget->text().toStdString());
    string link = this->link_widget->text().toStdString();

    if(service.findUser(title, presenter) != -1)
        QMessageBox::critical(this, QString::fromStdString(" Error : ( "),  QString::fromStdString(" The element already exists "));

    service.addUser(title, presenter, duration, likes, link);

    populate_playlist();
}


void GUI::next(){
    if(service.getAllElemm().empty())
        QMessageBox::critical(this, QString::fromStdString(" Error : ( "),  QString::fromStdString(" No tutorials in playlist "));
    else {
        Tutorial t = service.getElemm();
        service.nextUser();

        title_widget->setText(QString::fromStdString(t.getTitle()));
        presenter_widget->setText(QString::fromStdString(t.getPresenter()));
        minutes_widget->setText(QString::fromStdString(to_string(t.getDuration().get_minutes())));
        seconds_widget->setText(QString::fromStdString(to_string(t.getDuration().get_seconds())));
        likes_widget->setText(QString::fromStdString(to_string(t.getLikes())));
        link_widget->setText(QString::fromStdString(t.getLink()));
    }
}

void GUI::play(){
    if(service.getAllElemm().empty())
        QMessageBox::critical(this, QString::fromStdString(" Error : ( "),  QString::fromStdString(" No tutorials in playlist "));
    else{
        service.playUser();
        service.removeUser();
        populate_playlist();}
}

void GUI::filter(){

    tutorials_widget->clear();
    string presenter = this->presenter_widget->text().toStdString();
    std::vector<Tutorial> copy;
    copy = service.filter(presenter);
    for (Tutorial &t: copy) {
        tutorials_widget->addItem(QString::fromStdString(
                t.getTitle() + "   |   " + t.getPresenter() + "   |   " + to_string(t.getDuration().get_minutes()) +
                " : " + to_string(t.getDuration().get_seconds()) + "   |   " + to_string(t.getLikes()) + "   |   " +
                t.getLink()));
    }
}

void GUI::open(){
    service.open();
}

void GUI::filter_user(){
    if(service.getAllElemm().empty())
        QMessageBox::critical(this, QString::fromStdString(" Error : ( "),  QString::fromStdString(" No tutorials in playlist "));
    else {
        playlist_widget->clear();
        string presenter = this->presenter_widget->text().toStdString();
        std::vector<Tutorial> copy;
        copy = service.filterUser(presenter);
        for (Tutorial &t: copy) {
            playlist_widget->addItem(QString::fromStdString(
                    t.getTitle() + "   |   " + t.getPresenter() + "   |   " + to_string(t.getDuration().get_minutes()) +
                    " : " + to_string(t.getDuration().get_seconds()) + "   |   " + to_string(t.getLikes()) + "   |   " +
                    t.getLink()));
        }
    }
}
