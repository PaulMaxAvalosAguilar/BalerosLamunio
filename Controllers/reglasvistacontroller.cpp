#include "reglasvistacontroller.h"

ReglasVistaController::ReglasVistaController():
    DatabaseLogicController()
{

}

void ReglasVistaController::configureVista(ReglasVista *vista)
{
    this->vista = vista;
}
