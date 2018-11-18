#include "pch.h"
#include "Human.h"

Human::Human(){}

Human::~Human(){}

//method called by player object to commence dice roll sequence
void Human::RollDice() {
	return dice.diceDriver();
}

//method that prompts the player for order of dice to be resolved
void Human::ResolveDice() {
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

	cout << "Select the order in which you would like to resolve your die.";
	for (int i = 0; i < values.size(); i++) {
		options[i + 1] = values[i];
		cout << endl;
		cout << "Option #" << i + 1 << ": " << values[i] << endl;
	}
	for (int i = 1; i <= values.size(); i++) {
		cout << "Enter dice option number:";
		cin >> resolveChoice;
		while (resolveChoice > options.size() || resolveChoice < 0)
		{
			cout << "Invalid Input, must in option list, please try again." << endl;
			cin >> resolveChoice;
		}
		resolveOrder.push_back(resolveChoice);
	}
	for (int i = 0; i < resolveOrder.size(); i++) {
		resolveValue(options[resolveOrder[i]], valueCount[options[resolveOrder[i]]]);
	}
}

void Human::move(Map &map) {

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
		cout << "Would like to move to another borough? (yes or no): " << endl;

		string answer;
		cin >> answer;
		while (answer != "yes" && answer != "no" && answer != "Yes" && answer != "No") {
			cout << "Invalid answer. Please enter yes or no: ";
			cin >> answer;
		}

		if (answer == "Yes" || answer == "yes") {
			cout << "Please Choose the zone you would like to move too from these" << endl;

			for (int i = 0; i < positions.size(); i++) {
				if (positions[i].start) {
					cout << i << ": " << positions[i].name << endl;
				}
			}

			int playerChoice;
			cin >> playerChoice;
			while (playerChoice < 0 || playerChoice >= positions.size() || !positions[playerChoice].start || map.graph.getNbOfPlayersInZone(positions[playerChoice].id) >= 2) {
				if (playerChoice < 0 || playerChoice >= positions.size()) {
					cout << "enter valied region ID: " << endl;
				}
				else {
					cout << "Choose from the given IDs: " << endl;
				}
				cin >> playerChoice;
			}

			//removing player from current position
			int currentSize = map.graph.getNbOfPlayersInZone(this->region.id);
			map.graph.setNbOfPlayersInZone(this->region.id, --currentSize);

			this->region = positions[playerChoice];

			//add to the player count of the ZONE
			currentSize = map.graph.getNbOfPlayersInZone(this->region.id);
			map.graph.setNbOfPlayersInZone(this->region.id, ++currentSize);
		}

	}
}

void Human::buyCards(Deck &deck) {
	string answer;
	string againAsnwer;
	bool goAgain = true;
	cout << "Do you wish to buy a card?";
	cin >> answer;
	while (answer != "yes" && answer != "no" && answer != "Yes" && answer != "No") {
		cout << "Invalid answer. Please enter yes or no: ";
		cin >> answer;
	}
	if (answer == "yes" || answer == "Yes") {
		while (goAgain == true) {
			buyDiscard(deck);
			cout << "Would you like to go again?" << endl;
			cin >> againAsnwer;
			while (againAsnwer != "yes" && againAsnwer != "no" && againAsnwer != "Yes" && againAsnwer != "No") {
				cout << "Invalid answer. Please enter yes or no: ";
				cin >> againAsnwer;
			}
			if (againAsnwer == "yes" || againAsnwer == "Yes") {
				goAgain = true;
			}
			else {
				cout << "okay ending turn!";
				goAgain = false;
			}
		}
	}
	else if (answer == "no" || answer == "No") {
		cout << "Ending Turn!" << endl;

	}
}
