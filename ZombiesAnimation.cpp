#include <SFML/Graphics.hpp>
#include <vector>

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Animation");

    // Load images into textures
    std::vector<sf::Texture> textures(19);
    textures[0].loadFromFile("photo/zombie/image1.png");
    textures[1].loadFromFile("photo/zombie/image3.png");
    textures[2].loadFromFile("photo/zombie/image5.png");
    textures[3].loadFromFile("photo/zombie/image7.png");
    textures[4].loadFromFile("photo/zombie/image9.png");
    textures[5].loadFromFile("photo/zombie/image11.png");
    textures[6].loadFromFile("photo/zombie/image13.png");
    textures[7].loadFromFile("photo/zombie/image15.png");
    textures[8].loadFromFile("photo/zombie/image17.png");
    textures[9].loadFromFile("photo/zombie/image19.png");
    textures[10].loadFromFile("photo/zombie/image21.png");
    textures[11].loadFromFile("photo/zombie/image22.png");
    textures[12].loadFromFile("photo/zombie/image23.png");
    textures[13].loadFromFile("photo/zombie/image24.png");
    textures[14].loadFromFile("photo/zombie/image25.png");
    textures[15].loadFromFile("photo/zombie/image26.png");
    textures[16].loadFromFile("photo/zombie/image27.png");
    textures[17].loadFromFile("photo/zombie/image28.png");
    textures[18].loadFromFile("photo/zombie/image30.png");

    // Create sprites from textures
    std::vector<sf::Sprite> sprites;
    for (auto& texture : textures) {
        sprites.push_back(sf::Sprite(texture));
    }

    // Set the initial sprite
    int currentSprite = 0;

    // Create a clock to manage animation timing
    sf::Clock clock;
    float frameDuration = 0.06f; // Duration of each frame in seconds

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