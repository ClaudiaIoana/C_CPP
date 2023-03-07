#include "../Header files/ui.h"
void testsMedicineRepo();

int main()
{
    MedicineRepo * repo = createRepo(10);
    Service* ctrl = createService(repo);
    UI* ui = createUI(ctrl);
    menu(ui);
    testsMedicineRepo();
    destroyUI(ui);
    return 0;
}