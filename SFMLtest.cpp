#include <SFML/Graphics.hpp>
struct Object

    {
    float x, y, vx, vy;
    };

void Move (Object* m, int r, int dt);

int main()

    {

    sf::RenderWindow window(sf::VideoMode(1500, 900), "SFML works!");

    int dt = 2;
    int r = 10;

    Object m = {100, 200, 1/5.0, 1/4.0};

    sf::CircleShape shape(r);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())

        {

        sf::Event event;
        while (window.pollEvent(event))
            {
            if (event.type == sf::Event::Closed)
                window.close();
            }

        printf (".");

        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) vx++;
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) vx--;
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) vx = 0;
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) vx = 0;

        Move (&m, 10, 1);


        shape.setPosition (m.x, m.y);

        window.clear();
        window.draw(shape);
        window.display();

        }

    return 0;

    }

void Move (Object* m, int r, int dt)

    {
    (*m).x = (*m).x + (*m).vx*dt;
    (*m).y = (*m).y + (*m).vy*dt;

    if ((*m).x >= 1500 - r)

        {
        (*m).vx = -(*m).vx;
        (*m).x = 1500 - r;
        }

    if ((*m).x <= 0)

        {
        (*m).vx = -(*m).vx;
        (*m).x = 0;
        }

    if ((*m).y >= 900 - r)

        {
        (*m).vy = -(*m).vy;
        (*m).y = 900 - r;
        }

    if ((*m).y <= 0)

        {
        (*m).vy = -(*m).vy;
        (*m).y = 0;
        }


    }


