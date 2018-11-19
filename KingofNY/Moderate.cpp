#include "pch.h"
#include "Moderate.h"

Moderate::Moderate(){}
Moderate::~Moderate(){}

void Moderate::RollDice(){
	int numOfValues = 0;
	dice.firstRoll();

	for (string value : dice.valueArray) {
		if (value == "Energy" || value == "Heal") {
			dice.keepArray.push_back(value);
			numOfValues++;
		}
	}

	int numOfRolls = 1;
	while (numOfRolls < 3) {
		if (numOfValues >= 6) {
			break;
		}

		cout << "####### Rerolling dices" << endl;
		dice.rerollAll();

		for (string value : dice.valueArray) {
			if (numOfValues >= 6) {
				break;
			}
			if (value == "Energy" || value == "Heal") {
				dice.keepArray.push_back(value);
				numOfValues++;
			}
		}
		numOfRolls++;
	}

	//if the keepArray is not filled up yet, will add the remaining values inside
	if (numOfValues < 6) {
		for (string value : dice.valueArray) {
			if (numOfValues >= 6) {
				break;
			}
			//since these value will have already been push back previously.
			if (value != "Energy" || value != "Heal")
				dice.keepArray.push_back(value);
			numOfValues++;
		}
	}

	//Show values kept
	cout << "Here are the values of your dice:" << endl;
	for (string value : dice.keepArray) {
		cout << value << endl;
		cin;
	}
}

void Moderate::ResolveDice(){
	int resolveChoice;
	vector<int> resolveOrder;
	vector<string> values = dice.getDiceValues();
	map<string, int> valueCount;
	map<int, string> options;
	int enCount = 0;
	int atCount = 0;
	int deCount = 0;
	int heCount = 0;
	int ceCount = 0;
	int ouCount = 0;

	for (int i = 0; i < values.size(); i++) {
		if (values[i] == "Energy") {
			enCount++;
		}
		else if (values[i] == "Attack") {
			atCount++;
		}
		else if (values[i] == "Destruction") {
			deCount++;
		}
		else if (values[i] == "Heal") {
			heCount++;
		}
		else if (values[i] == "Celebrity") {
			ceCount++;
		}
		else if (values[i] == "Ouch!") {
			ouCount++;
		}
	}
	valueCount["Energy"] = enCount;
	valueCount["Attack"] = atCount;
	valueCount["Destruction"] = deCount;
	valueCount["Heal"] = heCount;
	valueCount["Celebrity"] = ceCount;
	valueCount["Ouch!"] = ouCount;


	sort(values.begin(), values.end());

	auto iter = unique(values.begin(), values.end());
	values.erase(iter, values.end());

	for (int i = 1; i <= values.size(); i++) {
		resolveOrder.push_back(i);
	}
	for (int i = 0; i < resolveOrder.size(); i++) {
		resolveValue(options[resolveOrder[i]], valueCount[options[resolveOrder[i]]]);
	}

	cout << "Value have been resolved in order. End of resolved" << endl;
}

void Moderate::move(Map & map) {
	vector<Node> positions = map.graph.availableRegions(this->region.id);
	int currentSize = 0;

	//if player is in manhattan. (not a starting position)
	if (!this->region.start) {
		//if player is upper manhattan, no movement during this turn
		if (this->region.victoryPoints == 2 || this->region.energyCube == 2) {
			cout << "You are already in upper Manhattan." << endl;
		}
		else {
			//moving to next manhattan zone
			cout << "Moving to " << positions[0].name << endl;

			//removing player from current position
			int currentSize = map.graph.getNbOfPlayersInZone(this->region.id);
			map.graph.setNbOfPlayersInZone(this->region.id, --currentSize);

			this->region = positions[0];

			//add to the player count of the ZONE
			currentSize = map.graph.getNbOfPlayersInZone(this->region.id);
			map.graph.setNbOfPlayersInZone(this->region.id, ++currentSize);
		}
	}
	//if there is no one in manhattan, player needs to move into manhattan
	else if (map.graph.getNbOfPlayersInManhattan() == 0) {
		cout << endl << "You need to move to Manhattan. New posistion: " << positions[0].name << endl;

		//removing player from current position
		currentSize = map.graph.getNbOfPlayersInZone(this->region.id);
		map.graph.setNbOfPlayersInZone(this->region.id, --currentSize);

		this->region = positions[0];
		map.graph.setNbOfPlayersInManhattan(1);
	}
	else {
		//removing player from current position
		int currentSize = map.graph.getNbOfPlayersInZone(this->region.id);
		map.graph.setNbOfPlayersInZone(this->region.id, --currentSize);

		int newPos = rand() % positions.size() + 1;
		this->region = positions[newPos];

		//add to the player count of the ZONE
		currentSize = map.graph.getNbOfPlayersInZone(this->region.id);
		map.graph.setNbOfPlayersInZone(this->region.id, ++currentSize);
	}
}

void Moderate::buyCards(Deck & deck) {
	cout << "Player will not buy cards. Ending Turn!" << endl;
}
