#include <SFML/Graphics.hpp>
#include <vector>

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML Animation");

    // Load images into textures
    std::vector<sf::Texture> textures(3);
    textures[0].loadFromFile("photo/potato/1.png");
    textures[1].loadFromFile("photo/potato/3.png");
    textures[2].loadFromFile("photo/potato/5.png");
    

    // Create sprites from textures
    std::vector<sf::Sprite> sprites;
    for (auto& texture : textures) {
        sprites.push_back(sf::Sprite(texture));
    }

    // Set the initial sprite
    int currentSprite = 0;

    // Create a clock to manage animation timing
    sf::Clock clock;
    float frameDuration = 0.08f; // Duration of each frame in seconds

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear();

        // If enough time has passed, move to the next frame
        if (clock.getElapsedTime().asSeconds() > frameDuration) {
            currentSprite = (currentSprite + 1) % sprites.size();
            clock.restart();
        }

        // Draw the current frame
        window.draw(sprites[currentSprite]);

        // Update the window
        window.display();
    }

    return 0;
}