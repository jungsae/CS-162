/******************************************************
** Program: assign1.cpp
** Author: Saehan Jung
** Date: 04/16/20
** Description: It is a program that get id and passward from user, and show information from
                outside txt files Also, It can export information in a txt form.
** Input: Executable file and 2 text files. Id and passward information that are in the text files.
** Output: Show information in text files which are sorted by user choice and export information as a txtfile.
******************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "catalog.h"
using namespace std;

int main(int argc, char* argv[])
{
    int count=0;
    char* wfile = argv[1];
    char* sfile = argv[2];

    ifstream infile1(wfile);
    if (infile1.fail())
    {
        cout << "Error, unable to open file!" << endl;
        return -1;
    }

    ifstream infile2(sfile);
    if (infile2.fail())
    {
        cout << "Error, unable to open file!" << endl;
        return -1;
    }

    int num_of_wizards;
    infile1 >> num_of_wizards;
    wizard* wizards = create_wizard(num_of_wizards);
    get_wizard_data(wizards,num_of_wizards,infile1);
    
    int num_of_spellbooks;
    infile2 >> num_of_spellbooks;
    spellbook* spellbooks = create_spellbooks(num_of_spellbooks);
    get_spellbook_data(spellbooks, num_of_spellbooks, infile2);
    
    
    string user_postion;
    int id;
    string pw;
    int check=0;
    int i;
    int j;
    cout << "Please enter your id: ";
    cin>>id;
    cout << "Please enter your password: ";
    cin>>pw;

    for(i=0; i<num_of_wizards; i++)
    {
        if(id==wizards[i].id)
        {
            if(pw==wizards[i].password)
            {
                
                cout << endl << "Welcome " << wizards[i].name << endl;
                cout << "ID: " << wizards[i].id << endl;
                cout << "Status: " << wizards[i].position_title << endl;
                cout << "Beard Length: " << wizards[i].beard_length << endl << endl;
                user_postion=wizards[i].position_title;               
            }
        }
    }
    count++;
    
    while (count < 3)
    {
        count++;
        cout << "Incorrect id or password" << endl;
        cout << "Please enter your id: ";
        cin >> id;
        cout << "Please enter your password: ";
        cin >> pw;

        for (j=0; j<num_of_wizards; j++)
        {
            if (id == wizards[i].id)
            {
                if (pw == wizards[i].password)
                {
                    cout << endl << "Welcome " << wizards[i].name << endl;
                    cout << "ID: " << wizards[i].id << endl;
                    cout << "Status: " << wizards[i].position_title << endl;
                    cout << "Beard Length: " << wizards[i].beard_length << endl << endl;
                    check=505;
                    user_postion = wizards[i].position_title;
                }
            }
        }

    }
    
    if(count==3)
    {
        return 0;
    }

    int option1;
    int option2;
    string new_file;
    int end;

    do
    {
        options_1(option1);
        if(option1==1)
        {
            for(int k=0; k<num_of_spellbooks-1; k++)
            {
                for(int l=0; l<num_of_spellbooks; l++)
                {
                    if(spellbooks[l-1].num_pages > spellbooks[l].num_pages)
                    {
                        spellbook comp = spellbooks[l-1];
                        spellbooks[l-1] = spellbooks[l];
                        spellbooks[l] = comp;
                    }
                }
            }

            options_2(option2);
            if(option2==1)
            {
               if(user_postion== "Student")
               {    
                   int cannot=0;

                   for(int q=0; q<num_of_spellbooks; q++)
                   {
                       for(int r=0; r<spellbooks[q].num_spells; r++)
                       {
                           if(spellbooks[q].s[r].effect == "death" || spellbooks[q].s[r].effect == "position")
                            {
                                cannot = 1;
                            } 
                       }

                       if (!(cannot == 1))
                       {
                           cout << spellbooks[q].title << " " << spellbooks[q].num_pages << endl;
                           cannot = 0;
                       }
                   }
                   cout<<endl;
               }

                else
                {
                    for(int s=0; s< num_of_spellbooks; s++)
                    {
                        cout << spellbooks[s].title << " " << spellbooks[s].num_pages << endl;
                    }
                    cout<<endl;
                }
            }
        
            else if(option2==2)
            {
                cout << "Please provide desired filename: ";
                cin >> new_file;
                cout << "Appended requested information to file." << endl << endl;
                ofstream make_txt(new_file,ios::app);

                if(user_postion == "Student")
                {
                    int checkk = 0;
                    for(int t=0; t<num_of_spellbooks; t++)
                    {
                        for(int u=0; u<spellbooks[t].num_spells; t++)
                        {
                            if(spellbooks[t].s[u].effect == "death"||spellbooks[t].s[u].effect == "poison")
                            {
                                checkk=1;
                            }
                        }

                        if(checkk != 1)
                        {
                            make_txt << spellbooks[t].title <<" "<<spellbooks[t].num_pages << endl;
                        }
                        checkk = 0;
                    }
                    cout<<endl;
                }

                for(int v=0; v<num_of_spellbooks; v++)
                {
                    make_txt << spellbooks[v].title << " " << spellbooks[v].num_pages << endl;
                }
            make_txt.close();
            }
        }

        else if(option1 == 2)
        {
            options_2(option2);
            if(option2 == 1)
            {
                for(int m=0; m < num_of_spellbooks; m++)
                {
                    for(int n=0; n < spellbooks[m].num_spells; n++)
                    {
                        if(spellbooks[m].s[n].effect == "bubble")
                        {
                            cout << spellbooks[m].s[n].effect << " " << spellbooks[m].s[n].name << endl;
                        }
                    }
                }

                for(int m=0; m < num_of_spellbooks; m++)
                {
                    for(int n=0; n < spellbooks[m].num_spells; n++)
                    {
                        if(spellbooks[m].s[n].effect == "memory_loss")
                        {
                            cout << spellbooks[m].s[n].effect << " " << spellbooks[m].s[n].name << endl;
                        }
                    }
                }
                
                for(int m=0; m < num_of_spellbooks; m++)
                {
                    for(int n=0; n < spellbooks[m].num_spells; n++)
                    {
                        if(spellbooks[m].s[n].effect == "fire")
                        {
                            cout << spellbooks[m].s[n].effect << " " << spellbooks[m].s[n].name << endl;
                        }
                    }
                }

                if(user_postion != "Student")
                {
                    for(int m=0; m < num_of_spellbooks; m++)
                    {
                        for(int n=0; n< spellbooks[m].num_spells; n++)
                        {
                            if(spellbooks[m].s[n].effect == "poison")
                            {
                                cout << spellbooks[m].s[n].effect << " " << spellbooks[m].s[n].name << endl;
                            }
                        }
                    }

                    for(int m=0; m < num_of_spellbooks; m++)
                    {
                        for(int n=0; n< spellbooks[m].num_spells; n++)
                        {
                            if(spellbooks[m].s[n].effect == "death")
                            {
                                cout << spellbooks[m].s[n].effect << " " << spellbooks[m].s[n].name << endl;
                            }
                        }
                    }
                }
            }

            else if(option2==2)
            {
                cout << "Please provide desired filename: ";
                cin >> new_file;
                cout << "Appended requested information to file." << endl << endl;
                ofstream make_txt(new_file,ios::app);

                for(int m=0; m < num_of_spellbooks; m++)
                {
                    for(int n=0; n < spellbooks[m].num_spells; n++)
                    {
                        if(spellbooks[m].s[n].effect == "bubble")
                        {
                            make_txt << spellbooks[m].s[n].effect << " " << spellbooks[m].s[n].name << endl;
                        }
                    }
                }

                for(int m=0; m < num_of_spellbooks; m++)
                {
                    for(int n=0; n < spellbooks[m].num_spells; n++)
                    {
                        if(spellbooks[m].s[n].effect == "memory_loss")
                        {
                            make_txt << spellbooks[m].s[n].effect << " " << spellbooks[m].s[n].name << endl;
                        }
                    }
                }
                
                for(int m=0; m < num_of_spellbooks; m++)
                {
                    for(int n=0; n < spellbooks[m].num_spells; n++)
                    {
                        if(spellbooks[m].s[n].effect == "fire")
                        {
                            make_txt << spellbooks[m].s[n].effect << " " << spellbooks[m].s[n].name << endl;
                        }
                    }
                }

                if(user_postion != "Student")
                {
                    for(int m=0; m < num_of_spellbooks; m++)
                    {
                        for(int n=0; n< spellbooks[m].num_spells; n++)
                        {
                            if(spellbooks[m].s[n].effect == "poison")
                            {
                                make_txt << spellbooks[m].s[n].effect << " " << spellbooks[m].s[n].name << endl;
                            }
                        }
                    }

                    for(int m=0; m < num_of_spellbooks; m++)
                    {
                        for(int n=0; n< spellbooks[m].num_spells; n++)
                        {
                            if(spellbooks[m].s[n].effect == "death")
                            {
                                make_txt << spellbooks[m].s[n].effect << " " << spellbooks[m].s[n].name << endl;
                            }
                        }
                    }
                } 
            make_txt.close();
            }
        }

        else if(option1 == 3)
        {
            for(int k=0; k<num_of_spellbooks-1; k++)
            {
                for(int l=0; l<num_of_spellbooks; l++)
                {
                    if(spellbooks[l-1].avg_success_rate < spellbooks[l].avg_success_rate)
                    {
                        spellbook comp = spellbooks[l-1];
                        spellbooks[l-1] = spellbooks[l];
                        spellbooks[l] = comp;
                    }
                }
            }

            options_2(option2);
            if(option2 == 1)
            {
                if(user_postion== "Student")
                {    
                   int cannot=0;

                   for(int q=0; q<num_of_spellbooks; q++)
                   {
                       for(int r=0; r<spellbooks[q].num_spells; r++)
                       {
                           if(spellbooks[q].s[r].effect == "death" || spellbooks[q].s[r].effect == "position")
                            {
                                cannot = 1;
                            } 
                       }

                       if (!(cannot == 1))
                       {
                           cout << spellbooks[q].title << " " << spellbooks[q].num_pages << endl;
                           cannot = 0;
                       }
                   }
                   cout<<endl;
                }

                else
                {
                    for(int s=0; s< num_of_spellbooks; s++)
                    {
                        cout << spellbooks[s].title << " " << spellbooks[s].num_pages << endl;
                    }
                }
            }

            else if(option2 == 2)
            {
                cout << "Please provide desired filename: ";
                cin >> new_file;
                cout << "Appended requested information to file.";
                ofstream make_txt(new_file,ios::app);

                if(user_postion== "Student")
                {    
                   int cannot=0;

                   for(int q=0; q<num_of_spellbooks; q++)
                   {
                       for(int r=0; r<spellbooks[q].num_spells; r++)
                       {
                           if(spellbooks[q].s[r].effect == "death" || spellbooks[q].s[r].effect == "position")
                            {
                                cannot = 1;
                            } 
                       }

                       if (!(cannot == 1))
                       {
                           cout << spellbooks[q].title << " " << spellbooks[q].avg_success_rate << endl;
                           cannot = 0;
                       }
                   }
                   make_txt<<endl;
                }

                else
                {
                    for(int s=0; s< num_of_spellbooks; s++)
                    {
                        cout << spellbooks[s].title << " " << spellbooks[s].avg_success_rate << endl;
                    }
                }
            make_txt.close(); 
            }
        }
        
        else if(option1 == 4)
        {   
            cout<< "END" <<endl;
            end=1;
            
        }
        
    }while(end!=1);

    infile1.close();
    infile2.close(); 
    delete_info(&wizards, &spellbooks, num_of_spellbooks);
    return 0;      
}

/* Login error */