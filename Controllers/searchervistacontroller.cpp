#include "searchervistacontroller.h"
#include "Vistas/searchervista.h"
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

    if(listacoreplusmodifiers->empty())
        return;

    //Iterate through all coreplusmodifiers
    for(uint i = 0; i < listacoreplusmodifiers->size(); i++){

        vector<unique_ptr<int>> listaSubcategoriasdetecatadas;

        QString testString = listacoreplusmodifiers->at(i)->getFullNombre();




        if(listaCodigos->empty())
            return;

        //Evaluate against all codes and detect belonging subcategory
        for(uint i = 0; i < listaCodigos->size(); i ++){

            int evaluationResult;

            QString searchedString =  listaCodigos->at(i)->getCaracteres();

            evaluationResult = testString.indexOf(searchedString,0, Qt::CaseInsensitive);

            if(evaluationResult != -1){
                listaSubcategoriasdetecatadas.push_back(unique_ptr<int>(new int(listaCodigos->at(i)->getSubcategoria_ID())));
            }
        }




        if(listaSubcategoriasdetecatadas.empty())
            return;

        //Add relation of coreplusmodifier to each subcategory
        sort(listaSubcategoriasdetecatadas.begin(), listaSubcategoriasdetecatadas.end());
        listaSubcategoriasdetecatadas.erase(
                    unique(listaSubcategoriasdetecatadas.begin(), listaSubcategoriasdetecatadas.end()));

        for(uint e = 0; e < listaSubcategoriasdetecatadas.size(); e ++){
            addClasificacion(*listaSubcategoriasdetecatadas.at(e), listacoreplusmodifiers->at(i)->getId());
        }
    }
}

void SearcherVistaController::searchSimilar(QString cadena)
{

    QString testString = cadena;

    if(testString.isEmpty()){
        return;
    }

    unique_ptr<vector<unique_ptr<Codigo>>> listaCodigos = getCodigos();
    vector<unique_ptr<int>> listaSubcategoriasdetecatadas;

    if(listaCodigos->empty())
        return;

    //Evaluate against all codes and detect belonging subcategory
    for(uint i = 0; i < listaCodigos->size(); i ++){

        int evaluationResult;

        QString searchedString =  listaCodigos->at(i)->getCaracteres();

        evaluationResult = testString.indexOf(searchedString,0, Qt::CaseInsensitive);

        if(evaluationResult != -1){
            listaSubcategoriasdetecatadas.push_back(unique_ptr<int>(new int(listaCodigos->at(i)->getSubcategoria_ID())));
        }
    }


    if(listaSubcategoriasdetecatadas.empty())
        return;

    //Search for all coreplusmodifiers with same category
    sort(listaSubcategoriasdetecatadas.begin(), listaSubcategoriasdetecatadas.end());
    listaSubcategoriasdetecatadas.erase(
                unique(listaSubcategoriasdetecatadas.begin(), listaSubcategoriasdetecatadas.end()));

    for(uint e = 0; e < listaSubcategoriasdetecatadas.size(); e ++){
        unique_ptr<vector<unique_ptr<Clasificacion>>> listaClasificaciones =
                 getAllClasificacionesBySubcategoriaId(*listaSubcategoriasdetecatadas.at(e));

        if(listaClasificaciones->empty())
            return;

        for(uint i = 0; i < listaClasificaciones->size(); i ++){
            unique_ptr<vector<unique_ptr<Coreplusmodifier>>> coreplusmodifier =
                    getCoreplusmodifier(listaClasificaciones->at(i)->getCoreplusmodifier_ID());

            if(!coreplusmodifier->empty()){
                vista->clearTextBrowser();
                vista->appendToTextBrowser(coreplusmodifier->at(0)->getFullNombre());
            }
        }
    }
}
