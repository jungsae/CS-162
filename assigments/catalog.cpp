#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include "catalog.h"

void options_1(int &choice)
{
    cout << "Which option would you like to choose?"<<endl;
    cout << "1. Sort spellbooks by number of pages" <<endl;
    cout << "2. Group spells by their effect"<<endl;
    cout << "3. Sort spellbooks by average success rate"<<endl;
    cout << "4. Quit\n";
    cout << "Your Choice: ";
    cin >> choice;
    cout<<endl;
    
    while(!(choice == 1 || choice == 2 || choice == 3 || choice == 4))
    {
        cout << "Invalid Input. Try Again"<<endl;
        cout << "Your Choice" <<endl;
        cin >> choice;
    }
}

void options_2(int &choice)
{
    cout << "How would you like the information displayed?" << endl;
    cout << "1. Print to screen (Press 1)" << endl;
    cout << "2. Print to file (Press 2)" <<endl;
    cout << "Your choice: ";
    cin >> choice;
    cout<<endl;
    
    while(!(choice == 1 || choice == 2))
    {
        cout << "Invalid Input. Try Again"<<endl;
        cout << "Your Choice" <<endl;
        cin >> choice;
    }
}
  
wizard* create_wizard(int num_wiz)
{
    wizard* new_wizards = new wizard[num_wiz];

    return new_wizards;
}

spellbook* create_spellbooks(int num_spl_bk)
{
    spellbook *new_spellbooks = new spellbook[num_spl_bk];

    return new_spellbooks;
}

spell* create_spells(int num_spl)
{
    spell *new_spells = new spell[num_spl];

    return new_spells;
}

void get_wizard_data(wizard *wizards, int number, ifstream &infile)
{
    string tmp_string;
    getline(infile, tmp_string);

    for (int i = 0; i < number; i++)
    {
        infile >> wizards[i].name;
        infile >> wizards[i].id;
        infile >> wizards[i].password;
        infile >> wizards[i].position_title;
        infile >> wizards[i].beard_length;
    }
}

void get_spellbook_data(spellbook *spellbooks, int number, ifstream &infile)
{
    string tmp_string;
    getline(infile,tmp_string);
    int i=0;
    int j=0;

    for ( i = 0; i < number; i++)
    {
        infile >> spellbooks[i].title;
        infile >> spellbooks[i].author;
        infile >> spellbooks[i].num_pages;
        infile >> spellbooks[i].edition;
        infile >> spellbooks[i].num_spells;
        spellbooks[i].s = create_spells(spellbooks[i].num_spells);
        get_spell_data(spellbooks[i].s, spellbooks[i].num_spells, infile);
    
        float ave = 0;
        for( j = 0; j < spellbooks[i].num_spells; j++)
        {
            ave=(spellbooks[i].s[j].success_rate)+(ave);    
        }

        spellbooks[i].avg_success_rate = (ave)/(spellbooks[i].num_spells);
    }
}

void get_spell_data(spell *spells, int number, ifstream &infile)
{
    for (int i = 0; i < number; i++)
    {
        infile >> spells[i].name;
        infile >> spells[i].success_rate;
        infile >> spells[i].effect;
    }
}

void delete_info(wizard **wizards, spellbook **spellbooks, int number)
{
    for(int i=0; i < number; i++)
    {
        delete[] (*spellbooks)[i].s;
    }
    delete[] *spellbooks;
    *spellbooks = NULL;
    delete[] *wizards;
    *wizards = NULL;
}


