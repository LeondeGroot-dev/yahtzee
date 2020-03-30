#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>

#define SHOWSCORES_PURPOSE_SHOWSCORES   1
#define SHOWSCORES_PURPOSE_ENTEROPTIONS 2

#define FIELDNAME_1S                1
#define FIELDNAME_2S                2
#define FIELDNAME_3S                3
#define FIELDNAME_4S                4
#define FIELDNAME_5S                5
#define FIELDNAME_6S                6
#define FIELDNAME_BONUS             7
#define FIELDNAME_THREEOFAKIND      8
#define FIELDNAME_FOUROFAKIND       9
#define FIELDNAME_FULLHOUSE         10
#define FIELDNAME_SMALL_STRAIGHT    11
#define FIELDNAME_LARGE_STRAIGHT    12
#define FIELDNAME_YAHTZEE           13
#define FIELDNAME_CHANCE            14

using namespace std;

std::sort(Die, Die+6);

int FieldScore(int Field, int nPlayer);

void ShowScoresUpperSection(int nPlayer, int Purpose);
void ShowScoresLowerSection(int nPlayer, int Purpose);
void ShowDice();
void RollDice(char* DiceToRoll);
void EnterScore();
int Die[5];
int ScoreField[14][10]; // For max 10 player

const string FieldName[16][14] = {
    "1's             ",
    "2's             ",
    "3's             ",
    "4's             ",
    "5's             ",
    "6's             ",
    "Bonus           ",
    "Three-of-a-kind ",
    "Four-of-a-kind  ",
    "Full House      ",
    "Small straight  ",
    "Large straight  ",
    "Yahtzee         ",
    "Chance          "
};

int main() {

    int noPlayers;
    int noTimesRolled;

    cout << "Enter number of players" << endl;
    cin >> noPlayers;

    for( int turn = 0; turn < 14; turn++ ) {
        for( int player = 0; player < noPlayers; player++ ) {
            cout << player << endl;
            while( noTimesRolled < 3 ) {
                noTimesRolled++;
                cout << noTimesRolled;

                cout << "Player " << player << "'s turn" << endl;
                cout << "Pick an option: " << endl
                    << "1) Show upper scorefields" << endl
                    << "2) Show lower scorefields" << endl
                    << "3) Show dice" << endl
                    << "4) (Re)roll dice" << endl
                    << "5) Enter score" << endl
                    << "6) End turn" << endl;

                char cOption;
                cin >> cOption;

                if( cOption == '1' ) {
                    ShowScoresUpperSection(player, SHOWSCORES_PURPOSE_SHOWSCORES);
                }

                if( cOption == '2' ) {
                    ShowScoresLowerSection(player, SHOWSCORES_PURPOSE_SHOWSCORES);
                }

                if( cOption == '3' ) {
                    ShowDice();
                }

                if( cOption == '4' ) {
                    char* DiceToRoll;
                    cout << "Enter dice to roll in this way: 124 rolling dice 1, 2 and 4" << endl;
                    cin >> DiceToRoll;
                    RollDice(DiceToRoll);
                }

                if( cOption == '5' ) {
                    ShowScoresUpperSection(player, SHOWSCORES_PURPOSE_ENTEROPTIONS);
                    ShowScoresLowerSection(player, SHOWSCORES_PURPOSE_ENTEROPTIONS);
                }

                if( cOption == '5' ) {
                    ShowScoresUpperSection(player, SHOWSCORES_PURPOSE_ENTEROPTIONS);
                    ShowScoresLowerSection(player, SHOWSCORES_PURPOSE_ENTEROPTIONS);
                }

                if( cOption == '7' ) {
                    continue;
                }


            }
        }
    }
}

int FieldScore(int nField, int nPlayer) {

    int Score = 0;
/*
    struct dieset {
        int value;
        int location;
    }

    dieset sortedDie[5];

    for( int val = 1; val <= 6; val++ ) {
        for( d = 0; d < 5; d++ ) {
            if( Die[d] == val ) {

                sortedDie[d2].value = val;
                sortedDie[d2].location = 0;

            }
        }
    }

    int SortedDice[6][5]; // value | nodice

    struct dieset {
        int value;
        int start;
    };

    dieset SortedDice[5];

    for( int die_n = 0; die_n < 5; die_n++ ) {

    }

    // Nog niet klaar

   */

    switch(nField) {

        case FIELDNAME_1S:
            Score = 0;
            for(int n; n < 5; n++) {
                if( Die[n] == 1 ) {
                    Score += 1;
                }
            }
            break;

        case FIELDNAME_2S:
            Score = 0;
            for(int n; n < 5; n++) {
                if( Die[n] == 2 ) {
                    Score += 2;
                }
            }
            break;

        case FIELDNAME_3S:
            Score = 0;
            for(int n; n < 5; n++) {
                if( Die[n] == 3 ) {
                    Score += 3;
                }
            }
            break;

        case FIELDNAME_4S:
            Score = 0;
            for(int n; n < 5; n++) {
                if( Die[n] == 4 ) {
                    Score += 4;
                }
            }
            break;

        case FIELDNAME_5S:
            Score = 0;
            for(int n; n < 5; n++) {
                if( Die[n] == 5 ) {
                    Score += 5;
                }
            }
            break;

        case FIELDNAME_6S:
            Score = 0;
            for(int n; n < 5; n++) {
                if( Die[n] == 6 ) {
                    Score += 6;
                }
            }
            break;

        case FIELDNAME_BONUS:
            if(     ScoreField[0][nPlayer] > 0 &&
                    ScoreField[1][nPlayer] > 0 &&
                    ScoreField[2][nPlayer] > 0 &&
                    ScoreField[3][nPlayer] > 0 &&
                    ScoreField[4][nPlayer] > 0 &&
                    ScoreField[5][nPlayer] > 0 &&
                    ScoreField[0][nPlayer] +
                    ScoreField[1][nPlayer] +
                    ScoreField[2][nPlayer] +
                    ScoreField[3][nPlayer] +
                    ScoreField[4][nPlayer] +
                    ScoreField[5][nPlayer]
                    >= 63 ) {
                        Score = 35;
                }
                break;

        case FIELDNAME_THREEOFAKIND:

            if( Die[0] == Die[1] && Die[0] == Die[2] ||
                Die[0] == Die[1] && Die[0] == Die[3] ||
                Die[0] == Die[1] && Die[0] == Die[4] ||

                Die[1] == Die[2] && Die[1] == Die[3] ||
                Die[1] == Die[2] && Die[1] == Die[4] ||

                Die[2] == Die[3] && Die[2] == Die[4] ) {
                Score = Die[0] + Die[1] + Die[2] + Die[3] + Die[4];

            }
            break;

    }
    return Score;
}


void ShowScoresUpperSection(int nPlayer, int Purpose) {
    if(Purpose == SHOWSCORES_PURPOSE_SHOWSCORES) {
        for( int n = 0; n < 7; n++ ) {
            cout << FieldName[0][n] << ScoreField[n][nPlayer] <<  endl;
        }
        cout << endl;
    }
    else if(Purpose == SHOWSCORES_PURPOSE_ENTEROPTIONS) {
        for( int n = 0; n < 7; n++ ) {
            cout << FieldName[0][n] << ScoreField[n][nPlayer] <<  endl;
        }
        cout << endl;
    }
    return;
}
void ShowScoresLowerSection(int nPlayer, int Purpose) {
    if( Purpose == SHOWSCORES_PURPOSE_SHOWSCORES ) {
        for( int n = 7; n < 13; n++ ) {
            cout << FieldName[0][n] << ScoreField[n][nPlayer] <<  endl;
        }
        cout << endl;
    }
    else if(Purpose == SHOWSCORES_PURPOSE_ENTEROPTIONS) {
        for( int n = 7; n < 13; n++ ) {
            cout << FieldName[0][n] << ScoreField[n][nPlayer] <<  endl;
        }
        cout << endl;
    }
    return;
}

void ShowDice() {
    cout << Die[0] << " " << Die[1]<< " " << Die[2] << " " << Die[3] << " " << Die[5] << endl;
    return;
}

void RollDice(char* DiceToRoll) {
    for( int n = 0; n < 5; n++ ) {
        Die[n] = (rand()%6)+1;
    }
 }

void EnterScore() {

}
