#include "observerimpl.h"
#include "subject.h"
#include <iostream>

ObserverImpl::ObserverImpl() {
    // Constructeur par d�faut de l'observateur
}

ObserverImpl::~ObserverImpl() {
    // Destructeur de l'observateur
}

// Fonction appel�e par le sujet observ� pour notifier tous les observateurs de la mise � jour de la valeur
void ObserverImpl::update(Subject* s) {
    // Afficher la nouvelle valeur du sujet observ�
    std::cout << "Value changed to: " << s->getValue() << std::endl;
}
