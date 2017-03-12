/// <summary>
/// @author Darren Sweeney
/// @version 1.0
/// </summary>

#ifndef PAUSE_SCREEN_H
#define PAUSE_SCREEN_H

#include "Screen.h"
#include "..\Input\XboxController.h"
#include "..\GUI\Gui.h"
#include "..\GUI\Button.h"

/// The pause screen that the player can back into
/// 
/// The pause screen handles all the update and render of the widgets
/// on screen
class PauseScreen
{
public:
	PauseScreen();
	~PauseScreen();

	void update();
	void render(sf::RenderWindow &window);
	void processInput(XboxController &controller);

private:
	Gui m_pauseScreenGUI;
	Label *m_pauseScreenLabel;
	Button *m_resumeButton;
	Button *m_optionsButton;
	Button *m_quitButton;
};

#endif