//
// Created by aj on 15.05.24.
//

#include "Adventure.h"
#include "Misc/Battle.h"
#include "Areas/StarterArea.h"
#include "Areas/BanditArea.h"
#include "Areas/CaveArea.h"
#include "Bosses/CaveTroll.h"
#include "Bosses/Necromancer.h"


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

	m_player->addItem(1);
	m_player->addItem(5);

	StarterArea grasslands("Grasland");
	Battle temp(m_player,grasslands.generateEnemies());
}

void Adventure::start() {

	std::vector<std::string> textVec;

	textVec.push_back(fmt::format("Kapitel I:\n"));
	textVec.push_back(fmt::format("Du wachst in der Scheune eines kleinen Dorfes auf."));
	textVec.push_back(fmt::format("Ein besorgter Dorfbewohner erzählt dir dass in letzter Zeit viele Monster im angrenzenden Grasland aufgetaucht sind."));
	textVec.push_back(fmt::format("Er vermutet dass die Monster aus einer nahegelegenen Höhle kommen, welche hinter dem Grasland liegt und bittet dich diese zu untersuchen."));
	displayText(textVec);
	fmt::print("Wirst du dem Dorfbewohner helfen?\n1.Ja\n2.Nein\n");

	std::string choice;
	while (choice != "1" && choice != "2"){
		std::cin >> choice;
	}
	if(choice == "1"){
		textVec.push_back(fmt::format("Auf dem Weg zur Dorfgrenze läuft dir ein kleines Mädchen über den Weg."));
		textVec.push_back(fmt::format("\"Mein Herr ihr dürft nicht durch das Grasland, es ist viel zu gefährlich."));
		textVec.push_back(fmt::format("Nehmt lieber den Pfad durch den Wald dort habe ich noch nie ein Monster gesehen.\""));
		displayText(textVec);

		fmt::print("Welchen Weg wählst du?\n1.Das Grasland ist offener dort weiß ich genau was mich erwartet.\n2.Ein sicherer Weg durch den Wald hört sich verlockend an.\n");

		choice.clear();
		while (choice != "1" && choice != "2"){
			std::cin >> choice;
		}
		if (choice == "1"){
			textVec.push_back(fmt::format("Auf dem Weg durchs Grasland musst du dich durch hohe Gräser schlagen"));
			textVec.push_back(fmt::format("Du hörst ein rascheln aus dem Gras und eine Gruppe Monster springt herraus"));
			displayText(textVec);

			StarterArea grassland("Grasland",2,3);
			Battle battle1(m_player,grassland.generateEnemies());
			if (!m_player->isAlive())
				return;

			textVec.push_back(fmt::format("Nachdem du die Monster mit äußerster Leichtigkeit besiegen konntest gönnst du dir eine Verschnaufspause."));
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

			BanditArea banditArea ("Wald vor dem Dorf",3,4);
			Battle banditBattle(m_player,banditArea.generateEnemies());
			if (!m_player->isAlive())
				return;

			textVec.push_back(fmt::format("Jetzt weißt du warum keine Mopnster im Wald zu finden waren."));
			textVec.push_back(fmt::format("Du folgst dem Pfad weiter und kommst Nahe des Höhleneingangs raus"));
		}
	}
	else if (choice == "2"){
		textVec.push_back(fmt::format("Du vermeidest dich in diese Angelegenheiten einzumischen, du kennst die Leute hier ja nicht mal."));
		textVec.push_back(fmt::format("Den nächsten Monat verbringst du damit dich mit dem Dorf vertraut zu machen."));
		textVec.push_back(fmt::format("Geralt, der Bauern in dessen Scheune du aus irgendwelchen Gründen aufgewacht bist, hat dir einen Job auf seinen Feldern angeboten und dich mit der nötigen Kleidung und Equipment versorgt"));
		textVec.push_back(fmt::format("Eines Nachts weckt dich ein lauter Schrei aus dem schlaf."));
		textVec.push_back(fmt::format("Du stürmst aus der Scheune und siehst dass das Dorf brennt."));
		textVec.push_back(fmt::format("Die Monster haben es wohl in der Nacht angegriffen."));
		textVec.push_back(fmt::format("Einen Blick später entdeckst du dass Geralt von den Monster stark verwundet wurde."));
		textVec.push_back(fmt::format("Es sind zu viele Monster um zu fliehen dir bleibt nur noch ein Möglichkeit."));
		textVec.push_back(fmt::format("EIN KAMPF UM LEBEN UND TOT!"));
		displayText(textVec);

		m_player->addItem(7);
		m_player->addItem(8);
		m_player->addItem(9);
		m_player->addItem(10);
		m_player->addItem(11);
		StarterArea burningVillage("Brennendes Dorf",5,8);
		Battle burningVillageBattle(m_player,burningVillage.generateEnemies());
		if (!m_player->isAlive())
			return;

		textVec.push_back(fmt::format("Du konntest mit Mühe und Not die Monster in die Flucht schlagen, doch der Schaden ist immens."));
		textVec.push_back(fmt::format("Nicht in der Lage diese Situation zu ignorieren machst du dich doch auf den Weg zu der besagten Höhle."));
		textVec.push_back(fmt::format("Von den Monstern war auf dem Weg keine Spur mehr."));
		textVec.push_back(fmt::format("Letzendlich kommst du an der Höhle an."));
	}
	textVec.push_back(fmt::format("Die Gänge der Höhle sind schmal und die Dunkelheit macht es schwer zu sehen was vor dir liegt."));
	textVec.push_back(fmt::format("Durch die fehlende Sicht verschärft sich dein Gehör , welches nahe Geräuche wahrnimmt."));
	textVec.push_back(fmt::format("Du bereitest dich auf das schlimmste vor und machst dich kampfbereit."));
	displayText(textVec);

	CaveArea caveArea("Höhle",2,4);
	Battle caveBattle1(m_player,caveArea.generateEnemies());
	if (!m_player->isAlive())
		return;

	textVec.push_back(fmt::format("Nach dem anstrengenden Kampf kommst in einem größeren Raum der Höhle an."));
	textVec.push_back(fmt::format("Du bemerkst schnell dass du auch hier nicht alleine bist."));
	textVec.push_back(fmt::format("Eine weitere Gruppe Monster hat dich bereits umzingelt."));
	displayText(textVec);

	Battle caveBattle2(m_player,caveArea.generateEnemies());
	if (!m_player->isAlive())
		return;

	textVec.push_back(fmt::format("Du bemerkst dass sich der Tunnel hier in 2 weitere Spaltet"));
	textVec.push_back(fmt::format("Einer der beiden Tunnel kommt dir größer vor, als hätte sich etwas großes durch ihn hindurch gezwängt"));
	textVec.push_back(fmt::format("Der andere Tunnel hingegen sieht so aus wie der aus dem du gekommen bist, jedoch durchdringt dich ein mulmiges Gefühl wenn du länger hineinstarrst."));
	textVec.push_back(fmt::format("Welchen Tunnel möchtest du betreten?\n1. Den großen Tunnel\n2. Den \"normalen\" Tunnel\n"));
	displayText(textVec);

	choice.clear();
	while (choice != "1" && choice != "2"){
		std::cin >> choice;
	}
	if (choice == "1"){
		textVec.push_back(fmt::format("Du entscheidest dich für den großen Tunnel, immerhin lässt er sich einfacher durchqueren."));
		textVec.push_back(fmt::format("Der Tunnel führt in eine große stinkende Kammer."));
		textVec.push_back(fmt::format("Beim voranschreiten zerbricht etwas unter deinen Füßen."));
		textVec.push_back(fmt::format("Es war ein Schädel dessen Skelett du nicht weit von dir erblickst."));
		textVec.push_back(fmt::format("Beim genaueren hinsehen bemerkst du, dass es sich nicht nur um ein Skelett sondern um viele handelt, welche rampunierte Ausrüstung von Abenteurern bei sich tragen."));
		textVec.push_back(fmt::format("Du kriegst ein ungutes Gefühl und hörst wie sich etwas großes in deine Richtung bewegt."));
		textVec.push_back(fmt::format("Zum fliehen bleibt dir wohl keine Zeit mehr also bereitest du dich auf einen Kampf vor."));

		auto caveTroll = CaveTroll::generateEnemies();
		Battle caveTrollBattle(m_player,caveTroll);
		if (!m_player->isAlive())
			return;

		textVec.push_back(fmt::format("Nachdem du gerade so mit deinem Leben davongekommen bist merkst du, dass du dich in einer Sackgasse befindest und kehrst wieder um."));
	}
	textVec.push_back(fmt::format("Beim durchqueren des Tunnels ergreift dich immer mehr das Gefühl dass hier irgendwas nicht stimmt, als würde eine erdrückende Aura dir das atmen erschweren."));
	textVec.push_back(fmt::format("Ein paar Schritte weiter bemerkst du ein violettes Leuchten vor dir."));
	textVec.push_back(fmt::format("Das Leuchten führt dich in einen Tempel ähnlichen Raum mit einem Altar in der Mitte"));
	textVec.push_back(fmt::format("Neben jenem Alter siehst du mehrere violette Fackeln, welche ihn beleuchten."));
	textVec.push_back(fmt::format("Aus den Schatten erhebt sich eine umhüllte Gestalt, welche sich neben den Altar stellt."));
	textVec.push_back(fmt::format("\"Ich habe dich bereits erwartet {0}.",m_player->getName()));
	textVec.push_back(fmt::format("Dein Körper wird sich wunderbar in meiner Sammlung machen.\""));
	textVec.push_back(fmt::format("Ohne weiter zu zögern greift die Gestalt dich an"));
	displayText(textVec);

	auto necromancer = Necromancer::generateEnemies();
	Battle necromancerBattle(m_player, necromancer);
	if (!m_player->isAlive())
		return;

	textVec.push_back(fmt::format("Nach einem harten Kampf konntest du den Nekromanten besiegen."));
	textVec.push_back(fmt::format("Mit seinem Tod erloschen auch die Flammen die den Raum einst erhellten."));
	textVec.push_back(fmt::format("Es scheint als hätte er ein Ritual durchgeführt um die Monster herbei zu rufen, jedoch scheint es jetzt gestoppt worden zu sein."));
	textVec.push_back(fmt::format("Nach einer Verschnaufspause machst du dich  wieder auf den Weg zum Dorf um von deiner Reise zu berichten."));
	textVec.push_back(fmt::format("\nEnde von Kapitel 1."));
	displayText(textVec);
}

void Adventure::displayText(std::vector<std::string>& text) {
	for (const auto& element:text){
		fmt::print(element);
		std::cin.get();
	}
	text.clear();
}
