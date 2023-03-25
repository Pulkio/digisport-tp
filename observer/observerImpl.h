#ifndef OBSERVERIMPL_H
#define OBSERVERIMPL_H

#include "observer.h"

class Subject;

// Classe ObserverImpl héritant de la classe Observer
class ObserverImpl : public Observer {
public:
    // Constructeur par défaut
    ObserverImpl();

    // Destructeur virtuel pour une destruction appropriée des instances de classes dérivées
    virtual ~ObserverImpl();

    // Fonction virtuelle pour mettre à jour l'état de l'objet observé
    void update(Subject* s) override;
};

#endif /* OBSERVERIMPL_H */
