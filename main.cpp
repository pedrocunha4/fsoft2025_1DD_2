#include "Project/headers/model/StepUp.h"
#include "Project/headers/controllers/Controller.h"
#include "Project/mock/MockData.h"

int main() {
    StepUp store;

    MockData mock;
    mock.generateData(store);  // <- aqui os produtos são adicionados

    Controller controller(store);
    controller.run();

    return 0;
}
