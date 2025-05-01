#include "Project/headers/model/StepUp.h"
#include "Project/headers/controllers/Controller.h"

int main() {
    StepUp store;
    Controller controller(store);
    controller.run();

    return 0;
}
