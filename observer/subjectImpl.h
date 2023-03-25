#ifndef SUBJECTIMPL_H
#define SUBJECTIMPL_H

#include <string>
#include <list>
#include "subject.h"

// Déclaration anticipée de la classe Observer pour éviter une dépendance cyclique
class Observer;

// Classe d'implémentation d'un sujet
class SubjectImpl : public Subject {
public:
    // Constructeur par défaut
    SubjectImpl();

    // Destructeur virtuel pour permettre la destruction polymorphique
    virtual ~SubjectImpl();

    // Fonction pour obtenir la valeur actuelle du sujet
    std::string getValue() const override;

    // Fonction pour définir la valeur du sujet et notifier les observateurs si elle change
    void setValue(std::string value) override;

    // Fonction pour vérifier si un observateur est déjà enregistré
    bool isRegistered(const Observer* o) const override;

    // Fonction pour enregistrer un observateur
    void registerObserver(Observer* o) override;

    // Fonction pour désenregistrer un observateur
    void unregisterObserver(Observer* o) override;

    // Fonction pour notifier tous les observateurs enregistrés d'un changement de sujet
    void notifyObservers() override;

private:
    std::string value;              // Valeur actuelle du sujet
    std::list<Observer*> observers; // Liste des observateurs enregistrés
};

#endif /* SUBJECTIMPL_H */
