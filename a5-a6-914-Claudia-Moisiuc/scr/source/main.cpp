//
// Created by dell on 19.03.2022.
//
#include "../header/ui.h"
using namespace std;
void Test();

 int main()
 {
     Test();
     Repository repository;
     Playlist playlist;
     Service service(repository, playlist);
     Ui ui(service);
     ui.menu();

     return 0;
 }
//