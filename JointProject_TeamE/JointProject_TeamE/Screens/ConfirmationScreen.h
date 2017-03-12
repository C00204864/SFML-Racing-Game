#ifndef CONFIRMATION_SCRREN_H
#ifndef CONFIRMATION_SCRREN_H
#define CONFIRMATION_SCRREN_H

#include "Screen.h"
#include "..\Input\XboxController.h"
#include "..\Gui\Gui.h"
#include "..\GUI\Button.h"

class ConfirmationScreen : Screen
{
public:
	ConfirmationScreen();
	~ConfirmationScreen();

	void update();
	void render(sf::RenderWindow &window);
	void processInput(XboxController &controller);

private:
	Gui m_helpScreenGUI;
	Label *m_areYouSureLabel;
	Button *m_yesButton;
	Button *m_noButton;
};


#endif