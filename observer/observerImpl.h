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

    // Fonction pour mettre à jour l'état de l'objet observé
    void update(Subject* s) override;

    // Fonction qui permet de récupérer la valeur stockée dans l'observer.
    std::string getObsValue() override;

private:
    std::string obsValue;
};

#endif /* OBSERVERIMPL_H */
