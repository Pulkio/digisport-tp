#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <list>

// Déclaration anticipée de la classe Observer pour éviter une dépendance cyclique
class Observer;

// Classe abstraite Subject
class Subject {
public:
    // Destructeur virtuel
    virtual ~Subject() {}

    // Fonction virtuelle pure pour obtenir la valeur du sujet
    virtual std::string getValue() const = 0;

    // Fonction virtuelle pure pour définir la valeur du sujet
    virtual void setValue(std::string value) = 0;

    // Fonction virtuelle pure pour déterminer si un observateur est enregistré pour observer le sujet
    virtual bool isRegistered(const Observer* o) const = 0;

    // Fonction virtuelle pure pour enregistrer un observateur pour observer le sujet
    virtual void registerObserver(Observer* o) = 0;

    // Fonction virtuelle pure pour désenregistrer un observateur qui observe le sujet
    virtual void unregisterObserver(Observer* o) = 0;

    // Fonction virtuelle pure pour notifier tous les observateurs enregistrés que l'état du sujet a changé
    virtual void notifyObservers() = 0;

};

#endif /* SUBJECT_H */
