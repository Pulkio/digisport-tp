#ifndef SUBJECTIMPL_H
#define SUBJECTIMPL_H

#include <string>
#include <list>
#include "subject.h"

// D�claration anticip�e de la classe Observer pour �viter une d�pendance cyclique
class Observer;

// Classe d'impl�mentation d'un sujet
class SubjectImpl : public Subject {
public:
    // Constructeur par d�faut
    SubjectImpl();

    // Destructeur virtuel pour permettre la destruction polymorphique
    virtual ~SubjectImpl();

    // Fonction pour obtenir la valeur actuelle du sujet
    std::string getValue() const override;

    // Fonction pour d�finir la valeur du sujet et notifier les observateurs si elle change
    void setValue(std::string value) override;

    // Fonction pour v�rifier si un observateur est d�j� enregistr�
    bool isRegistered(const Observer* o) const override;

    // Fonction pour enregistrer un observateur
    void registerObserver(Observer* o) override;

    // Fonction pour d�senregistrer un observateur
    void unregisterObserver(Observer* o) override;

    // Fonction pour notifier tous les observateurs enregistr�s d'un changement de sujet
    void notifyObservers() override;

private:
    std::string value;              // Valeur actuelle du sujet
    std::list<Observer*> observers; // Liste des observateurs enregistr�s
};

#endif /* SUBJECTIMPL_H */
