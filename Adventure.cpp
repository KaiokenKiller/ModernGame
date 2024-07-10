//
// Created by aj on 15.05.24.
//

#include "Adventure.h"

Adventure::Adventure(){
	std::string name;
	fmt::print("Nenne deinen Namen Held: ");
	std::cin >> name;
	fmt::print("Und so beginnt das Abenteuer von {}\n",name);
	std::cin.get();
	std::cin.get();

	m_player = std::make_shared<Player>(name);
	start();
	//test();
}

Adventure::~Adventure() = default;

void Adventure::test() {

	/*
	// test armor and equippedArmor
    std::shared_ptr<Item> testArmor = std::make_shared<Armor>(1,"BasicHelm",1,"helmet",3);
    testArmor->info();

	m_player->addItem(testArmor);
	m_player->equipArmor(testArmor);
	*/

	/*
	// test show functions
	m_player->info();

	m_player->showInventory();
	*/

	/*
	// test if Battle works as expected
	std::shared_ptr<Enemy> dummy1 = std::make_shared<Enemy>("Napstablock",35,2,2);
	std::shared_ptr<Enemy> dummy2 = std::make_shared<Enemy>("Mad dummy",55,0,20);

	auto temp = std::vector<std::shared_ptr<Enemy>>();
	temp.emplace_back(dummy1);
	temp.emplace_back(dummy2);

	Battle(m_player,temp);
	*/

	StarterArea grasslands("Grassland");
	Battle temp(m_player,grasslands.generateEnemies());
}

void Adventure::start() {

	std::vector<std::string> textVec;

	textVec.push_back(fmt::format("Kapitel I:\n"));
	textVec.push_back(fmt::format("Du wachst in der Scheune eines kleinen Dorfes auf."));
	textVec.push_back(fmt::format("Ein besorgter Dorfbewohner erzählt dir dass in letzter Zeit viele Monster im angrenzenden Grassland aufgetaucht sind."));
	textVec.push_back(fmt::format("Er vermutet dass die Monster aus einer nahegelegenen Höhle kommen, welche hinter dem Grassland liegt und bittet dich diese zu untersuchen."));
	displayText(textVec);
	fmt::print("Wirst du dem Dorfbewohner helfen?\n1.Ja\n2.Nein\n");

	std::string choice;
	while (choice != "1" && choice != "2"){
		std::cin >> choice;
	}
	if(choice == "1"){
		textVec.push_back(fmt::format("Auf dem Weg zur Dorfgrenze läuft dir ein kleines Mädchen über den Weg."));
		textVec.push_back(fmt::format("\"Mein Herr das Grassland ist zu gefährlich um zur Höhle zu kommen."));
		textVec.push_back(fmt::format("Nehmt lieber den Pfad durch den Wald dort habe ich noch nie Monster gesehen.\""));
		displayText(textVec);

		fmt::print("Welchen Weg wählst du?\n1.Das Grassland ist offener dort weiß ich genau was mich erwartet.\n2.Ein sicherer Weg durch den Wald hört sich verlockend an.\n");

		while (choice != "1" && choice != "2"){
			std::cin >> choice;
		}
		if (choice == "1"){
			textVec.push_back(fmt::format("Auf dem Weg durchs Grassland musst du dich durch hohe Gräser schlagen"));
			textVec.push_back(fmt::format("Du hörts ein rascheln aus dem Gras und eine Gruppe Monster springt herraus"));
			displayText(textVec);

			StarterArea grassland("Grassland",2,3);
			Battle battle1(m_player,grassland.generateEnemies());
			if (!m_player->isAlive())
				return;

			textVec.push_back(fmt::format("Nachdem du die Monster mit äußerster Leichtigkeit besiegen konntest gönnst du dir eine Verschnaufspause"));
			textVec.push_back(fmt::format("Leider waren das nicht die einzigen Monster auf dem Weg."));
			textVec.push_back(fmt::format("Du siehst eine weitere Gruppe und sprintest ins Gefecht"));
			displayText(textVec);

			Battle battle2(m_player,grassland.generateEnemies());
			if (!m_player->isAlive())
				return;
			textVec.push_back(fmt::format("Ein Stückchen weiter vorne im Weg erspähst du bereits den Eingang der Höhle."));
		}
		else if (choice == "2"){
			textVec.push_back(fmt::format("Während du durch den Wald stapfst fühlst du dich beobachtet."));
			textVec.push_back(fmt::format("Abgelegen vom Weg erspähst du ein erloschenes Lagerfeuer."));
			textVec.push_back(fmt::format("Noch bevor du deine Schlüsse daraus ziehen kannst greift dich eine Gruppe Banditen an, welche sich zuvor versteckt hatte."));
			displayText(textVec);

			BanditArea banditBattle ("Wald vor dem Dorf",3,5);
			if (!m_player->isAlive())
				return;

			textVec.push_back(fmt::format("Jetzt weißt du warum keine Mopnster im Wald zu finden waren."));
			textVec.push_back(fmt::format("Du folgst dem Pfad weiter und kommst Nahe des Höhleneingangs raus"));
		}
		textVec.push_back(fmt::format("Die Höhle "));
	}
	else if (choice == "2"){
		textVec.push_back(fmt::format("Du vermeidest dich in diese Angelegenheiten einzumischen, du kennst die Leute hier ja nicht mal."));
		textVec.push_back(fmt::format("Den nächsten Monat verbringst du damit dich mit dem Dorf vertraut zu machen."));
		textVec.push_back(fmt::format("Bob, der Bauern in dessen Scheune du aus irgendwelchen Gründen aufgewacht bist, hat dir einen Job auf seinen Feldern angeboten und dich mit der nötigen Kleidung und Equipment versorgt"));
		textVec.push_back(fmt::format("Eines Nachts weckt dich ein lauter Schrei aus dem schlaf."));
		textVec.push_back(fmt::format("Du stürmst aus der Scheune und siehst dass das Dorf von den umliegenden Monstern angegriffen wird."));
		textVec.push_back(fmt::format("Einen Blick später entdeckst du dass Bob von den Monster stark verwundet wurde."));
		textVec.push_back(fmt::format("Es sind zu viele Monster um zu fliehen dir bleibt nur noch ein Möglichkeit."));
		textVec.push_back(fmt::format("EIN KAMPF UM LEBEN UND TOT!"));
		displayText(textVec);

		StarterArea burningVillage("Brennendes Dorf",5,8);
		Battle burningVillageBattle(m_player,burningVillage.generateEnemies());
		if (!m_player->isAlive())
			return;
	}

}

void Adventure::displayText(std::vector<std::string>& text) {
	for (const auto& element:text){
		fmt::print(element);
		std::cin.get();
	}
	text.clear();
}
