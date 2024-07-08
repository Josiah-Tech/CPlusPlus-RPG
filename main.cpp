/*************************************************
Josiah Rodriguez 
This Program uses a menu system, functions, logic, 
processing, and decisions. It is using a fantasy 
setting to demonstrate these skills.
*************************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// STRUCTURE FOR CHARACTER CREATION
struct Character
{
 string name;
 string Class;
 bool elf;
 bool barbarian;
 bool wizard;
};

//CLASS FOR THE SHOPPING PORTION 
class Shop
    {
        public:
        void initialGold(int);
        void transaction(int*, int);
        void showAmount();
        private:
        int gold;
    };
    
// Function Prototypes
void Start_Function();
void Part2_Function();
void Credits_Function();

int main()
{
    // variables
    int Choice;
    
    // Choice Variables
    const int Start_Choice = 1,
              Part2_Choice = 2,
              Credits_Choice = 3,
              Quit_Choice = 4;
    // The Menu
    cout << "\t Welcome to\n";
    cout
<< "  #####                  #####                             \n"
<< " #     #   #     #      #     # #    # ######  ####  ##### \n" 
<< " #         #     #      #     # #    # #      #        #   \n"
<< " #       ##### #####    #     # #    # #####   ####    #   \n"
<< " #         #     #      #   # # #    # #           #   #   \n"
<< " #     #   #     #      #    #  #    # #      #    #   #   \n"
<< "  #####                  #### #  ####  ######  ####    # \n\n";
                                                                      


    cout << "\t MENU\n";
    cout << "Hello Adventurer!\n";
    cout << "Select from this menu.\n";
    cout << "1. Start Your Quest!\n";
    cout << "2. Start from Part 2.\n";
    cout << "3. Credits for C++ Quest.\n";
    cout << "4. Quit C++ Quest.\n";
    cin >> Choice;
    
    //if statements
    while (Choice < 1 || Choice > 4)
    {
     cout << "Have too much mead adventurer?\n";
     cout << "Choose one of the four options to start your quest!\n";
     cin >> Choice;    
    }
    if (Choice == Start_Choice)
    {
     Start_Function();  
    }
    else if (Choice == Part2_Choice)
    {
     Part2_Function();  
    }
    else if (Choice == Credits_Choice)
    {
     Credits_Function();    
    }
    else if (Choice == Quit_Choice)
    {
        cout << "So long adventurer! The story waits for your return...\n";
        
    }
    return 0;
}

/*****************************************
Start function 
This function is the beginning of the 
adventure. 
*****************************************/
void Start_Function()
{
    // SAVE FILE RELATED 
    ofstream outputFile("save.txt");
    string name;
    bool namechoice;
    
    Character player; // struct type declaration
    
    int startingGold = 100;
    int fairyAmount = 0;
    int *goldptr = &startingGold;
    Shop Transaction1; // class declaration and related information
    
    
    cout << "Hello adventurer! Before you start your quest you need to make a few choices.\n"
         << "The first choice is your name. What is your name?\n";
    cin.ignore();
    getline(cin, player.name);
    outputFile << player.name << endl;
    cout << player.name << " is it? Well, " << player.name << ", your second choice is your class.\n\n"
         << "You can be an wood ELF archer. At 400 years old you're still quite young\n"
         << "and with your youth comes a headstrong attitude.\n\n"
         << "You can be a BARBARIAN warrior from the cold north. Brutish and strong you\n"
         << "often get confused with an orc. You take it as a compliment.\n\n"
         << "You can be an old wise WIZARD from the isle of Simerule. You've devoted\n"
         << "your life to the study of spells. You definitly have a few tricks up your sleve.\n\n"
         << "All these warriors have their strengths and weaknesses. What will you choose?\n"
         << "Your choices are the classes in bold, your choice should be in all capital or lowercase letters.\n";
          getline(cin, player.Class);
          
    while (player.Class != "ELF" && player.Class != "BARBARIAN" && player.Class != "WIZARD" &&
           player.Class != "elf" && player.Class != "barbarian" && player.Class != "wizard")   
           {
               cout << "Sorry, your choice wasn't correctly formatted\n"
                    << "Your choice should be in either all capitals or all lowercase.\n";
                getline(cin, player.Class);    
           }
    if (player.Class == "ELF" || player.Class == "elf")
    {
        player.elf = true;
        player.barbarian = false;
        player.wizard = false;
        cout << "You chose the elf. A wise choice.\n"
             << "These choices are over, "<< player.name << ", but a multitude await you in your adventure..\n"; 
        outputFile << player.elf << endl;
        outputFile << player.barbarian << endl;
        outputFile << player.wizard << endl;
    }
    else if (player.Class == "BARBARIAN" || player.Class == "barbarian")
    {
        player.elf = false;
        player.barbarian = true;
        player.wizard = false;
        cout << "You chose the barbarian. A wise choice.\n"
             << "These choices are over, "<< player.name << ", but a multitude await you in your adventure..\n";
        outputFile << player.elf << endl;
        outputFile << player.barbarian << endl;
        outputFile << player.wizard << endl;
    }
    else if (player.Class == "WIZARD" || player.Class == "wizard")
    {
        player.elf = false;
        player.barbarian = false;
        player.wizard = true;
        cout << "You chose the wizard. A wise choice.\n"
             << "These choices are over, "<< player.name << ", but a multitude await you in your adventure..\n";
        outputFile << player.elf << endl;
        outputFile << player.barbarian << endl;
        outputFile << player.wizard << endl;     
    }
    
    // GAME START
    cout << "\n\n\n";
   cout << "You wake up in the local inn. Your last mercenary job has kept\n"; 
   cout << "you unconscious for two days. \n"
        << "The only things to your name are 100 gold, your weapons, and some mead.\n";
   cout << "So " << player.name << " you have two options:\n";  
   cout << "The options you have are in bold.\n" ;
   cout << "If you enter anything else it's up to you, but beware of this. \n";
   
   //CHOICE 1
   string choice1;
   cout << "You can get UP from bed or DRINK your mead. \n";
   cin >> choice1;
    if (choice1 == "UP" || choice1 == "up")
    {
    cout << "You get up from your bed, get dressed and grab your gear.\n";
    }
    else if (choice1 == "DRINK" || choice1 == "drink")
    {
    cout << "You go to your gear and grab your mead, you put it to your lips ";
    cout << "and… of course empty.\nEither way you’re up now so you get ";
    cout << "dressed and grab your gear.\n\n";
    }
   else 
   {
    cout << "While thinking about your choice you fall back asleep.\n"; 
    cout << "Eventually you wake back up and get dressed and go down the stairs.\n\n";  
   }
   
   //CHOICE 2
   string choice2;
   cout << "Down the stairs is the bar. You go to the bartender to get your bounty.\n"; 
   cout << "“You were out for two days, I’m taking it out of your reward.” The bartender says.\n" ;
   cout << "“You said it was one guy, not twelve.” You retort, “I did the bounty, I get the coin.”\n"; 
   cout << "You’re agitated, you can THREATEN him or you can REASON with him. \n";
   cin >> choice2;
   if (choice2 == "THREATEN" || choice2 == "threaten")
   {
   cout << "You’re angry, you worked hard for that bounty. In your rage you say \n"; 
   cout << "“I killed 12 men for this bounty, what’s one more?” The barkeep turns pale,\n";
   cout << "drops the gold in your hand and turns away to the cellar.\n\n";
   startingGold += 30;
   }
   else if (choice2 == "REASON" || choice2 == "reason")
   {
    cout << "You take a breath and say, “The bounty was for one guy not twelve, I \n";
    cout << "should be paid for the extra work.” The barkeep thinks it over. “I’ll give you\n";
    cout << "half, but that’s it.” You nod and take the gold.\n\n";
    startingGold += 15;
   }
    else 
    {
    cout << "“You get half and nothing more.” The barkeep says. “Now take it and \n";
    cout << "come back later if you want another bounty.” You snatch the gold from his \n";
    cout << "hand\n\n";
    startingGold += 15;
    }
   
   //CHOICE 3
   string choice3;
   cout << "As you walk away your arm is grabbed by an elf. His clothes indicate\n"; 
   cout << "a highborne, someone that doesn’t belong in this dingy tavern.\n";
   if (player.elf == true)
   {
       cout << "“Looking for a new quest, fellow woodland child?” he says with a toothy smile.\n";   
   }
   else if (player.barbarian == true)
   {
       cout << "“Looking for a new quest, my brutish friend?” he says with a toothy smile.\n";
   }
   else if (player.wizard == true)
   {
       cout << "“Looking for a new quest, spellcaster?” he says with a toothy smile.\n";
   }
   cout << "Do you LISTEN or do you WALK away?\n";
   cin >> choice3;
   if (choice3 == "LISTEN" || choice3 == "listen")
   {
    cout << "You snatch your arm away and as you pull away you feel a bit of a sting.\n";
    cout << "He continues, “Hold on to that anger, you’ll need it.” He lowers his voice \n";
    cout << "and says “I have a quest that will benefit the both of us.”\n\n";
   }
    else if (choice3 == "WALK" || choice3 == "walk") 
    {
    cout << "You snatch your arm away and as you pull away you feel a bit of a sting.\n";
    cout << "You ignore it and keep walking toward the exit. He yells “Hold on! ” and \n";
    cout << "chases you down, “Please listen, it will benefit the both of us.”\n\n";
    }
   else
   {
   cout << "He releases your arm. His toothy grin widens. He starts, “I believe I have a \n";
   cout << "quest that will benefit the both of us.”\n\n";
   }
   cout << "“I am Nevar the Apprentice. There is a temple in ruins just north of here.\n"; 
   cout << "It belonged to an old wizard who just vanished one day. \n";
   if (player.wizard = true)
   {
   cout << "He was much older than you, and much more powerful.\n";
   }
   cout << "The locals don’t go near it out of fear, they \n";
   cout << "don’t know what they’re missing.” You see the desperation as he talks,\n";
   cout << "he really wants whatever is in that temple. “Get to the point.” you bark.\n";
   cout << "“The point is that there is something for the both of us in that temple. Near \n";
   cout << "the end of his life he became paranoid, he amassed all his wealth and it’s \n";
   cout << "still in that temple. I don’t care for his riches. I want his tome, the entirety \n";
   cout << "of his knowledge.” He talks as if he will die without it, “If it was so easy\n";
   cout << "you would have done it already. So what's the catch?” you ask. “With his \n";
   cout << "paranoia came the need to protect his knowledge and riches. I’m sure \n";
   cout << "getting to it won’t be easy, who knows what protections he has.” \n";
   cout << "“Here's the map to the temple, it's not far from here.\n";
   cout << "I never got your name..” he says.\n";
   
  //choice 4
  string choice4;
   cout << "You can REPLY with your name or you can TAKE the map and leave.\n";
   cin >> choice4;
   if (choice4 == "REPLY" || choice4 == "reply")
   {
    namechoice = true;
    outputFile << namechoice << endl;
   cout << "“My name is " << player.name << ", I will meet you back here when I find the books.” \n";
   cout << "you reply. You turn and walk away.\n\n";
   }
   else if (choice4 == "TAKE" || choice4 == "take")
   {
       namechoice = false;
       outputFile << namechoice << endl;
       cout << "“It doesn't matter, I’ll meet you back here when I find the books.\n”"; 
       cout << "you reply. You turn and walk away.\n\n";
   }
   else 
   {
       namechoice = false;
       outputFile << namechoice << endl;
       cout << "You stare blankly at the elf. He looks at you strangely.\n"; 
       cout << "The elf is confused and just puts the map in your hand. You turn and walk away.\n\n"; 
   }
   
   cout << "As you walk away the elf yells “Good Luck!” in his native tongue.\n";
   cout << "Hopefully you won't need it, you think to yourself.\n\n\n";
   
   //CHOICE 5
   string choice5;
   cout << "On the way out of town you see a shop. It doesn't seem like it receives a lot of buisness.\n"
        << "It might be a good idea to get something that will help you on your quest.\n"
        << "Do you want to GO in or LEAVE town and get on with your adventure?\n";
    cin >> choice5;
   if (choice5 == "GO" || choice5 == "go")
   {
    cout << "You walk inside the dusty old shop.\n"
         << "“Hello! This is the shop, feel free to look around.” the elderly shopkeep says.\n"
         << "You look around for items that will help you in your quest. \n"
         << "There’s a lot of dried meats, furs, and camping equipment.\n" 
         << "There are countless shelves but there isn't much to help you in your quest.\n"
         << "You see something glowing behind the counter, so you go investigate\n"
         << "Behind the counter are jars of fairies.\n"
         << "“They’ll save your life if you’re ever in need. Fifty gold each.” the shopkeep says.\n"
         << "Expensive but might be worth it if what the shopkeep says is true\n" ;
         Transaction1.initialGold(startingGold);
         int amountOfFairytobuy = startingGold / 50;
    cout << "With your gold you can buy " << amountOfFairytobuy <<  " of them. \n"
         << "How many do you want to buy? Input 0 if you want none.\n";
    cin  >> fairyAmount; 
         while (fairyAmount < 0 || fairyAmount > 2)
         {
             cout << "The shopkeep is confused. “With your amount of gold you can get one or two,\n" 
                  << "or none if you so choose.”\n";
             cin  >> fairyAmount;
         }
         if (fairyAmount == 1)
         {
            Transaction1.transaction(goldptr, fairyAmount);
            cout << "You have " << startingGold << " gold left.\n";
            
         }
         else if (fairyAmount == 2)
         {
            Transaction1.transaction(goldptr, fairyAmount);
            cout << "You have " << startingGold << " gold left.\n";         
             
         }
         else if (fairyAmount == 0)
         {
             cout << "“Well alright.” says the shopkeep “Have a good one.”\n";
         }
   }
   else if (choice5 == "LEAVE" || choice5 == "leave")
   {
    cout << "You decide to skip the shop. What could be in that dusty old shop anyways?\n";
    fairyAmount = 0;
   }
   else 
   {
    cout << "You're focused on your quest. You decide to skip the shop.\n" 
         << "What could be in that dusty old shop anyways?\n";
    fairyAmount = 0;
   }
        
  //CHOICE 6
  string choice6;
  cout << "\n\nYou exit out the towns gates and go on with your quest.\n"
       << "Out of the corner of your eye you see a big dark shadow.\n"
       << "Before you can react Goruk the Blooded slams you into the wall.\n"
       << "He pulls a knife to your throat. The knife looks like it's carved from stone, orc made.\n"
       << "“Where's my gold, " << player.name << "?” He sceams in your ear.\n"
       << "You have two options here. You can either FIGHT back or you can BARTER with him.\n";
  cin >> choice6;
  if (choice6 == "FIGHT" || choice6 == "fight")
  {
    if (player.barbarian == true)
    {
        cout << "He has your arms pinned against the wall. He is using all his orc strength\n"
             << "to hold you down.\n"
             << "You stuggle to grab the blade on your hip.\n"
             << "He slams you against the wall over and over. Your ears ring as you feel the warmth\n"
             << "of the blood rushing to your face.\n"
             << "Again he screams “Where is my gold? I won't ask again.”\n"
             << "In one quick, explosive motion you're able to free yourself.\n"
             << "You grab the blade at your side and before Goruk can react, he falls.\n\n";
    }
    else if (player.elf == true)
    {
         cout << "He has your arms pinned against the wall. He is using all his orc strength\n"
              << "to hold you down.\n"
              << "You can see the elven blade in your boot. If only you could reach it..\n"
              << "Sadly Goruk notices as well. He is enraged and shouts “Enough!”\n"
              << "He slides the blade of his knife across your throat.\n"
              << "You feel a tingling sensation as you fall to the ground.\n"
              << "The last thing you see is Goruk walking away with your coinpurse.\n"
              << "Then everything fades to black.\n\n";
        if (fairyAmount > 0)
        {
         cout << "After black comes immense, blinding light.\n"
              << "Your eyesight comes back into focus. It was the fairy!\n"
              << "Just like the shopkeep said it would, it saved you.\n"
              << "You see the fairy fly off into the sky. You look into the distance.\n";
                fairyAmount--;
         cout << "You can still see Goruk walking away counting your gold.\n"
              << "You reach into your boot and with one swift motion your elven blade leaves your hand.\n"
              << "You hear the orc fall to the ground. You can't believe the fairy actually saved you.\n"
              << "You get up and walk to Goruk's lifeless body. You pull the knife out and grab your gold.\n\n";
        }
        else if (fairyAmount == 0)
        {
         cout << "\t         You Have Died.\n"
              << "\t           Try Again.";
              return;
        }
    }
    else if (player.wizard == true)
    {
         cout << "He has your arms pinned against the wall. He is using all his orc strength\n"
              << " to hold you down.\n"
              << "You try to conjure a firebolt. If only you had a little more time..\n"
              << "Goruk notices the heat irradiating from your palm. He is enraged and shouts “Enough!”\n"
              << "He slides the blade of his knife across your throat.\n"
              << "You feel a tingling sensation as you fall to the ground.\n"
              << "The last thing you see is Goruk walking away with your coinpurse.\n"
              << "Then everything fades to black.\n\n"; 
         if (fairyAmount > 0)
        {
         cout << "After black comes immense, blinding light.\n"
              << "Your eyesight comes back into focus. It was the fairy!\n"
              << "Just like the shopkeep said it would, it saved you.\n"
              << "You see the fairy fly off into the sky. You look into the distance.\n";
                fairyAmount--;
         cout << "You can still see Goruk walking away counting your gold.\n"
              << "You close your eyes and expel all thought except for one. Fire.\n"
              << "Out of your hand shoots a fireball. You hear the orc scream and fall to the ground.\n"
              << "You get up and walk to Goruk's lifeless body with a smoldering hole the size of your fist.\n"
              << "You bend down and grab your gold.\n\n";
        }
        else if (fairyAmount == 0)
        {
         cout << "\t         You Have Died.\n"
              << "\t           Try Again.";
              return;
        }
              
    }
  }   
  else if (choice6 == "BARTER" || choice6 == "barter")
  {
    cout << "You offer him your " << startingGold << " gold.\n"
         << "“Is this all you have?” he snarls as he yanks your coinpurse out of your hand.\n"
         << "As he finishes counting the coin he nods his head, “Fine, for now”.\n"
         << "He releases his grip on you and you fall to the floor.\n"
         << "“But don't think for a second I'll let you off as easy next time.”\n"
         << "He walks through the town gates and into the the inn.\n\n";
  }
  else
  {
    cout << "“Is this all you have?” he snarls as he yanks your coinpurse out of your hand.\n"
         << "As he finishes counting the coin he nods his head, “Fine, for now”.\n"
         << "He releases his grip on you and you fall to the floor.\n"
         << "“But don't think for a second I'll let you off as easy next time.”\n"
         << "He walks through the town gates and into the the inn.\n\n";  
  }
    cout << "Hopefully that's the last of the surprises on this quest, you think to yourself.\n"
         << "“On to the temple.” you mutter to yourself. \n";
  
  outputFile << fairyAmount;
  outputFile.close();
   int Part2_choice;
   cout << "To continue to Part Two press 1 or press 2 to quit.\n";
   cin >> Part2_choice;
   while (Part2_choice > 2 || Part2_choice < 1)
   {
   cout << "Did a wizard cast a confusion spell on you?\n";
   cout << "Press 1 to continue your adventure or press 2 to quit.\n";
   cin >> Part2_choice;
   }
   if (Part2_choice == 1)
   {
       Part2_Function();
   }
   else if (Part2_choice == 2)
   {
    cout << "So long adventurer! The story waits for your return...\n";   
   }
  
   return;
}


/*****************************************
Part 2 function 
This function is the second part of the 
adventure. 
*****************************************/
void Part2_Function()
{
    
    string name;
    bool elf;
    bool barbarian;
    bool wizard;
    bool namechoice;
    int fairyAmount;
    //get data from file created in part 1
    ifstream inputFile("save.txt"); 
    getline(inputFile, name);
    inputFile >> elf;
    inputFile >> barbarian;
    inputFile >> wizard;
    inputFile >> namechoice;
    inputFile >> fairyAmount;
    
    string choice1, choice2, choice3;
    string puzzle1, puzzle2, puzzle3;
    string direction1;
    cout << "Warning Adventurer, only play this part if you played through part 1.\n\n\n";
    //cout << "Save Data\t You have " << fairyAmount << endl; 

    cout << "You arrive at the temple at sunfall. It is huge and magnificent, but\n";
    cout << "time has not been kind to it. You go straight to the front entrance.\n";
    cout << "On the door is four round stone markers. They look like they can be moved\n";
    cout << "Each of the four markers has an image: Owl, Snake, Rabbit, and a Carrot\n";
    cout << "There is a giant inscription next to the door.\n\n";
    cout << "\t |The third eats none while the second eats the third.|\n";
    cout << "\t |Once the second finishes its snack, it better watch |\n"; 
    cout << "\t |it's back, the fourth is always ready to attack.    |\n";
    cout << "\t |The first is not so demanding and will eat the      |\n";
    cout << "\t |second and fourth where they are standing.          |\n";
    cout << "\t |To cross this border, activate them in order.       |\n";
    cout << endl;
    cout << "You wonder to yourself if this old puzzle will still work..\n";
    cout << "It's worth a shot.\n";
    cout << "How will you order the four markers?\n";
    
    if (wizard == true)
    {
    cout << "You remember this puzzle from an old spellbook.\n"
         << "It's a spell casted at the door to make it unpenetrable unless you can solve it.\n"
         << "The order of the markers is owl then rabbit then carrot then snake.\n"
         << "The big door rolls to the side and you enter into the temple.\n";
    }
    else
    {
    cin.ignore();
    getline(cin, puzzle1);
    if (puzzle1 == "owl rabbit carrot snake")
     {
     cout << "You got it! The big door rolls to the side and you enter into the temple.\n\n"; 
     }
     else if (puzzle1 != "owl rabbit carrot snake")
     {
         cout << "The ground rumbles and shakes. Some stones fall around you.\n";
         cout << "You don't know how many more tries you have at this..\n";
         cout << "Hurry! Try again!\n";
        getline(cin, puzzle1);
        if (puzzle1 == "owl rabbit carrot snake")
    {
            cout << "You got it just in time.\n";
            cout << "Who knows what could have happened if you missed it again.\n";
            cout << "The big door rolls to the side and you enter the temple.\n\n";
    } 
    else if (puzzle1 != "owl rabbit carrot snake")
    {
         cout << "Oh no! Not again. You feel it, this is your last shot.\n";
         getline(cin, puzzle1);
         if (puzzle1 == "owl rabbit carrot snake")
         {
         cout << "The door is rolling to the side! Hurry and get in!\n";
         cout << "The entrance collapses behind you, you would've been crushed.\n";
         cout << "At least you're finally in the temple.\n\n";
         }
    else if (puzzle1 != "owl rabbit carrot snake" && fairyAmount > 0)
    {
         cout << "The ground rubles violently, you look up and see the entrance..\n";
         cout << "It's coming down, before you can even think..\n";
         cout << "A fairy pops out of a bottle in your bag and pulls you out of the way!\n"
              << "You would've been crushed if not for the fairy!\n"
              << "Well at least the door is open now.\n";
              fairyAmount--;
    }
     else if (puzzle1 != "owl rabbit carrot snake")
         {
         cout << "The ground rubles violently, you look up and see the entrance..\n";
         cout << "It's coming down, before you can even think..\n";
         cout << "\t         You Have Died.\n";
         cout << "\t           Try Again.";
         return ;
         }
    }
    }
    }
   
    cout << "\nThat was a close one. Hopefully the rest is easy.\n";
    cout << "You walk through the temple. You pass things that you can only\n";
    cout << "imagine what they were used for. Alchemy tables, soul binders, enchanted staves,\n";
    cout << "and blood ignitors litter the rooms. You walk until you see it, the library.\n\n";
    cout << "The room is two stories high and even more amazing is the stacks of books\n"; 
    cout << "that reach the ceiling.\n";
    cout << "“Which book could it be?” you wonder to yourself..";
    cout << "\nThen as if answering you, a book shoots out from a stack right into your stomach.\n";
    cout << "OOF! That was lucky, but what isn't lucky is the avalanche of books it brought with it.\n";
    cout << "You need to think quickly..Do you DODGE or do you RUN?\n";
    cin  >> choice1;
    if (choice1 == "DODGE" || choice1 == "dodge")
        {
            cout << "You notice just in time. You drop the book and roll out of the way!\n";
        }
    else if (choice1 == "RUN" || choice1 == "run")
    {
            cout << "You drop the book and run. A couple books fall on top of you\n";
            cout << "bringing you to the ground. You get up and dust yourself off.\n";
    }
    else
    {
        if (fairyAmount > 0)
        {
        cout << "You're too slow! The cascade of books crushes you.\n"
             << "You feel your broken bones as you try to move.\n"   
             << "Out of your bag comes a fairy, the pain starts leaving your body.\n"
             << "You're able to get up and dust yourself off.\n";
             fairyAmount--;
        }
        else
        {
            cout << "You're too slow! The cascade of books crushes you.\n";
            cout << "You feel your broken bones as you try to move.\n";
            cout << "\t         You Have Died.\n";
            cout << "\t           Try Again.";
         return ;
        }
    }
    cout << "You look around and wonder where in this mountain of books the tome \n";
    cout << "could be. As if answering you again the book shoots out of the fallen\n";
    cout << "stack of books and into your hands. The books rumbles and shakes as\n";
    cout << "you grab it. The book calls to you, it is alluring but causes fear in\n";
    cout << "your gut. Will fear stand in the way of power?\n";
    
  
        cout << "You give in and open the tome.\n";
        cout << "You are instantly transported to an ethereal realm.\n";
        cout << "You are have the feeling that you are rapidly falling.\n";
        cout << "As you are falling you see the world coming into view\n";
        cout << "You brace yourself for the coming inpact but you are sure\n";
        cout << "you will die. At the last second all of your speed stops and\n";
        cout << "you're dropped inches from the ground.\n\n";
        
        cout << "“This is my prison.” a voice says. “I am Zigurat. I am the\n"; 
        cout << "wizard who’s temple I assume you have defiled.” \n";
        cout << "His voice is booming and fills your ears. It almost knocks you\n"; 
        cout << "off your feet every time he speaks.\n";
        cout << "“I was trapped here in a spell gone awry.\n";
        if (elf == true)
        {
        cout << "“And you're an... elf archer? How original..”\n";
        cout << "“Well, if you wish to leave you will have to pass my test, proving that you are not some\n";
        cout << "little elf who stumbled upon my power.”\n\n";
        }
        else if (barbarian == true)
        {
        cout << "“And you're a... barbarian? Sadly, your strength won't help you here.”\n";
        cout << "“If you wish to leave you will have to pass my test, proving that you are not some\n";
        cout << "simple bandit who stumbled upon my power.”\n\n";    
        }
        else if (wizard == true)
        {
        cout << "“And you're a... wizard? No known spell can break you out of my prison.”\n";
        cout << "“If you wish to leave you will have to pass my test, proving that you are not some\n";
        cout << "no name conjurer who stumbled upon my power.”\n\n";   
        }
        cout << "“How do I leave then?” you shout. As soon as your sentence\n";
        cout << "is finished you are transported miles above the world you\n";
        cout << "were just on. It appears as if you are standing on thin air.\n";
        cout << "“Answer my riddle and you will be set free. Don’t and you\n";
        cout << "will perish like the rest of the inferiors that try my powers.”\n\n";
        cout << "“My riddle is this.. What walks on four legs in the morning,\n";
        cout << "two legs at noon, and three legs in the evening?”\n\n";
        
        if (elf == true)
        {
            cout << "You begin to laugh, harder and harder.\n"
                 << "“This is the best you have?” you say between laughs.\n"
                 << "“Enough! What is your answer?” The anger in Zigurat's voice is inescapable.\n"
                 << "“The answer of course is a human.” you declare.\n"
                 << "“In my village that wasn't a riddle. Instead it was told as a joke about \n" 
                 << "the frailty of humans.” you say with a final laugh.\n"
                 << "Zigurat yelps in anger “How dare you insult me! But I\n"
                 << "am true to my word. Step forward and I will set you free.”\n";
        }
        else 
        {
        cin.ignore();
        getline(cin, puzzle2);
        if (puzzle2 == "Old man" || puzzle2 == "old man" || puzzle2 == "man"
        || puzzle2 == "Man" || puzzle2 == "human" || puzzle2 == "Human")
        {
            cout << "Zigurat yelps in anger “Must have been a lucky guess! But I\n";
            cout << "am true to my word. Step forward and I will set you free.”\n";
        }
        else 
        {
            cout << "“Wrong!” Zigurat laughs a booming laugh. The floor you are\n";
            cout << "standing on gets smaller and smaller. Soon you are falling to\n";
            cout << "the world you saw before. And just like before you brace\n";
            cout << "yourself. Zigurat won’t be saving you this time. His maniacal\n";
            cout << "laugh is the last thing you hear before impact.\n";
            cout << "\t         You Have Died.\n";
            cout << "\t           Try Again.";
            return;
        }
        }
    
    cout << "You step forward and see his incoporeal body.\n";
    cout << "“Yes, the years in this realm have taken my body. Who knows \n";
    cout << "what I would be in the outside world.” Zigurat explains. “And \n";
    cout << "yes I can leave anytime I want, but why would I? I can perform \n";
    cout << "spells that are not possible in your world. In your world I would\n";
    cout << "work years on a spell that might not even work, in my world I \n";
    cout << "work years on a spell that might not even work, in my world I \n";
    cout << "“Enough! Just get me out of here.” you demand. \n";
    cout << "Zigurat is taken aback, “Yes, fine. Just promise me you’ll keep others \n";
    cout << "out of my realm. I imagine I won’t be so nice the next time someone  \n";
    cout << "bothers me from my work.” \n\n";
    
    cout << "As if nothing happened you are back in the temple.\n";
    cout << "You waste no time. You want to leave as soon as possible.\n";
    cout << "But first the gold. You go into the room that leads out of the library\n";
    cout << "In the next room you see it. It seems as if Nevar undersold Zigurat's wealth.\n";
    cout << "It is a mountain of gold, almost as tall as the stacks of books in the library\n";
    cout << "Yet as you get closer your stomach drops...\n";
    cout << "“No no no no NO!” you scream. \n";
    cout << "It seems that in Zigurat's paranoia he melted all of his riches into one.\n";
    cout << "You see the used fire staff next to the mound of gold. It would take\n";
    cout << "a full team of men to remove the gold. It's useless to you.\n";
    cout << "You pick up a sword and try to slash at the gold to break a chunk off but it's hopeless.\n";
    cout << "Light can be seen just behind the gold. That's your exit.\n";
    cout << "You follow the light and open the exit door. The floor behind you\n";
    cout << "crubles under your feet. You start to run as the temple collapses. \n";
    cout << "You see the outside world, you jump for it and just make it.\n";
    cout << "You look back to see an unrecognizable crater. It would take years\n";
    cout << "to find anything in whatever remains of the temple.\n";
    cout << "One last trick from the old wizard.\n\n";
    
    cout << "You let out an audible sigh. Before you can think you hear an elf's voice\n";
    if (namechoice == 1)
    {
        cout << "“Hello there, " << name << "! I'm glad you weren't in there!”\n";
        cout << "It's Nevar looking for his book.\n";
    }
    else if (namechoice == 0)
    {
        cout << "“Hello there, my mighty adventurer! I'm glad you weren't in there!”\n";
        cout << "It's Nevar looking for his book.\n";
    }
    
    cout << "“So did you get the book?” Nevar says with his ear to pointed ear grin\n";
    cout << "“Yeah I got the book but I need the reward.” you say angrily.\n";
    cout << "“Oh, was the gold not enough?” Nevar retorts.\n";
    cout << "“It was melted into one giant blob, I couldn’t even carry it.”\n";
    cout << "“Did I forget to mention that? I knew I was forgetting\n";
    cout << "something..” Nevar is teasing you now.\n";
    if (barbarian == true)
    {
    cout << "“You knew?” You say as you grab your sword. \n";
    cout << "“It may have been part of the myth. You were in such a hurry, \n";
    cout << "so I may have left out a few parts.” Nevar is enjoying this. \n";
    cout << "It was part of his trick from the beginning.\n";
    cout << "You swing your sword out of frustration. Nevar shoots you with \n";
    cout << "a bolt of electricity and you drop to your knees.\n";
    }
    else if (elf == true)
    {
    cout << "“You knew?” You say as you grab your bow. \n";
    cout << "“It may have been part of the myth. You were in such a hurry, \n";
    cout << "so I may have left out a few parts.” Nevar is enjoying this. \n";
    cout << "It was part of his trick from the beginning.\n";
    cout << "You loose an arrow out of frustration. Nevar doges and shoots you with \n";
    cout << "a bolt of electricity and you drop to your knees.\n";    
    }
    else if (wizard == true)
    {
    cout << "“You knew?” You say as your start to prepare your spell. \n";
    cout << "“It may have been part of the myth. You were in such a hurry, \n";
    cout << "so I may have left out a few parts.” Nevar is enjoying this. \n";
    cout << "It was part of his trick from the beginning.\n";
    cout << "The fire in your palm is fueled by your frustration. Nevar shoots you with \n";
    cout << "a bolt of electricity and you drop to your knees.\n";
    cout << "He's using ancient dark magic. Elcectric magic is the only instantaneous magic.\n";
    }
    cout << "You can't even stand. He's too stong for combat.\n";
    cout << "“Thank you for all your hard work but I’ll be going” Nevar \n";
    cout << "bends down and grabs the book.\n";
    cout << "You remember what the old wizard said about visitors..\n";
    //choice 3
    cout << "You can WARN Nevar or you can LET him read the tome.\n";
    cin >> choice3;
    if (choice3 == "WARN" || choice3 == "warn")
    {
        cout << "You yell out to him but your voice is not loud enough.\n";
        cout << "You're able to get out a “NO!” and Nevar turns his head over to you.\n";
        cout << "He opens the tome. “Thank you, truly. I couldn't have done it\n"; 
        cout << "withou-” he's cut short and the book drops to the floor the pages splayed out.\n";
        cout << "You crawl over to the book and can hear Nevar's scream. It disapears\n";
        cout << "as you close the tome.\n";
        cout << "You get up and throw the book in the crater that was once a temple.\n";
        cout << "Time to find a tavern..\n\n";
    }
    else if (choice3 == "LET" || choice3 == "let")
    {
        cout << "You smile at him as he starts to open the tome.\n"; 
        cout << "He's enjoying his triumph over you. “Thank you, truly. I couldn't have done it\n"; 
        cout << "withou-” he's cut short and the book drops to the floor the pages splayed out.\n";
        cout << "You can't help yourself and for the first time in a long time you laugh.\n";
        cout << "You laugh as you pick up the book and hear Nevar screaming.\n";
        cout << "You laugh as you throw the damned book into the ruined temple\n";
        cout << "You let out one last laugh as you look at the crater.\n";
        cout << "Time to find a tavern..\n\n";
    }
    else
    {
        cout << "You stare at him as he starts to open the tome.\n"; 
        cout << "He's enjoying his triumph over you. “Thank you, truly. I couldn't have done it\n"; 
        cout << "withou-” he's cut short and the book drops to the floor the pages splayed out.\n";
        cout << "You are so tired you close the book and throw it into the crater without a thought\n";
        cout << "Time to find a tavern..\n\n";
        
    }
    Credits_Function();
}


/*****************************************
Shop related functions 
This function is to make the shop work
*****************************************/
void Shop::initialGold(int g)
{
    gold = g;
    cout << "You have " << gold << " gold. ";
}
void Shop::transaction(int *g, int fairyAmount)
{
   int AmountToBeDeducted = fairyAmount * 50;
   cout << "“Okay that'll be " << AmountToBeDeducted << " gold” says the shopkeep.\n";
   *g -= AmountToBeDeducted;
}


/*****************************************
Credits function 
This function is the credits of the 
program.
*****************************************/
void Credits_Function()
{
cout << "\t      Code\n";
cout << "\t Josiah Rodriguez\n";
cout << "\t      Story\n";
cout << "\t Josiah Rodriguez\n";
}



