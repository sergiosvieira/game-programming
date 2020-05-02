#include <SFML/Graphics.hpp>
#include <functional>

using sf::RenderWindow,
    sf::VideoMode,
    sf::Event,
    sf::CircleShape,
    sf::RectangleShape,
    sf::Color,
    sf::Vector2f;

using Draw = std::function<void(RenderWindow&)>;

void loop(RenderWindow& window,
          Draw draw = nullptr) {
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        if (draw) draw(window);
        window.display();
    }
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Aula 02");
    CircleShape cshape(100);
    cshape.setFillColor(Color::Red);
    cshape.setPosition(100, 100);
    RectangleShape rshape(Vector2f{100.f, 100.f});
    rshape.setFillColor(Color::Blue);
    loop(window, [=](RenderWindow& rw){
        rw.draw(cshape);
        rw.draw(rshape);
    });
    return 0;
}
