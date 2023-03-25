#include "observerimpl.h"
#include "subject.h"
#include <iostream>

ObserverImpl::ObserverImpl() {
    // Constructeur par défaut de l'observateur
}

ObserverImpl::~ObserverImpl() {
    // Destructeur de l'observateur
}

// Fonction appelée par le sujet observé pour notifier tous les observateurs de la mise à jour de la valeur
void ObserverImpl::update(Subject* s) {
    // Afficher la nouvelle valeur du sujet observé
    std::cout << "Value changed to: " << s->getValue() << std::endl;
}
