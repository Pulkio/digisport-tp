#ifndef OBSERVER_H
#define OBSERVER_H

// D�claration anticip�e de la classe Subject pour �viter une d�pendance cyclique
class Subject;

// Classe abstraite repr�sentant un observateur
class Observer {
public:
    // Destructeur virtuel
    virtual ~Observer() {}

    // Fonction virtuelle pure pour mettre � jour l'�tat de l'observateur en fonction du sujet
    virtual void update(Subject* s) = 0;
};

#endif /* OBSERVER_H */
