#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

// Window dimensions
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Paddle settings
const float PADDLE_WIDTH = 10.0f;
const float PADDLE_HEIGHT = 100.0f;
const float PADDLE_SPEED = 5.0f;

// Ball settings
const float BALL_RADIUS = 10.0f;
sf::Vector2f ballVelocity(4.0f, 4.0f);

int main() {
    // Create window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pong Game");
    window.setFramerateLimit(60);

    // Left Paddle
    sf::RectangleShape leftPaddle(sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT));
    leftPaddle.setPosition(10, (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2));

    // Right Paddle
    sf::RectangleShape rightPaddle(sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT));
    rightPaddle.setPosition(WINDOW_WIDTH - 20, (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2));

    // Ball
    sf::CircleShape ball(BALL_RADIUS);
    ball.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    // Game Loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Paddle movement (W/S for left, UP/DOWN for right)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && leftPaddle.getPosition().y > 0) {
            leftPaddle.move(0, -PADDLE_SPEED);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && leftPaddle.getPosition().y + PADDLE_HEIGHT < WINDOW_HEIGHT) {
            leftPaddle.move(0, PADDLE_SPEED);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && rightPaddle.getPosition().y > 0) {
            rightPaddle.move(0, -PADDLE_SPEED);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && rightPaddle.getPosition().y + PADDLE_HEIGHT < WINDOW_HEIGHT) {
            rightPaddle.move(0, PADDLE_SPEED);
        }

        // Move the ball
        ball.move(ballVelocity);

        // Ball collision with top and bottom walls
        if (ball.getPosition().y <= 0 || ball.getPosition().y + BALL_RADIUS * 2 >= WINDOW_HEIGHT) {
            ballVelocity.y = -ballVelocity.y;
        }

        // Ball collision with paddles
        if (ball.getGlobalBounds().intersects(leftPaddle.getGlobalBounds()) ||
            ball.getGlobalBounds().intersects(rightPaddle.getGlobalBounds())) {
            ballVelocity.x = -ballVelocity.x;
        }

        // Ball out of bounds (reset to center)
        if (ball.getPosition().x < 0 || ball.getPosition().x > WINDOW_WIDTH) {
            ball.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
            ballVelocity.x = -ballVelocity.x; // Change direction after reset
        }

        // Clear window
        window.clear(sf::Color::Black);

        // Draw objects
        window.draw(leftPaddle);
        window.draw(rightPaddle);
        window.draw(ball);

        // Display everything
        window.display();
    }

    return 0;
}
