cmake_minimum_required(VERSION 3.10)
project(fsoft2025_1DD_2)

set(CMAKE_CXX_STANDARD 20)

# Diretórios de headers
include_directories(
        Project/headers
        Project/headers/controllers
        Project/headers/views
        Project/headers/model
        Project/headers/exceptions
)

# Ficheiros fonte
add_executable(fsoft2025_1DD_2
        main.cpp

        # Controller
        Project/sources/controllers/Controller.cpp

        # View
        Project/sources/views/View.cpp

        # Model
        Project/sources/model/StepUp.cpp
        Project/sources/model/Product.cpp
        Project/sources/model/Client.cpp
        Project/sources/model/Manager.cpp
        Project/sources/model/Supplier.cpp
        Project/sources/model/ClientOrder.cpp
        Project/sources/model/SupplierOrder.cpp

        # Mock
        Project/mock/MockData.cpp
        Project/headers/views/Utils.h
        Project/sources/views/Utils.cpp
        Project/headers/model/Cart.h
        Project/sources/model/Cart.cpp
)

# -------------------
# TESTES UNITÁRIOS
# -------------------

# Adicionar GoogleTest
add_subdirectory(ProjectTester/googleTestLib/googletest)

# Incluir headers do GTest
include_directories(ProjectTester/googleTestLib/googletest/googletest/include)

# Criar target de testes
add_executable(run_tests
        ProjectTester/main.cpp
        ProjectTester/ProductTest.cpp
        ProjectTester/CartTest.cpp
        ProjectTester/ClientTest.cpp
        ProjectTester/ClientOrderTest.cpp
        ProjectTester/ManagerTest.cpp
        ProjectTester/SupplierTest.cpp
        ProjectTester/SupplierOrderTest.cpp
        ProjectTester/StepUpTest.cpp
        Project/sources/model/Product.cpp
        Project/sources/model/Cart.cpp
        Project/sources/model/Client.cpp
        Project/sources/model/ClientOrder.cpp
        Project/sources/model/Manager.cpp
        Project/sources/model/Supplier.cpp
        Project/sources/model/SupplierOrder.cpp
        Project/sources/model/StepUp.cpp
)


# Ligar bibliotecas do GoogleTest
target_link_libraries(run_tests gtest gtest_main)