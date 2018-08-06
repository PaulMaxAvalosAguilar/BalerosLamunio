#include "searchervistacontroller.h"
#include <vector>
#include <QDebug>

using namespace std;

SearcherVistaController::SearcherVistaController(SearcherVista *vista):
    DatabaseLogicController(),
    vista(vista)
{

}

void SearcherVistaController::readAndClassify()
{

    unique_ptr<vector<unique_ptr<Codigo>>> listaCodigos = getCodigos();

    unique_ptr<vector<unique_ptr<Coreplusmodifier>>> listacoreplusmodifiers = getCoreplusmodifiers();


    //Iterate through all coreplusmodifiers
    for(uint i = 0; i < listacoreplusmodifiers->size(); i++){

        vector<unique_ptr<int>> listaSubcategoriasdetecatadas;

        QString testString = listacoreplusmodifiers->at(i)->getFullNombre();


        //Evaluate against all codes and detect belonging subcategory
        for(uint i = 0; i < listaCodigos->size(); i ++){

            int evaluationResult;

            QString searchedString =  listaCodigos->at(i)->getCaracteres();

            evaluationResult = testString.indexOf(searchedString,0, Qt::CaseInsensitive);

            if(evaluationResult != -1){
                listaSubcategoriasdetecatadas.push_back(unique_ptr<int>(new int(listaCodigos->at(i)->getSubcategoria_ID())));
            }
        }

        //Add relation of coreplusmodifier to each subcategory
        sort(listaSubcategoriasdetecatadas.begin(), listaSubcategoriasdetecatadas.end());
        listaSubcategoriasdetecatadas.erase(
                    unique(listaSubcategoriasdetecatadas.begin(), listaSubcategoriasdetecatadas.end()));

        for(uint e = 0; e < listaSubcategoriasdetecatadas.size(); e ++){
            addClasificacion(*listaSubcategoriasdetecatadas.at(e), listacoreplusmodifiers->at(i)->getId());
        }
    }
}
