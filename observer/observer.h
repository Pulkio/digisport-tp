#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

// Déclaration anticipée de la classe Subject pour éviter une dépendance cyclique
class Subject;

// Classe abstraite représentant un observateur
class Observer {
public:
    // Destructeur virtuel
    virtual ~Observer() {}

    // Fonction virtuelle pure pour mettre à jour l'état de l'observateur en fonction du sujet
    virtual void update(Subject* s) = 0;

    // Fonction virtuelle pure qui permet de récupérer la valeur stockée dans l'observer.
    virtual std::string getObsValue() = 0;
};

#endif /* OBSERVER_H */
