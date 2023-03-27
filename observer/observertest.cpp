//
// Created by Noël Plouzeau on 20/03/2023.
//

#include <gtest/gtest.h>
#include "subjectimpl.h"
#include "observerimpl.h"

// Test 1 : Vérifie que l'on peut ajouter un observateur
TEST(ObserverPatternTest, RegisterObserver) {
	// Création du sujet et de l'observateur
	Subject* subject = new SubjectImpl();
	Observer* obs = new ObserverImpl();

	// Vérification que l'observateur n'est pas encore enregistré
	ASSERT_FALSE(subject->isRegistered(obs));

	// Enregistrement de l'observateur auprès du sujet
	subject->registerObserver(obs);

	// Vérification que l'observateur a été enregistré
	ASSERT_TRUE(subject->isRegistered(obs));

	// Destruction des objets
	delete obs;
	delete subject;
}

// Test 2 : Retirer un observateur d'un sujet
TEST(ObserverPatternTest, UnregisterObserver) {
	// Création du sujet et de l'observateur
	Subject* subject = new SubjectImpl();
	Observer* observer = new ObserverImpl();

	// Enregistrement de l'observateur auprès du sujet
	subject->registerObserver(observer);

	// Retrait de l'observateur
	subject->unregisterObserver(observer);

	// Vérification que l'observateur n'est plus enregistré auprès du sujet
	ASSERT_FALSE(subject->isRegistered(observer));

	// Destruction des objets
	delete observer;
	delete subject;
}

// Test 3 : Test de lecture de la valeur du sujet sans l'initialiser
TEST(ObserverPatternTest, getValueWithoutInitialise) {
	// Création du sujet et de l'observateur
	Subject* subject = new SubjectImpl();

	// Lecture de la valeur du sujet
	std::string value = subject->getValue();

	// Vérification que la valeur lue correspond à la valeur définie dans le constructeur de subject
	ASSERT_EQ(value, "nothing");

	// Destruction des objets
	delete subject;
}

// Test 4 : Test de lecture de la valeur du sujet
TEST(ObserverPatternTest, setValue) {
	// Création du sujet et de l'observateur
	Subject* subject = new SubjectImpl();

	//Donnée une valeur au sujet
	std::string valeur = "Nouvelle valeur";

	// Modification de la valeur du sujet
	subject->setValue(valeur);

	// Lecture de la valeur du sujet
	std::string value = subject->getValue();

	// Vérification que la valeur lue correspond à la valeur définie précédemment
	ASSERT_EQ(value, valeur);

	delete subject;
}

// Test 5 : Essayer d'enregistrer plusieurs observateurs
TEST(ObserverPatternTest, RegisterMultipleObservers) {
	// Création du sujet et des observateurs
	Subject* subject = new SubjectImpl();
	Observer* obs1 = new ObserverImpl();
	Observer* obs2 = new ObserverImpl();
	Observer* obs3 = new ObserverImpl();

	// Enregistrement des observateurs auprès du sujet
	subject->registerObserver(obs1);
	subject->registerObserver(obs2);
	subject->registerObserver(obs3);

	ASSERT_TRUE(subject->isRegistered(obs1));
	ASSERT_TRUE(subject->isRegistered(obs2));
	ASSERT_TRUE(subject->isRegistered(obs3));


	// Destruction des objets
	delete obs1;
	delete obs2;
	delete obs3;
	delete subject;
}

//Test 6 : Regarder si tous les observateurs qui sont enregistrés sur le même sujet lisent la même valeur
TEST(ObserverPatternTest, MultipleObserversSameValue) {
    // Création du sujet et des observateurs
    Subject* subject = new SubjectImpl();
	//Comme type Observer et non ObserverImpl, appel de getObsValue()
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
    ASSERT_EQ(obs1->getObsValue(), sameValue);
    ASSERT_EQ(obs2->getObsValue(), sameValue);
    ASSERT_EQ(obs3->getObsValue(), sameValue);

    // Destruction des objets
    delete obs1;
    delete obs2;
    delete obs3;
    delete subject;
}

// Test 7 : Enregistrer un même observateur sur deux sujets différents
TEST(ObserverPatternTest, oneObserverOnTwoSubjects) {
	// Création des sujets et de l'observateur
	Subject* subject1 = new SubjectImpl();
	Subject* subject2 = new SubjectImpl();
	Observer* obs = new ObserverImpl();

	// Enregistrement de l'observateur sur les deux sujets
	subject1->registerObserver(obs);
	subject2->registerObserver(obs);

	ASSERT_TRUE(subject1->isRegistered(obs));
	ASSERT_TRUE(subject2->isRegistered(obs));

	// Retrait de l'observateur des deux sujets
	subject1->unregisterObserver(obs);
	subject2->unregisterObserver(obs);

	// Destruction des objets
	delete obs;
	delete subject1;
	delete subject2;
}

// Test 8 : Tenter d'enlever 1 observateurs d'un sujet qui n'en a pas.
TEST(ObserverPatternTest, removeObserverNotRegistered) {
	// Création des sujets et de l'observateur
	Subject* subject = new SubjectImpl();
	Observer* obs = new ObserverImpl();

	//Vérifie que l'observer n'est pas enregistré auprès du sujet
	ASSERT_FALSE(subject->isRegistered(obs));

	//Essaye de désinscrire un Observer qui n'est pas enregistré avec ce sujet
	subject->unregisterObserver(obs);

	// Destruction des objets
	delete obs;
	delete subject;
}

// Test 9 : Mettre à jour 2 sujets dont où le même observer est enregistré
TEST(ObserverPatternTest, sameObserverTwoSubjectsWhatValue) {
	// Création des sujets et de l'observateur
	Subject* subject1 = new SubjectImpl();
	Subject* subject2 = new SubjectImpl();
	Observer* obs = new ObserverImpl();

	//Enregistrer les observers
	subject1->registerObserver(obs);
	subject2->registerObserver(obs);

	//Vérifie que l'observer est bien enregistré auprès des 2 sujets
	ASSERT_TRUE(subject1->isRegistered(obs));
	ASSERT_TRUE(subject2->isRegistered(obs));

	std::string value1 = "subject1";
	std::string value2 = "subject2";

	//Mets les valeurs de sujets un à la valeur valeur1
	subject1->setValue(value1);

	ASSERT_EQ(obs->getObsValue(), value1);
	//Mets les valeurs de sujets deux à la valeur valeur1
	subject2->setValue(value2);
	ASSERT_EQ(obs->getObsValue(), value2);

	// Retrait de l'observateur des deux sujets
	subject1->unregisterObserver(obs);
	subject2->unregisterObserver(obs);

	// Destruction des objets
	delete obs;
	delete subject1;
	delete subject2;
}

// Test 10 : Regarder si l'observer continue de recevoir les notification après être désabonné d'un sujet
TEST(ObserverPatternTest, registerUnregisterCheckValue) {
	// Création des sujets et de l'observateur
	Subject* subject = new SubjectImpl();
	Observer* obs = new ObserverImpl();

	//Enregistrer l'observer
	subject->registerObserver(obs);

	//Mettre à jour la valeur du sujet
	std::string value = "newValue";
	subject->setValue(value);

	//Verifier si l'observer a bien été notifié
	ASSERT_EQ(obs->getObsValue(), value);

	//Unregister l'observer
	subject->unregisterObserver(obs);
	
	// Remettre à jour la valeur du sujet
	value = "changement de valeur";
	subject->setValue(value);
	//Vérifier que la valeur du sujet a bien changé
	ASSERT_EQ(subject->getValue(), value);

	//Vérifier que la valeur de l'observer est différente de la valeur du sujet
	ASSERT_NE(obs->getObsValue(), value);
}


// Test 11 : Verifier qu'un observer est à la bonne valeur dès qu'il s'enregistre
TEST(ObserverPatternTest, registerValue) {
	// Création des sujets et de l'observateur
	Subject* subject = new SubjectImpl();
	Observer* obs = new ObserverImpl();

	std::string value = "valeur";
	//changement de la valeur du sujet
	subject->setValue(value);

	//Register l'observer avec le sujet
	subject->registerObserver(obs);

	//Vérifier la valeur de l'observer
	ASSERT_EQ(obs->getObsValue(), value);
}

// Test 12 : Essayer de set un string empty pour subject
TEST(ObserverPatternTest, emptyString) {
	// Création des sujets et de l'observateur
	Subject* subject = new SubjectImpl();
	Observer* obs = new ObserverImpl();

	std::string value = "";
	//changement de la valeur du sujet
	subject->setValue(value);

	//Register l'observer avec le sujet
	subject->registerObserver(obs);

	//Vérifier la valeur de l'observer
	ASSERT_NE(obs->getObsValue(), value);
	ASSERT_EQ(obs->getObsValue(), "nothing");
}








