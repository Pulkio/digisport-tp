#include "subjectimpl.h"
#include "observer.h"

// Constructeur par défaut
SubjectImpl::SubjectImpl() {
    this->value = "nothing";
}

// Destructeur
SubjectImpl::~SubjectImpl() {}

// Renvoie la valeur courante
std::string SubjectImpl::getValue() const {
    return this->value;
}

// Définit la valeur courante et notifie les observateurs
void SubjectImpl::setValue(std::string value) {
    if (!value.empty()) {
        this->value = value;
        notifyObservers();
    }
}

// Vérifie si l'observateur est déjà enregistré auprès du sujet
bool SubjectImpl::isRegistered(const Observer* o) const {
    for (const auto& obs : observers) {
        if (obs == o) {
            return true;
        }
    }
    return false;
}

// Enregistre un nouvel observateur auprès du sujet
void SubjectImpl::registerObserver(Observer* o) {
    if (!isRegistered(o)) {
        observers.push_back(o);
        o->update(this);
    }
}

// Désenregistre un observateur du sujet
void SubjectImpl::unregisterObserver(Observer* o) {
    if (isRegistered(o)) {
        observers.remove(o);
    }
}

// Notifie tous les observateurs du changement de valeur
void SubjectImpl::notifyObservers() {
    for (auto& obs : observers) {
        obs->update(this);
    }
}
