#ifndef OBSERVERIMPL_H
#define OBSERVERIMPL_H

#include "observer.h"

class Subject;

// Classe ObserverImpl h�ritant de la classe Observer
class ObserverImpl : public Observer {
public:
    // Constructeur par d�faut
    ObserverImpl();

    // Destructeur virtuel pour une destruction appropri�e des instances de classes d�riv�es
    virtual ~ObserverImpl();

    // Fonction pour mettre � jour l'�tat de l'objet observ�
    void update(Subject* s) override;

    // Fonction qui permet de r�cup�rer la valeur stock�e dans l'observer.
    std::string getObsValue() override;

private:
    std::string obsValue;
};

#endif /* OBSERVERIMPL_H */
