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

    // Fonction virtuelle pour mettre � jour l'�tat de l'objet observ�
    void update(Subject* s) override;
};

#endif /* OBSERVERIMPL_H */
