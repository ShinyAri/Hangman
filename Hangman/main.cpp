#include <bits/stdc++.h>

using namespace std;

const int MAX_BAD_GUESSES = 7;

string WORD_LIST[] = {
        "angle", "ant", "apple", "arch", "arm", "army",
        "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
        "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
        "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
        "cake", "camera", "card",  "cart", "carriage", "cat", "chain", "cheese", "chest",
        "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
        "cow", "cup", "curtain", "cushion",
        "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
        "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
        "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
        "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
        "hospital", "house", "island", "jewel",  "kettle", "key", "knee", "knife", "knot",
        "leaf", "leg", "library", "line", "lip", "lock",
        "map", "match", "monkey", "moon", "mouth", "muscle",
        "nail", "neck", "needle", "nerve", "net", "nose", "nut",
        "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
        "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
        "rail", "rat", "receipt", "ring", "rod", "roof", "root",
        "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
        "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
        "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
        "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
        "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
        "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
    };
const string FIGURE[] = {
        "   -------------    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |           |    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          /     \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        " -----   \n"
    };

void clearScreen() {
    const int PATCH_LINES = 30;
	for (int i = 0; i < PATCH_LINES; i++) cout << endl;
}

void renderGame(const string& guessedWord, const string& badGuesses)
{
	clearScreen();
	int badGuessCount = badGuesses.length();
	cout << FIGURE[badGuessCount] << endl;
	cout << "Secret word: " << guessedWord << endl;
	if (badGuessCount > 0) {
		cout << "You've made " << badGuessCount << " wrong ";
		cout << (badGuessCount == 1 ? "guess" : "guesses");
		cout << ": " << badGuesses << endl;
	}
}

char readAGuess();
bool contains(const string& word, char guess);
void updateGuessedWord(string& guessedWord, const string& word, char guess);

void renderGame(const string& guessedWord, const string& badGuesses);
void displayFinalResult(bool won, const string& word);

const string& getNextDancingMan() {
    const static string figure[] = {
    "     O     \n"
    "    /|\\   \n"
    "    | |    \n",
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n",
    "   __O__   \n"
    "     |     \n"
    "    / \\   \n",
    "    \\O/   \n"
    "     |     \n"
    "    / \\   \n",
    "   __O__   \n"
    "     |     \n"
    "    / \\   \n",
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "    O      \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "      O    \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,


    };
    const static int NUMBER_OF_FIGURES = sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure++) % NUMBER_OF_FIGURES];
}

const string& getNextHangMan() {
    const static string figure[] = {
    "   ------------+    \n"
    "   |    /           \n"
    "   |    O      \n"
    "   |   /|\\    \n"
    "   |   / \\    \n"
    "   |        \n"
    " -----      \n" ,
    "   ------------+     \n"
    "   |     |           \n"
    "   |     O           \n"
    "   |    /|\\         \n"
    "   |    / \\         \n"
    "   |        \n"
    " -----      \n",
    "   ------------+     \n"
    "   |      \\         \n"
    "   |      O          \n"
    "   |     /|\\        \n"
    "   |     / \\        \n"
    "   |      \n"
    " -----    \n",
    "   ------------+     \n"
    "   |     |           \n"
    "   |     O           \n"
    "   |    /|\\         \n"
    "   |    / \\         \n"
    "   |        \n"
    " -----      \n"
    };
    const static int NUMBER_OF_FIGURES = sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure++) % NUMBER_OF_FIGURES];
}

void displayFinalResult(bool won, const string& word) {
    while (true) {
        clearScreen();
        if (won)
            cout << "Congratulations! You win!" << endl;
        else
            cout << "You lost. The correct word is " << word << endl;
        cout << (won ? getNextDancingMan() : getNextHangMan());
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int main()
{
	srand(time(0));
	int k=rand()%100+1;
	string word = WORD_LIST[k];
	if (word.length() < 1) {
		cout << "Error reading vocabulary file ";
		return -1;
	}
	string guessedWord = string(word.length(), '-');
	string badGuesses = "";

	do {
		renderGame(guessedWord, badGuesses);
		char guess = readAGuess();
		if (contains(word, guess))
			updateGuessedWord(guessedWord, word, guess);
		else {
			badGuesses += guess;
		}
	} while (badGuesses.length() < MAX_BAD_GUESSES && word != guessedWord);
    displayFinalResult(badGuesses.length() < MAX_BAD_GUESSES, word);

	return 0;
}

string getLowerCaseString(const string& s)
{
    string res = s;
    transform(s.begin(), s.end(), res.begin(), ::tolower);
    return res;
}

string chooseWord(const char* fileName)
{
	vector<string> wordList;
	ifstream file(fileName);
  	if (file.is_open()) {
	    string word;
		while (file >> word) {
            wordList.push_back(word);
        }
    	file.close();
  	}
  	if (wordList.size() > 0) {
  		int randomIndex = rand() % wordList.size();
    	return getLowerCaseString(wordList[randomIndex]);
	} else return "";
}

char readAGuess()
{
	char input;
	cout << "Your guess: ";
	cin >> input;
	return tolower(input);
}

bool contains(const string& word, char c)
{
	return (word.find_first_of(c) != string::npos);
}

void updateGuessedWord(string& guessedWord, const string& word, char guess)
{
	for (int i = word.length() - 1; i >= 0; i--) {
        if (word[i] == guess) {
            guessedWord[i] = guess;
        }
    }
}
