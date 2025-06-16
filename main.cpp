#include "Project/headers/model/StepUp.h"
#include "Project/headers/controllers/Controller.h"
#include "Project/mock/MockData.h"

int main() {
    StepUp store;

    MockData mock;
    mock.generateData(store);  // <- aqui os produtos são adicionados

    Controller controller(store);

    // Adicionar produtos ao cart do pedro@gmail.com
    Product nikeProd = store.findProductById(1);
    Product adidasProd = store.findProductById(2);
    controller.addProductToClientCart("pedro@gmail.com", nikeProd, 1);
    controller.addProductToClientCart("pedro@gmail.com", adidasProd, 1);

    controller.run();

    return 0;
}
