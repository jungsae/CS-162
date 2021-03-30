#ifndef CATALOG_H //header guard
#define CATALOG_H //header guard

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

 
struct wizard
{
  string name;
  int id;
  string password;
  string position_title;
  float beard_length;
};

struct spell
{
  string name;
  float success_rate;
  string effect;
};

struct spellbook
{
  string title;
  string author;
  int num_pages;
  int edition;
  int num_spells;
  float avg_success_rate;
  struct spell *s;
};
void options_1(int &choice); // give choices to user

void options_2(int &choice); // give choices to user about options_1

spellbook *create_spellbooks(int number); // make an array for spellbooks

spell *create_spells(int); // make an array for spells

void get_spellbook_data(spellbook *, int, ifstream &); // get spellbooks information from txt file

void get_spell_data(spell *, int, ifstream &); // get spells information from txt file

wizard* create_wizard(int); //make an array for wizards

void get_wizard_data(wizard *, int, ifstream &); // get wizards information from txt file

void delete_info(wizard **, spellbook **, int); // remove array structres 

#endif
