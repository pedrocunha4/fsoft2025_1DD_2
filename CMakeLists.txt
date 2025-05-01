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
)
