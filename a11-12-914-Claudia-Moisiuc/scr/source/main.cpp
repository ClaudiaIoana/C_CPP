//
// Created by dell on 09.05.2022.
//


#include "../header/ui.h"

#include <fstream>
using namespace std;
//void Test();


int main()
{

    Repository* repository = new Repository_file{};
    cout<<"What type of file would you like to use? csv or html?";
    int ok = 1;
    char ch[20];
    while(ok == 1)
    {
        cin.get(ch,20);
        if(strcmp(ch, "csv") == 0) {
            Repository_playlist* playlist = new Playlist_file_csv{};
            Service service(repository, playlist);
            Ui ui(service);
            ui.menu();
            ok = 0;
            ui.DestroyUi();
        }
        else if(strcmp(ch, "html") == 0) {
            Repository_playlist* playlist = new Playlist_file_html{};
            Service service(repository, playlist);
            Ui ui(service);
            ui.menu();
            ui.DestroyUi();
            ok = 0;
        }
        else
            cout<<"invalid input";
    }

    return 0;
}
