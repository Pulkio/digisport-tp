//
// Created by Noël Plouzeau on 20/03/2023.
//

#include <gtest/gtest.h>
#include "subjectimpl.h"
#include "observerimpl.h"

// Test 1 : Vérifie que l'on peut ajouter un observateur
TEST(ObserverPatternTest, Test1) {
	// Création du sujet et de l'observateur
	Subject* subject = new SubjectImpl();
	Observer* obs = new ObserverImpl();

	// Vérification que l'observateur n'est pas encore enregistré
	ASSERT_FALSE(subject->hasObserver(obs));

	// Enregistrement de l'observateur auprès du sujet
	subject->registerObserver(obs);

	// Vérification que l'observateur a été enregistré
	ASSERT_TRUE(subject->hasObserver(obs));

	// Destruction des objets
	delete obs;
	delete subject;
}

// Test 2 : Retirer un observateur d'un sujet
TEST(ObserverPatternTest, Test2) {
	// Création du sujet et de l'observateur
	Subject* subject = new SubjectImpl();
	Observer* observer = new ObserverImpl();

	// Enregistrement de l'observateur auprès du sujet
	subject->registerObserver(observer);

	// Retrait de l'observateur
	subject->unregisterObserver(observer);

	// Vérification que l'observateur n'est plus enregistré auprès du sujet
	ASSERT_FALSE(subject->hasObserver(observer));

	// Destruction des objets
	delete observer;
	delete subject;
}

// Test 3 : Test de lecture de la valeur du sujet sans l'initialiser
TEST(ObserverPatternTest, Test3) {
	// Création du sujet et de l'observateur
	Subject* subject = new SubjectImpl();
	Observer* obs = new ObserverImpl();

	// Enregistrement de l'observateur auprès du sujet
	subject->registerObserver(obs);

	// Lecture de la valeur du sujet
	std::string value = subject->getValue();

	// Vérification que la valeur lue correspond à la valeur définie précédemment
	ASSERT_EQ(value, "nothing");

	// Retrait de l'observateur
	subject->unregisterObserver(obs);

	// Destruction des objets
	delete obs;
	delete subject;
}

// Test 4 : Test de lecture de la valeur du sujet
TEST(ObserverPatternTest, Test4) {
	// Création du sujet et de l'observateur
	Subject* subject = new SubjectImpl();
	Observer* obs = new ObserverImpl();

	std::string valeur = "Nouvelle valeur";
	// Enregistrement de l'observateur auprès du sujet
	subject->registerObserver(obs);

	// Modification de la valeur du sujet
	subject->setValue(valeur);

	// Lecture de la valeur du sujet
	std::string value = subject->getValue();

	// Vérification que la valeur lue correspond à la valeur définie précédemment
	ASSERT_EQ(value, valeur);

	// Retrait de l'observateur
	subject->unregisterObserver(obs);

	// Destruction des objets
	delete obs;
	delete subject;
}

// Test 5 : Essayer d'enregistrer plusieurs observateurs
TEST(ObserverPatternTest, Test5) {
	// Création du sujet et des observateurs
	Subject* subject = new SubjectImpl();
	Observer* obs1 = new ObserverImpl();
	Observer* obs2 = new ObserverImpl();
	Observer* obs3 = new ObserverImpl();

	// Enregistrement des observateurs auprès du sujet
	subject->registerObserver(obs1);
	subject->registerObserver(obs2);
	subject->registerObserver(obs3);

	ASSERT_TRUE(subject->hasObserver(obs1));
	ASSERT_TRUE(subject->hasObserver(obs2));
	ASSERT_TRUE(subject->hasObserver(obs3));


	// Destruction des objets
	delete obs1;
	delete obs2;
	delete obs3;
	delete subject;
}

//Test 6 : Regarder si tous les observateurs qui sont enregistrés sur le même sujet lisent la même valeur
TEST(ObserverPatternTest, Test6) {
    // Création du sujet et des observateurs
    Subject* subject = new SubjectImpl();
    Observer* obs1 = new ObserverImpl();
    Observer* obs2 = new ObserverImpl();
    Observer* obs3 = new ObserverImpl();

    // Enregistrement des observateurs auprès du sujet
    subject->registerObserver(obs1);
    subject->registerObserver(obs2);
    subject->registerObserver(obs3);

	const std::string sameValue = "sameValue";
    // Modification de la valeur du sujet
    subject->setValue(sameValue);

    // Vérification que tous les observateurs ont été notifiés
    ASSERT_EQ(obs1->getValue(), sameValue);
    ASSERT_EQ(obs2->getValue(), sameValue);
    ASSERT_EQ(obs3->getValue(), sameValue);

    // Destruction des objets
    delete obs1;
    delete obs2;
    delete obs3;
    delete subject;
}

// Test 7 : Enregistrer un même observateur sur deux sujets différents
TEST(ObserverPatternTest, Test7) {
	// Création des sujets et de l'observateur
	Subject* subject1 = new SubjectImpl();
	Subject* subject2 = new SubjectImpl();
	Observer* obs = new ObserverImpl();

	// Enregistrement de l'observateur sur les deux sujets
	subject1->registerObserver(obs);
	subject2->registerObserver(obs);

	ASSERT_TRUE(subject1->hasObserver(obs));
	ASSERT_TRUE(subject2->hasObserver(obs));

	// Retrait de l'observateur des deux sujets
	subject1->unregisterObserver(obs);
	subject2->unregisterObserver(obs);

	// Destruction des objets
	delete obs;
	delete subject1;
	delete subject2;
}

// Test 8 : Tenter d'enlever 1 observateurs d'un sujet qui n'en a pas.
TEST(ObserverPatternTest, Test8) {
	// Création des sujets et de l'observateur
	Subject* subject = new SubjectImpl();
	Observer* obs = new ObserverImpl();

	//Vérifie que l'observer n'est pas enregistré auprès du sujet
	ASSERT_FALSE(subject->hasObserver(obs));

	//Essaye de désinscrire un Observer qui n'est pas enregistré avec ce sujet
	subject->unregisterObserver(obs);

	// Retrait de l'observateur des deux sujets
	subject1->unregisterObserver(obs);
	subject2->unregisterObserver(obs);

	// Destruction des objets
	delete obs;
	delete subject1;
	delete subject2;
}











