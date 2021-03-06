#include "Nav.hpp"

Nav::Nav(std::vector<std::pair<std::string, StateInt>> content, std::string pathToFont)
{
    float offsetWidth = (Settings()).getWidthWindow() / 2.5;
    float offsetHeight = (Settings()).getHeightWindow() / 3;
    const float stepHeight = (Settings()).getHeightWindow() / 10;

    for(auto const& [title, link] : content)
    {
        this->buttons.push_back(
            std::shared_ptr<Button>(
                new Button(
                    title,
                    link,
                    pathToFont,
                    30,
                    sf::Vector2f(offsetWidth, offsetHeight
                )
            )
        ));
        offsetHeight += stepHeight;
    }

    this->indexOfActiveButton = 0;
    this->buttons[this->indexOfActiveButton]->toggleActive();
}

std::shared_ptr<Button> Nav::getButton(u_int32_t index)
{
    return this->buttons[index];
}

u_int32_t Nav::getActive()
{
    return this->indexOfActiveButton;
}

void Nav::setActive(u_int32_t index)
{
    if(index < 0 || index >= this->buttons.size()) return;

    this->buttons[this->indexOfActiveButton]->toggleActive();
    this->indexOfActiveButton = index;
    this->buttons[this->indexOfActiveButton]->toggleActive();
}

std::vector<std::shared_ptr<Button>> Nav::getButtons()
{
    return this->buttons;
}