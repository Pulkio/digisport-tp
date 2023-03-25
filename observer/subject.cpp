#include "subject.h"
#include "observer.h"

// Fonction pour notifier tous les observateurs que l'état du sujet a changé
void Subject::notifyObservers() {
    // Parcourt la liste des observateurs enregistrés pour observer le sujet
    for (auto& obs : observers) {
        // Appelle la fonction update() de l'observateur avec le sujet en paramètre
        obs->update(this);
    }
}
