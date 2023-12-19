#include <bits/stdc++.h>
using namespace std;

void space(string matrix[4][4]) 
{
    cout <<"\t\t\t\t\t" << char(201);
    for (int i = 0; i < 10; i++) {
        cout << char(205);
    }
    cout << char(203);

    for (int i = 0; i < 10; i++) {
        cout << char(205);
    }
    cout << char(203);

    for (int i = 0; i < 10; i++) {
        cout << char(205);
    }
    cout << char(203);

    for (int i = 0; i < 10; i++) {
        cout << char(205);
    }
    cout << char(187);


    for (int i = 0; i < 4; i++) 
    {
        cout << endl;
        cout << "\t\t\t\t\t" << char(186);
        for (int j = 0; j < 4; j++) 
        {
            cout << matrix[i][j]  << char(186) ;
        }
        cout << endl;
        if (i != 3) 
        {
            cout<<"\t\t\t\t\t" << char(204);
            for (int i = 0; i < 10; i++) {
                cout << char(205);
            }
            cout << char(206);

            for (int i = 0; i < 10; i++) {
                cout << char(205);
            }
            cout << char(206);

            for (int i = 0; i < 10; i++) {
                cout << char(205);
            }
            cout << char(206);

            for (int i = 0; i < 10; i++) {
                cout << char(205);
            }
            cout << char(185);
        }
    }

    cout << "\t\t\t\t\t" << char(200);
    for (int i = 0; i < 10; i++) {
        cout << char(205);
    }
    cout << char(202);

    for (int i = 0; i < 10; i++) {
        cout << char(205);
    }
    cout << char(202);

    for (int i = 0; i < 10; i++) {
        cout << char(205);
    }
    cout << char(202);

    for (int i = 0; i < 10; i++) {
        cout << char(205);
    }
    cout << char(188);
}

//enter choice
int readNumber(int numChoice) {
    int num;
    do {
        if (numChoice == 1) {
            cout << "Please enter your first  choice : ";
        }
        else if (numChoice == 2) {
            cout << "Please enter your second choice : ";
        }
        cin >> num;
    } while (num < 1 || num>16);
    return num;
}

//remplir skills random
void readMatrixSkills(string matrixSkills[4][4], vector<string> skills) {
    srand(time(NULL));
    //rand() % (max - min +1)  + min
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
                int rad = rand() % skills.size() ;
                matrixSkills[i][j] = skills[rad];
                skills.erase(skills.begin() + (rad));
           
        }
    }
}

//recherche pos choice 1,choice 2
void PositionChoice(int choice1, int choice2, string matrix[4][4],int &l1,int &c1,int &l2,int &c2) {
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) {
            if (matrix[i][j] == "   Java   " || matrix[i][j] == "JavaScript" || matrix[i][j] == "   PhP    " || matrix[i][j] == "   Html   " || matrix[i][j] == "    Css   " || matrix[i][j] == "    C++   " || matrix[i][j] == "  Kotlin  " || matrix[i][j] == "   MySql  ")
                continue;
            if (stoi(matrix[i][j]) == choice1)
            {
                l1 = i;
                c1 = j;
            }
            else if (stoi(matrix[i][j]) == choice2)
            {
                l2 = i;
                c2 = j;
            }
        }
    }
}

int main()
{
    string matrix[4][4] = {
        {"    1     ","    2     ","    3     ","    4     "},
        {"    5     ","    6     ","    7     ","    8     "},
        {"    9     ","    10    ","    11    ","    12    "},
        {"    13    ","    14    ","    15    ","    16    "}
    };
    vector<string> skills{ "   Java   ", "   Java   ", "JavaScript", "JavaScript", "   PhP    ", "   PhP    ", "   Html   ", "   Html   ", "    Css   ", "    Css   ", "    C++   ", "    C++   ", "  Kotlin  ", "  Kotlin  ", "   MySql  ", "   MySql  " };
    string matrixSkills[4][4] ;
    readMatrixSkills(matrixSkills, skills);
    space(matrix);
    int trueTry = 0;
    int l1=0, c1=0, l2=0, c2=0;
    while (trueTry < 8)
    {
      cout << "\n\n"; int choice1 = readNumber(1);
      int choice2 = readNumber(2);
      cout << endl << endl;
      PositionChoice(choice1, choice2, matrix, l1, c1, l2, c2);
      if (matrixSkills[l1][c1] == matrixSkills[l2][c2]) 
      {
          system("cls");
          matrix[l1][c1] = matrixSkills[l1][c1];
          matrix[l2][c2] = matrixSkills[l2][c2];
          space(matrix);
          cout << "\n\ngood :)";
          system("color 2F");
          trueTry++;
      } 
      else 
      {
          system("cls");
          string oldWord1 = matrix[l1][c1];
          string oldWord2 = matrix[l2][c2];
          matrix[l1][c1]  = matrixSkills[l1][c1];
          matrix[l2][c2]  = matrixSkills[l2][c2];
          space(matrix);
          cout << "\n\nwrong :(\n\n";
          system("color 4F");
          matrix[l1][c1] = oldWord1;
          matrix[l2][c2] = oldWord2;
      }
      int choice;
      do {
          cout << "\nDo you want to play again ??\n";
          cout << "1 - yes\n";
          cout << "2 - no\n\n";
          cin >> choice;
      } while (choice != 1 && choice != 2);
      if (choice == 2) {
          system("cls");
          cout << "the right table\n\n";
          space(matrixSkills);
          cout << "\n\n\n\n";
          system("pause");
          break;
      }
      system("cls");
     

      space(matrix);
    }
    


}
