//
// Created by dell on 09.05.2022.
//

#include "../header/ui.h"

#include <utility>


Ui::Ui(Service s):service(std::move(s))
{
}

void Ui::DestroyUi(){
    service.DestroyService();
}

void Ui::options()
{
    cout<<"Modes:\n";
    cout<<"   a. Administrator\n";
    cout<<"   u. User\n";
    cout<<"   e. Exit\n";
}

void Ui::options_mode()
{
    cout<<"----------------------------------------------------------------\n";
    cout<<"a. list all tutorials\n";
    cout<<"l. see tutorials and add to the watch list\n";
    cout<<"p. play tutorials from watch list\n";
    cout<<"s. list tutorials with the same presenter\n";
    cout<<"o. open watchlist.\n";
    cout<<"e. exit\n";
    cout<<"----------------------------------------------------------------\n";
}

void Ui::options_admin()
{
    cout<<"***************************************************************\n";
    cout<<"l. list all tutorials\n";
    cout<<"a. add a tutorial\n";
    cout<<"r. remove a tutorial\n";
    cout<<"u. update a tutorial\n";
    cout<<"s. list tutorials with the same presenter\n";
    cout<<"e. exit\n";
    cout<<"***************************************************************\n";
}

void Ui::printHead()
{
    cout
            <<left
            <<setw(25)
            <<"TITLE"
            <<left
            <<setw(25)
            <<"PRESENTER"
            <<left
            <<setw(12)
            <<"DURATION"
            <<left
            <<setw(8)
            <<"LIKES"
            <<left
            <<setw(18)
            <<"LINK"
            <<endl;
}

void Ui::printElem(const Tutorial& v)
{
    cout
            <<left
            <<setw(25)
            <<v.getTitle()
            <<left
            <<setw(25)
            <<v.getPresenter()
            <<left
            <<setw(4)
            <<v.getDuration().get_minutes()
            <<setw(8)
            <<v.getDuration().get_seconds()
            <<left
            <<setw(8)
            <<v.getLikes()
            <<left
            <<setw(8)
            <<v.getLink()
            <<endl;
}

void Ui::printUser(int i)
{
    printHead();
    Tutorial v;
    v = service.getElem(i);
    printElem(v);
}

void Ui::addTutorial(int u)
{
    char title[70], presenter[70], link[70];
    int like, minutes, seconds;
    Duration d;
    cout<<"Title:  ";
    cin.get();
    cin.get(title, 70);
    cout<<"Presentor:  ";
    cin.get();
    cin.get(presenter, 70);
    cout<<"Duration:\n";
    cout<<"   Minutes:  ";
    cin>>minutes;
    cout<<"   Seconds:  ";
    cin>>seconds;
    d = Duration(minutes, seconds);
    cout<<"Likes:  ";
    cin>>like;
    cout<<"Link:   ";
    cin.get();
    cin.get(link, 70);
    cin.get();
    if(service.find(title, presenter) != -1)
        cout<<"The tutorial already exists. :(\n";
    else if(u == 0)
        service.addTutorial(title, presenter, d, like, link);
    else
        service.addUser(title, presenter, d, like, link);
}

void Ui::removeTutorial()
{
    char title[70], pres[70];
    cout<<"Title:";
    cin.get();
    cin.get(title, 70);
    cout<<"Presentor:  ";
    cin.get();
    cin.get(pres, 70);
    if(service.find(title, pres) == -1)
        cout<<"The tutorial does not exist. :(\n";
    else
        service.removeTutorial(title, pres);
}

void Ui::updateTutorial()
{
    char title[70], presenter[70], link[70];
    int like, minutes, seconds;
    Duration d;
    cout<<"Title:  ";
    cin.get();
    cin.get(title, 70);
    cout<<"Presentor:  ";
    cin.get();
    cin.get(presenter, 70);
    cout<<"Duration:\n";
    cout<<"   Minutes:  ";
    cin>>minutes;
    cout<<"   Seconds:  ";
    cin>>seconds;
    d = Duration(minutes, seconds);
    cout<<"Likes:  ";
    cin>>like;
    cout<<"Link:   ";
    cin.get();
    cin.get(link, 70);
    cin.get();
    if(service.find(title, presenter) == -1)
        cout<<"The tutorial does not exist. :(\n";
    else
        service.updateTutorial(title, presenter, d, like, link);
}

void Ui::list()
{
    printHead();
    Tutorial v;
    std::vector<Tutorial> data = this->service.getAllElem();
    for (auto i = data.begin(); i < data.end(); i++)
    {
        //v = service.getElem(i);
        printElem(*i);
    }

}

void Ui::listUser()
{
    printHead();
    for (auto i = ui.begin(); i < ui.end(); i++)
    {
        //v = service.getElem(i);
        printElem(*i);
    }
}

/*
void Ui::lisst()
{
    printHead();
    Tutorial* v;
    for (int i=0; i<service.getlen(); i++)
    {
        v = service.getElemm();
        printElem(*v);
        service.nextUser();
    }

}*/

void Ui::same()
{
    char p[70];
    cout<<"Presenter:";
    cin.get();
    cin.getline(p, 70);
    ui = service.filter(p);
}

void Ui::sameUser()
{
    char p[70];
    cout<<"Presenter:";
    cin.get();
    cin.getline(p, 70);
    ui = service.filterUser(p);
}

void Ui::copy(){
    Tutorial v;
    for (int i=0; i<service.getlen(); i++) {
        v = service.getElemm();
        ui.push_back(v);
        service.nextUser();
    }
}


void Ui::menu()
{
    service.startdata();
    int ok = 1, u = 0, a = 0, i = 0;
    char option, mode, yn;
    while (ok==1)
    {
        options();
        cout<<"Mode:  ";
        cin>>mode;
        if (mode == 'u') {
            u = 1;
            options_mode();
        }
        else if(mode == 'a'){
            a = 1;
            options_admin();
        }
        else if(mode == 'e')
            ok = 0;
        else
            cout<<"Invalid input";

        while(u == 1) {
            cout << "Option: ";
            cin>>option;
            if (option == 'e')
                u = 0;
            else if(option == 'a'){
                copy();
                listUser();
                ui.clear();
            }
            else if(option == 'p')
            {
                if(service.getlen() > 0)
                { Tutorial v;
                    v = service.getElemm();
                    printElem(v);
                    service.playUser();
                    cout<<"Did you like the tutorial? Would you like to give it a like?  y/n  \n";
                    cin>>yn;
                    if(yn == 'y')
                        service.like();
                    service.removeUser();}
                else cout<<"No more tutorials to play\n";
            }
            else if(option == 's')
            {
                sameUser();
                listUser();
                ui.clear();
            }
            else if(option == 'l') {
                printUser(i);
                cout<<"Would you like to add it to the watch list?  y/n \n";
                cin>>yn;
                if (yn == 'y')
                    service.addUser(service.getElem(i).getTitle(), service.getElem(i).getPresenter(), service.getElem(i).getDuration(), service.getElem(i).getLikes(), service.getElem(i).getLink());
                i++;
                i %= service.getSize();
            }
            else if(option == 'o'){
                service.open();
            }
            else cout<<"Invalid option";
        }

        while(a == 1) {
            cout << "Option: ";
            cin >> option;
            if (option == 'a')
                addTutorial(0);
            else if (option == 'r')
                removeTutorial();
            else if (option == 'u')
                updateTutorial();
            else if (option == 'l')
                list();
            else if (option == 's')
            {same();
                listUser();
                ui.clear();
            }
            else if (option == 'e')
                a = 0;
            else
                cout << "Invalid input\n";
        }
    }
    //
    //addTutorial();
    service.DestroyService();
}
