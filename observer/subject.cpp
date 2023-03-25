#include "subject.h"
#include "observer.h"

// Fonction pour notifier tous les observateurs que l'�tat du sujet a chang�
void Subject::notifyObservers() {
    // Parcourt la liste des observateurs enregistr�s pour observer le sujet
    for (auto& obs : observers) {
        // Appelle la fonction update() de l'observateur avec le sujet en param�tre
        obs->update(this);
    }
}
