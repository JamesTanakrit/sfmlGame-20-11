#include "Game.h"
#include "Menu.h"
#include "score.h"

float multiplier = 1;
int runScene = MenuScene;
vector<Event> textEvents;
ScoreData scoreData[6];

int main()
{
    RenderWindow window(VideoMode(1280, 960), "Game", Style::Titlebar | Style::Close);
    window.setVerticalSyncEnabled(true);

    srand(time(NULL));
    Game game;
    Menu menu;
    score score;
    
    while (window.isOpen())
    {
        textEvents.clear();
        Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == Event::Closed)
                window.close();
            else if (ev.type == Event::LostFocus)
            {
                multiplier = 0;
            }
            else if (ev.type == Event::GainedFocus)
            {
                multiplier = 1;
            }
            else if (ev.type == Event::TextEntered)
            {
                textEvents.push_back(ev);
            }
        }

        //update
        if (runScene == GameScene)
        {
            game.update(window);
        }
        else if (runScene == MenuScene)
        {
            menu.update(window);
        }
        else if (runScene == ScoreScene)
        {
            score.update(window);
        }
        window.clear();

        //render
        if (runScene == GameScene)
        {
            game.render(window);
            
        }
        else if (runScene == MenuScene)
        {
            menu.render(window);
        }
        else if (runScene == ScoreScene)
        {
            score.render(window);
        }
        window.display();
    }
    return 0;
}