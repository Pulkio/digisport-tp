#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <list>

// D�claration anticip�e de la classe Observer pour �viter une d�pendance cyclique
class Observer;

// Classe abstraite Subject
class Subject {
public:
    // Destructeur virtuel
    virtual ~Subject() {}

    // Fonction virtuelle pure pour obtenir la valeur du sujet
    virtual std::string getValue() const = 0;

    // Fonction virtuelle pure pour d�finir la valeur du sujet
    virtual void setValue(std::string value) = 0;

    // Fonction virtuelle pure pour d�terminer si un observateur est enregistr� pour observer le sujet
    virtual bool isRegistered(const Observer* o) const = 0;

    // Fonction virtuelle pure pour enregistrer un observateur pour observer le sujet
    virtual void registerObserver(Observer* o) = 0;

    // Fonction virtuelle pure pour d�senregistrer un observateur qui observe le sujet
    virtual void unregisterObserver(Observer* o) = 0;

    // Fonction virtuelle pure pour notifier tous les observateurs enregistr�s que l'�tat du sujet a chang�
    virtual void notifyObservers() = 0;

};

#endif /* SUBJECT_H */
