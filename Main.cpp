#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test");
	window.setFramerateLimit(60u);

	sf::RectangleShape rect(sf::Vector2f(70.f, 50.f));
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(100.f, 100.f);
	float speed = 5.f;
	float xspeed = speed;
	float yspeed = speed;
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		if (rect.getPosition().x <= 0.f)
		{
			xspeed = speed; rect.setFillColor(sf::Color::Red);
		}
		if (rect.getPosition().x >= (window.getSize().x - rect.getSize().x))
		{
			xspeed = -speed; rect.setFillColor(sf::Color::Green);
		}
		if (rect.getPosition().y <= 0.f)
		{
			yspeed = speed; rect.setFillColor(sf::Color::Yellow);
		}
		if (rect.getPosition().y >= (window.getSize().y - rect.getSize().y))
		{
			yspeed = -speed; rect.setFillColor(sf::Color::Blue);
		}
		rect.move(xspeed, yspeed);
		window.clear();
		window.draw(rect);
		window.display();
	}
	return 0;
}