/*
	Title:  	lab10.h
	Author:		Griffin Sutton
	Date:		04/15/26	
	Purpose:	Header file containing all includes, namespaces, and function 
				prototypes for the digital spell book program.
*/

#ifndef LAB10_H
#define LAB10_H

#include <iostream>
#include <string>

using namespace std;

//struct declaration
struct spell {
	string spell_name;
	string element;
	int power_level;
	bool is_learned;
};

//function prototypes
void display_menu();
void learn_spell(spell* spellbook, int& spell_count, int max_spell_count);
void cast_spell(spell* spellbook, int spell_count);
void display_top_spells(spell* spellbook, int spell_count);
void display_extreme_spells(spell* spellbook, int spell_count);

#endif