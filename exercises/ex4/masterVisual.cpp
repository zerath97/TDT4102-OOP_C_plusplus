#include "includes/masterVisual.h"
#include "includes/includes.h"
void addGuess(MastermindWindow &mwin, const string code, const int size, const char startLetter, const int round)
{

	int posX = 0;
	int posY = 0;
	unsigned int c = 0;

	for(unsigned int i = 0; i < code.length(); i++) {
		posX = 2*padX * i + padX;
		posY = 2*padY * round + 3*padY;
		switch(code[i]) {
			case 'A':
				c = 1;
				break;
			case 'B':
				c = 2;
				break;
			case 'C':
				c = 3;
				break;
			case 'D':
				c = 4;
				break;
			case 'E':
				c = 5;
				break;
			case 'F':
				c = 6;
				break;
		}
		mwin.vr.push_back(new Rectangle{Point{posX , posY}, padX, padY});
		mwin.vr[mwin.vr.size()-1].set_fill_color(c);
		mwin.attach(mwin.vr[mwin.vr.size()-1]);

	}
}
void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter, const int size,
				 const int round)
{

	int xPos = (2*size * padX) + padX;
	int yPos = (4*padY) + (padY * round) + 2*radCircle;

	for(int i = 0; i < size; i++) {
		Color circleColor = Color::invisible;
		xPos += 2*radCircle;
		mwin.vc.push_back(new Circle{Point{xPos, yPos}, radCircle});

		if(correctPosition > i) {
			circleColor = Color::black;

		}
		else if(correctCharacter > i){
			circleColor = Color::white;
		}

		mwin.vc[mwin.vc.size()-1].set_fill_color(circleColor);
		mwin.attach(mwin.vc[mwin.vc.size()-1]);
	}
}

void hideCode(MastermindWindow &mwin, const int size)
{
	mwin.vr.push_back(new Rectangle{Point{padX, 3 * padY}, winW - size * padX, padY});
	mwin.vr[mwin.vr.size() - 1].set_fill_color(Color::black);
	mwin.attach(mwin.vr[mwin.vr.size() - 1]);
}

MastermindWindow::MastermindWindow(Point xy, int w, int h, const string &title) : Window(xy, w, h, title),
																				  button_pressed{false},
																				  guessBtn{upperLeftCornerBtn, btnW, btnH, "Add", cb_guess},
																				  guess{upperLeftCornerInBox, inBoxW, inBoxH, "Guess"}
{
	attach(guess);
	attach(guessBtn);
};

string MastermindWindow::wait_for_guess()
{
	while (!button_pressed)
	{
		Fl::wait();
	}
	button_pressed = false;
	string newGuess = guess.get_string();
	guess.clear_value();
	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput)
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input[i];
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again\n";
		}
	}
	return guess;
}
