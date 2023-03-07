//
// Created by dell on 21.03.2022.
//

#include "../header/ui.h"
#include <cassert>

void testService(){
    Repository repository = Repository();
    Playlist playlist = Playlist();

    Service service = Service(repository, playlist);
    Duration d;
    d.set_seconds(12);
    d.set_minutes(13);
    service.addTutorial("input", "Ana", d, 12, "sjdh");
    assert(service.getSize() == 1);
    assert(service.getElem(0)->getPresenter() == "Ana");
    assert(service.getElem(0)->getTitle() == "input");
    assert(service.getElem(0)->getLink() == "sjdh");
    assert(service.getElem(0)->getLikes() == 12);
    assert(service.getElem(0)->getDuration().get_minutes() == 13);
    assert(service.getElem(0)->getDuration().get_seconds() == 12);

    service.addTutorial("output", "Alia", d, 11, "aaa");
    service.removeTutorial("input", "Ana");
    assert(service.getSize() == 1);
    assert(service.getElem(0)->getTitle() == "output");

    service.addTutorial("input", "Ana", d, 12, "sjdh");
    service.updateTutorial("input", "Ana", d, 0, "bbb");
    assert(service.getElem(1)->getLink() == "bbb");
    assert(service.getElem(1)->getLikes() == 0);

    assert(service.find("input", "Ana") == 1);
    assert(service.find("a", "b") == -1);

    assert(service.samePresenter("Ana", 1) == 1);
    assert(service.samePresenter("Ana", 0) == 0);
    service.DestroyService();


}

void TestUser()
{
    Repository repository = Repository();
    Playlist playlist = Playlist();

    Service service = Service(repository, playlist);
    Duration d;
    d.set_seconds(12);
    d.set_minutes(13);

    service.addUser("outputing", "Ana", d, 11, "aab");
    service.addUser("output", "Alia", d, 11, "aaa");


    assert(service.getlen() == 2);
    assert(service.getElemm()->getPresenter() == "Ana");
    assert(service.getElemm()->getTitle() == "outputing");
    assert(service.getElemm()->getLink() == "aab");
    assert(service.getElemm()->getLikes() == 11);
    assert(service.getElemm()->getDuration().get_minutes() == 13);
    assert(service.getElemm()->getDuration().get_seconds() == 12);
    service.nextUser();
    assert(service.getElemm()->getPresenter() == "Alia");
    assert(service.getElemm()->getTitle() == "output");
    assert(service.getElemm()->getLink() == "aaa");
    assert(service.getElemm()->getLikes() == 11);
    assert(service.getElemm()->getDuration().get_minutes() == 13);
    assert(service.getElemm()->getDuration().get_seconds() == 12);
    service.nextUser();

    assert(service.findUser("output", "Alia") == 1);
    assert(service.findUser("input", "alia") == -1);

    assert(service.samePresUser("Alia") == 1);
    assert(service.samePresUser("ana") == 0);

    service.like();
    assert(service.getElemm()->getLikes() == 12);

    service.removeUser();
    assert(service.getlen()==1);
}

void Test()
{
    testService();
    TestUser();
}
//