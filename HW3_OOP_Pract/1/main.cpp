/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Kalin Borisov
* @idnumber 62580
* @task 3
* @compiler VC
*/

#include <iostream>
#include "Deck.hpp"
#include "Base.hpp"
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "PendulumCard.hpp"
#include "Duelist.hpp"

int main()
{
	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000, 2500);
		MonsterCard magician("Dark Magician", "The ultimate wizard.", 2500, 2100);
	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", Type::spell);
		MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.",Type::trap);
	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap MagicCards", 1200, 600, Type::spell,8);
		Duelist firstDuelist("Ivan Ivanov");
	firstDuelist.getDeck().setDeckname("Magician Deck");
	firstDuelist.getDeck().addMonsterCard(dragon);
	firstDuelist.getDeck().addMagicCard(swords);
	firstDuelist.getDeck().addMonsterCard(magician);
	firstDuelist.getDeck().addMagicCard(cylinder);
	firstDuelist.getDeck().addPendulumCard(timegazer);
	firstDuelist.display();
	firstDuelist.saveDeck("magician_deck.txt");
	firstDuelist.loadDeck("magician_deck.txt");
	firstDuelist.display();
	MagicCard box("Mystic Box", "Destroy one monster.", Type::spell);
	firstDuelist.getDeck().ChangeMagicCard(1, box);



	return 0;
}