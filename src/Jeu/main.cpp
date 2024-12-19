#include "pch.h"
#include "main.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "projectil.h"
#include "Scene.h"
#include "collidable.h"
#include "Poop.h"
#include "Heart.h"
#include "Enemy.h"
#include "Patate.h"
#include "ProjectileEnemy.h"
#include "objet.h"

sf::Vector2f normalize(const sf::Vector2f& vector) {
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    if (magnitude == 0) {
        return sf::Vector2f(0.f, 0.f); // Return zero vector if magnitude is zero
    }
    return sf::Vector2f(vector.x / magnitude, vector.y / magnitude);
}

int main()
{
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif

    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Escape From Lucy");

    sf::Music music;
    music.openFromFile("../../../src/Jeu/music.wav");

    music.setLoop(true);
    music.setVolume(50.f);
    music.play();

    std::vector<sf::RectangleShape> walls;
    std::vector<sf::RectangleShape> doors;
    std::vector<sf::RectangleShape> other;

    sf::RectangleShape wall1(sf::Vector2f(50, 200));
    wall1.setFillColor(sf::Color(255, 255, 255, 0)); // rend transparent
    wall1.setPosition(80, 190);
    wall1.setScale(3, 3);
    walls.push_back(wall1);

    sf::RectangleShape wall2(sf::Vector2f(360, 50));
    wall2.setFillColor(sf::Color(255, 255, 255, 0));
    wall2.setPosition(250, -20);
    wall2.setScale(3, 3);
    walls.push_back(wall2);

    sf::RectangleShape wall3(sf::Vector2f(50, 200));
    wall3.setFillColor(sf::Color(255, 255, 255, 0));
    wall3.setPosition(1350, 180);
    wall3.setScale(3, 3);
    walls.push_back(wall3);

    sf::RectangleShape wall4(sf::Vector2f(360, 50));
    wall4.setFillColor(sf::Color(255, 255, 255, 0));
    wall4.setPosition(250, 780);
    wall4.setScale(3, 3);
    walls.push_back(wall4);   

    sf::RectangleShape door1(sf::Vector2f(60, 20));
    door1.setFillColor(sf::Color(255, 255, 255, 0));
    door1.setPosition(80, 440);
    door1.setScale(3, 3);
    doors.push_back(door1);

    sf::RectangleShape door2(sf::Vector2f(40, 60));
    door2.setFillColor(sf::Color(255, 255, 255, 0));
    door2.setPosition(720, -40);
    door2.setScale(3, 3);
    doors.push_back(door2);

    sf::RectangleShape door3(sf::Vector2f(60, 20));
    door3.setFillColor(sf::Color(255, 255, 255, 0));
    door3.setPosition(1330, 440);
    door3.setScale(3, 3);
    doors.push_back(door3);

    sf::RectangleShape door4(sf::Vector2f(40, 60));
    door4.setFillColor(sf::Color(255, 255, 255, 0));
    door4.setPosition(720, 780);
    door4.setScale(3, 3);
    doors.push_back(door4);

    sf::RectangleShape shopik(sf::Vector2f(80, 15));
    shopik.setFillColor(sf::Color(255, 255, 255, 0));
    shopik.setPosition(670, 460);
    shopik.setScale(3, 3);
    other.push_back(shopik);

    sf::RectangleShape HangingMan(sf::Vector2f(30, 55));
    HangingMan.setFillColor(sf::Color(255, 255, 255, 0));
    HangingMan.setPosition(760, 100);
    HangingMan.setScale(3, 3);
    other.push_back(HangingMan);

    sf::RectangleShape letter(sf::Vector2f(50, 50));
    letter.setFillColor(sf::Color(255, 255, 255, 150));
    letter.setPosition(700, 550);
    letter.setScale(3, 3);
    other.push_back(letter);

    sf::Font font;

    if (!font.loadFromFile("../../../src/Jeu/png/font.ttf"))
    {
        return -1;
    }

    sf::Text start;
    sf::Text jouer;
    sf::Text options;
    sf::Text aide;
    sf::Text credits;
    sf::Text quit;
    sf::Text txtgo;


    Player player;
    Scene scene;
    Heart heart;
    Patate patate;
    Objet object;


    std::vector<projectil*> projectiles;
    std::vector<ProjectileEnemy*> proenemy;

    std::vector<Poop*> enemyPoop;
    Poop* Poop1 = new Poop();
    enemyPoop.push_back(Poop1);

    std::vector<Patate*> enemyPatate;
    Patate* Patate1 = new Patate();
    enemyPatate.push_back(Patate1);
    Patate* Patate2 = new Patate();
    Patate2->setPosition(900, 300);
    enemyPatate.push_back(Patate2);


    sf::Clock clock;
    sf::Clock endLarme;
    sf::Clock moveEnemyClock;
    sf::Clock enemyShootClock;
    sf::Clock invincibilityClock;
    sf::Time invincibilityDuration = sf::seconds(2);

    float frameDuration = 0.1f;
    float speedLarme = 500.f;
    float enemyShootInterval = 2.f;

    int currentFrame = 0;
    int currentFrameLarme = 0;
    int currentRoom = 5;

    int totalRoom;
    int totalFramesLarme;
    int totalFrames;
    
    int totalObjet;
    int currentitem;

    float timeSinceLastShot = 0.0f; // Temps écoulé depuis le dernier tir
    float fireInterval = 0.5f;

    bool poopIsDead = false;
    bool takeDamage = false;
    bool isPaused = false;
    bool shopikCollide = false;

    bool itemCoin = false;
    bool itemKey = false;

    std::map<sf::Keyboard::Key, float> fireTimers = {
        {sf::Keyboard::Up, 0.f},
        {sf::Keyboard::Down, 0.f},
        {sf::Keyboard::Left, 0.f},
        {sf::Keyboard::Right, 0.f},
    };

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                isPaused = !isPaused;
            }
        }

        if (!isPaused)
        {
            float deltaTime = endLarme.restart().asSeconds();
            timeSinceLastShot += deltaTime;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !player.WallCollision(wall3, player.Bounds(player.spritePlayer)))//1200
            {
                const auto& currentSheets = player.sheetsRight;
                totalFrames = currentSheets.size();

                if (clock.getElapsedTime().asSeconds() > frameDuration)
                {
                    currentFrame = (currentFrame + 1) % totalFrames;
                    player.spritePlayer.setTexture(*currentSheets[currentFrame]);
                    clock.restart();
                }
                //std::cout << player.getPosition().x << player.getPosition().y << std::endl;
                player.move(0.5f, 0.f);
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !player.WallCollision(wall1, player.Bounds(player.spritePlayer)))//150
            {
                const auto& currentSheets = player.sheetsLeft;
                totalFrames = currentSheets.size();

                if (clock.getElapsedTime().asSeconds() > frameDuration)
                {
                    currentFrame = (currentFrame + 1) % totalFrames;
                    player.spritePlayer.setTexture(*currentSheets[currentFrame]);
                    clock.restart();
                }
                //std::cout << player.getPosition().x << player.getPosition().y << std::endl;

                player.move(-0.5f, 0.f);
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !player.WallCollision(wall4, player.Bounds(player.spritePlayer)))//530
            {
                const auto& currentSheets = player.sheetsDown;
                totalFrames = currentSheets.size();

                if (clock.getElapsedTime().asSeconds() > frameDuration)
                {
                    currentFrame = (currentFrame + 1) % totalFrames;
                    player.spritePlayer.setTexture(*currentSheets[currentFrame]);
                    clock.restart();
                }
                //std::cout << player.getPosition().x << player.getPosition().y << std::endl;

                player.move(0.f, 0.5f);
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !player.WallCollision(wall2, player.Bounds(player.spritePlayer)))//60
            {
                const auto& currentSheets = player.sheetsUP;
                totalFrames = currentSheets.size();

                if (clock.getElapsedTime().asSeconds() > frameDuration)
                {
                    currentFrame = (currentFrame + 1) % totalFrames;
                    player.spritePlayer.setTexture(*currentSheets[currentFrame]);
                    clock.restart();
                }
                //std::cout << player.getPosition().x << player.getPosition().y << std::endl;

                player.move(0.f, -0.5f);
            }

            else if (event.type == sf::Event::KeyReleased)
            {
                player.spritePlayer.setTexture(player.texturePause1);
            }
            //std::cout << player.getPosition().x << " " << player.getPosition().y << std::endl;



            for (auto& timer : fireTimers)
            {
                timer.second += deltaTime;
            }

            // Gestion des tirs continus
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && fireTimers[sf::Keyboard::Up] >= fireInterval)
            {
                projectil* newProjectile = new projectil();
                newProjectile->setPosition(player.getPosition());

                if (itemCoin)
                {
                    newProjectile->spriteLarmeBase.setTexture(newProjectile->BlackLarme);
                }

                newProjectile->direction = sf::Vector2f(0.f, -1.f); // Direction haut
                projectiles.push_back(newProjectile);
                fireTimers[sf::Keyboard::Up] = 0.f;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && fireTimers[sf::Keyboard::Down] >= fireInterval)
            {
                projectil* newProjectile = new projectil();
                newProjectile->setPosition(player.getPosition());

                if (itemCoin)
                {
                    newProjectile->spriteLarmeBase.setTexture(newProjectile->BlackLarme);
                }

                newProjectile->direction = sf::Vector2f(0.f, 1.f); // Direction bas
                projectiles.push_back(newProjectile);
                fireTimers[sf::Keyboard::Down] = 0.f;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && fireTimers[sf::Keyboard::Left] >= fireInterval)
            {
                projectil* newProjectile = new projectil();
                newProjectile->setPosition(player.getPosition());
                
                if (itemCoin)
                {
                    newProjectile->spriteLarmeBase.setTexture(newProjectile->BlackLarme);
                }

                newProjectile->direction = sf::Vector2f(-1.f, 0.f); // Direction gauche
                projectiles.push_back(newProjectile);
                fireTimers[sf::Keyboard::Left] = 0.f;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && fireTimers[sf::Keyboard::Right] >= fireInterval)
            {
                projectil* newProjectile = new projectil();
                newProjectile->setPosition(player.getPosition());

                if (itemCoin)
                {
                    newProjectile->spriteLarmeBase.setTexture(newProjectile->BlackLarme);
                }

                newProjectile->direction = sf::Vector2f(1.f, 0.f); // Direction droite
                projectiles.push_back(newProjectile);
                fireTimers[sf::Keyboard::Right] = 0.f;
            }

            for (auto& proj : projectiles)
            {
                if (!proj->WallCollision(wall1, proj->Bounds(proj->spriteLarmeBase)) && !proj->WallCollision(wall2, proj->Bounds(proj->spriteLarmeBase)) && !proj->WallCollision(wall3, proj->Bounds(proj->spriteLarmeBase)) && !proj->WallCollision(wall4, proj->Bounds(proj->spriteLarmeBase)))
                {
                    proj->move(deltaTime, speedLarme);
                }
            }

            for (auto it = projectiles.begin(); it != projectiles.end(); )
            {
                bool collisionDetected = false;
                // Vérifier la collision avec chaque mur (ou autre objet)
                for (auto& wall : walls)
                {
                    if (player.WallCollision(wall, (*it)->Bounds((*it)->spriteLarmeBase)))
                    {
                        collisionDetected = true;
                        break;  // On arrête dès qu'une collision est trouvée
                    }
                }

                // Si une collision a été détectée, on supprime le projectile du vecteur
                if (collisionDetected)
                {
                    it = projectiles.erase(it);  // Supprimer le projectile
                }
                else
                {
                    ++it;  // Passer au projectile suivant si pas de collision
                }
            }

            if (currentRoom == 5)
            {

                scene.room.setPosition(400, 50);
                scene.room.setScale(0.8, 0.8);
                scene.room.setTextureRect(sf::IntRect(0, 0, 1024, 1024));

                start.setFont(font);
                start.setString("Cliquez sur n'importe quel bouton de la souris pour commencer.");
                start.setCharacterSize(45);
                start.setFillColor(sf::Color::Red);
                start.setPosition(0, 900);

                if (event.type == sf::Event::MouseButtonPressed)
                {
                    const auto& currentSheetsRoom = scene.sheetsRoom;
                    totalRoom = currentSheetsRoom.size();
                    currentRoom = 6;
                    scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                }
            }

            if (currentRoom == 6)
            {
                scene.room.setPosition(0, 100);
                scene.room.setScale(3, 3);
                scene.room.setTextureRect(sf::IntRect(0, 0, 510, 596));

                jouer.setFont(font);
                jouer.setString("Jouer");
                jouer.setCharacterSize(60);
                jouer.setFillColor(sf::Color::White);
                jouer.setPosition(670, 625);

                options.setFont(font);
                options.setString("Options");
                options.setCharacterSize(60);
                options.setFillColor(sf::Color::White);
                options.setPosition(630, 700);

                aide.setFont(font);
                aide.setString("aide");
                aide.setCharacterSize(60);
                aide.setFillColor(sf::Color::White);
                aide.setPosition(690, 775);

                credits.setFont(font);
                credits.setString("Credits");
                credits.setCharacterSize(60);
                credits.setFillColor(sf::Color::White);
                credits.setPosition(630, 850);

                quit.setFont(font);
                quit.setString("Quitter");
                quit.setCharacterSize(60);
                quit.setFillColor(sf::Color::White);
                quit.setPosition(630, 925);

                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        sf::FloatRect jouerBounds = jouer.getGlobalBounds();
                        sf::FloatRect optionsBounds = options.getGlobalBounds();
                        sf::FloatRect aideBounds = aide.getGlobalBounds();
                        sf::FloatRect creditsBounds = credits.getGlobalBounds();
                        sf::FloatRect quitBounds = quit.getGlobalBounds();

                        if (jouerBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                        {
                            const auto& currentSheetsRoom = scene.sheetsRoom;
                            totalRoom = currentSheetsRoom.size();
                            currentRoom = 0;
                            scene.room.setTexture(*currentSheetsRoom[currentRoom]);

                            scene.room.setPosition(100, 25);
                            scene.room.setTextureRect(sf::IntRect(0, 0, 460, 305));
                            scene.room.setScale(3, 3);
                        }
                        else if (optionsBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                        {
                            const auto& currentSheetsRoom = scene.sheetsRoom;
                            totalRoom = currentSheetsRoom.size();
                            currentRoom = 9;
                            scene.room.setTexture(*currentSheetsRoom[currentRoom]);

                            scene.room.setPosition(400, 150);
                            scene.room.setTextureRect(sf::IntRect(0, 0, 239, 229));
                            scene.room.setScale(3, 3);
                        }
                        else if (aideBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                        {
                            const auto& currentSheetsRoom = scene.sheetsRoom;
                            totalRoom = currentSheetsRoom.size();
                            currentRoom = 7;
                            scene.room.setTexture(*currentSheetsRoom[currentRoom]);

                            scene.room.setPosition(400, 150);
                            scene.room.setTextureRect(sf::IntRect(0, 0, 239, 229));
                            scene.room.setScale(3, 3);

                        }
                        else if (creditsBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                        {
                            const auto& currentSheetsRoom = scene.sheetsRoom;
                            totalRoom = currentSheetsRoom.size();
                            currentRoom = 10;
                            scene.room.setTexture(*currentSheetsRoom[currentRoom]);

                            scene.room.setPosition(400, 150);
                            scene.room.setTextureRect(sf::IntRect(0, 0, 239, 229));
                            scene.room.setScale(3, 3);
                        }
                        else if (quitBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                        {
                            return -1;
                        }
                    }
                }
            }

            float delta = moveEnemyClock.restart().asSeconds();
            sf::Vector2f directionPoop = normalize(player.getPosition() - Poop1->getPosition());

            sf::Vector2f directionPatate1 = normalize(player.getPosition() - Patate1->getPosition());
            sf::Vector2f directionPatate2 = normalize(player.getPosition() - Patate2->getPosition());

            if (currentRoom == 0)
            {
                if (player.DoorsCollision(door1, player.Bounds(player.spritePlayer)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                {
                    const auto& currentSheetsRoom = scene.sheetsRoom;
                    totalRoom = currentSheetsRoom.size();
                    currentRoom = 1;
                    player.setPosition(door3.getPosition());

                    scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                    player.Bounds(player.spritePlayer) = player.spritePlayer.getGlobalBounds();

                    player.Bounds(player.spritePlayer) = player.getTransform().transformRect(player.Bounds(player.spritePlayer));
                    for (auto it = projectiles.begin(); it != projectiles.end(); )
                    {
                        it = projectiles.erase(it);
                    }
                }
                else if (player.DoorsCollision(door2, player.Bounds(player.spritePlayer)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && itemKey)
                {
                    const auto& currentSheetsRoom = scene.sheetsRoom;
                    totalRoom = currentSheetsRoom.size();
                    currentRoom = 3;

                    player.setPosition(door4.getPosition().x + 70, door4.getPosition().y - 40);
                    scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                    player.Bounds(player.spritePlayer) = player.spritePlayer.getGlobalBounds();

                    player.Bounds(player.spritePlayer) = player.getTransform().transformRect(player.Bounds(player.spritePlayer));
                    for (auto it = projectiles.begin(); it != projectiles.end(); )
                    {
                        it = projectiles.erase(it);
                    }
                }
                else if (player.DoorsCollision(door3, player.Bounds(player.spritePlayer)) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    const auto& currentSheetsRoom = scene.sheetsRoom;
                    totalRoom = currentSheetsRoom.size();

                    player.setPosition(door1.getPosition().x + 180, door1.getPosition().y);
                    currentRoom = 2;
                    scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                    player.Bounds(player.spritePlayer) = player.spritePlayer.getGlobalBounds();

                    player.Bounds(player.spritePlayer) = player.getTransform().transformRect(player.Bounds(player.spritePlayer));
                    for (auto it = projectiles.begin(); it != projectiles.end(); )
                    {
                        it = projectiles.erase(it);
                    }
                }
            }

            else if (currentRoom == 1)
            {
                if (player.DoorsCollision(door3, player.Bounds(player.spritePlayer)) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    const auto& currentSheetsRoom = scene.sheetsRoom;
                    totalRoom = currentSheetsRoom.size();
                    currentRoom = 0;

                    player.setPosition(door1.getPosition().x + 180, door1.getPosition().y);
                    scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                    player.Bounds(player.spritePlayer) = player.spritePlayer.getGlobalBounds();

                    player.Bounds(player.spritePlayer) = player.getTransform().transformRect(player.Bounds(player.spritePlayer));
                    for (auto it = projectiles.begin(); it != projectiles.end(); )
                    {
                        it = projectiles.erase(it);
                    }
                }

                Poop1->move(delta * Poop1->speedEnemy * directionPoop.x, delta * Poop1->speedEnemy * directionPoop.y);

                if (Poop1->collideSprite(Poop1->Bounds(Poop1->spritePoop), player.Bounds(player.spritePlayer)))
                {
                    if (!takeDamage) {
                        // Le joueur perd de la vie
                        player.mCurrentHealth -= Poop1->mAttack;

                        // Activer l'invincibilité
                        takeDamage = true;
                        invincibilityClock.restart();
                    }

                    if (takeDamage && invincibilityClock.getElapsedTime() > invincibilityDuration) {
                        takeDamage = false; // Fin de l'invincibilité
                    }
                }

                for (auto it = projectiles.begin(); it != projectiles.end();)
                {
                    if ((*it)->Bounds((*it)->spriteLarmeBase).intersects(Poop1->Bounds(Poop1->spritePoop)))
                    {
                        if ((*it)->direction.x > 0)
                        {
                            Poop1->setPosition(Poop1->getPosition().x + 30, Poop1->getPosition().y);
                        }
                        else if ((*it)->direction.x < 0)
                        {
                            Poop1->setPosition(Poop1->getPosition().x - 30, Poop1->getPosition().y);
                        }
                        else if ((*it)->direction.y > 0)
                        {
                            Poop1->setPosition(Poop1->getPosition().x, Poop1->getPosition().y + 30);
                        }
                        else if ((*it)->direction.y < 0)
                        {
                            Poop1->setPosition(Poop1->getPosition().x, Poop1->getPosition().y - 30);
                        }

                        // Collision détectée, supprimer le projectile
                        it = projectiles.erase(it);
                        Poop1->mCurrentHealth -= player.mAttack;

                    }

                    else
                    {
                        ++it;
                    }
                }

                for (auto it = enemyPoop.begin(); it != enemyPoop.end(); )
                {
                    // Si un ennemi est mort, le retirer
                    if ((*it)->isDead())
                    {
                        delete* it;
                        it = enemyPoop.erase(it); // Retourne le nouvel itérateur
                        
                        const auto& currentitems = object.items;
                        totalObjet = currentitems.size();
                        currentitem = 1;
                        object.item.setTexture(*currentitems[currentitem]);
                        object.item.setPosition(700,400);
                        object.item.setColor(sf::Color(255, 255, 255, 255));
                    
                    }
                    else
                    {
                        ++it;
                    }
                }

                if (player.collideSprite(object.Bounds(object.item), player.Bounds(player.spritePlayer)))
                {
                    object.item.setColor(sf::Color(255, 255, 255, 1));
                    object.sac.push_back(&object.goldKey);
                    itemKey = true;

                }

            }

            if (currentRoom == 2)
            {
                const auto& currentitems = object.items;
                totalObjet = currentitems.size();
                currentitem = 0;
                object.item.setTexture(*currentitems[currentitem]);
                object.item.setPosition(800, 600);

                if (shopikCollide == false)
                {
                    object.item.setColor(sf::Color(255, 255, 255, 1));
                }
                else if (shopikCollide)
                {
                    object.item.setColor(sf::Color(255, 255, 255, 255));
                }

                if (player.OtherCollision(shopik, player.Bounds(player.spritePlayer)))
                {
                    shopikCollide = true;

                    if (!takeDamage) {
                        // Le joueur perd de la vie
                        player.mCurrentHealth--;

                        // Activer l'invincibilité
                        takeDamage = true;
                        invincibilityClock.restart();
                    }

                    if (takeDamage && invincibilityClock.getElapsedTime() > invincibilityDuration) {
                        takeDamage = false; // Fin de l'invincibilité
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    {
                        player.move(-0.5f, 0.f);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                    {
                        player.move(0.5f, 0.f);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    {
                        player.move(0.f, -0.5f);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                    {
                        player.move(0.f, 0.5f);
                    }

                }

                if (player.collideSprite(object.Bounds(object.item), player.Bounds(player.spritePlayer)))
                {
                    itemCoin = true;
                    object.item.setColor(sf::Color(255, 255, 255, 1));
                    object.sac.push_back(&object.satanicCoin);

                    player.mAttack = 2;
                }

                if (player.OtherCollision(HangingMan, player.Bounds(player.spritePlayer)))
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    {
                        player.move(-0.05f, 0.f);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                    {
                        player.move(0.05f, 0.f);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    {
                        player.move(0.f, -0.05f);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                    {
                        player.move(0.f, 0.05f);
                    }

                }

                if (player.OtherCollision(HangingMan, player.Bounds(player.spritePlayer)))
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    {
                        player.move(-0.05f, 0.f);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                    {
                        player.move(0.05f, 0.f);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    {
                        player.move(0.f, -0.05f);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                    {
                        player.move(0.f, 0.05f);
                    }

                }

                if (player.DoorsCollision(door1, player.Bounds(player.spritePlayer)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                {
                    const auto& currentSheetsRoom = scene.sheetsRoom;
                    totalRoom = currentSheetsRoom.size();
                    currentRoom = 0;
                    player.setPosition(door3.getPosition());
                    scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                    player.Bounds(player.spritePlayer) = player.spritePlayer.getGlobalBounds();

                    player.Bounds(player.spritePlayer) = player.getTransform().transformRect(player.Bounds(player.spritePlayer));
                    for (auto it = projectiles.begin(); it != projectiles.end(); )
                    {
                        it = projectiles.erase(it);
                    }
                }
            }

            if (currentRoom == 3)
            {
                if (player.DoorsCollision(door2, player.Bounds(player.spritePlayer)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                {
                    const auto& currentSheetsRoom = scene.sheetsRoom;
                    totalRoom = currentSheetsRoom.size();
                    currentRoom = 4;

                    player.setPosition(door4.getPosition().x + 70, door4.getPosition().y - 40);
                    scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                    player.Bounds(player.spritePlayer) = player.spritePlayer.getGlobalBounds();

                    player.Bounds(player.spritePlayer) = player.getTransform().transformRect(player.Bounds(player.spritePlayer));
                    for (auto it = projectiles.begin(); it != projectiles.end(); )
                    {
                        it = projectiles.erase(it);
                    }
                }
                else if (player.DoorsCollision(door4, player.Bounds(player.spritePlayer)) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    const auto& currentSheetsRoom = scene.sheetsRoom;
                    totalRoom = currentSheetsRoom.size();
                    currentRoom = 0;

                    player.setPosition(door2.getPosition().x + 70, door2.getPosition().y + 180);
                    scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                    player.Bounds(player.spritePlayer) = player.spritePlayer.getGlobalBounds();

                    player.Bounds(player.spritePlayer) = player.getTransform().transformRect(player.Bounds(player.spritePlayer));
                    for (auto it = projectiles.begin(); it != projectiles.end(); )
                    {
                        it = projectiles.erase(it);
                    }
                }

                Patate1->move(delta * Patate1->speedEnemy * directionPatate1.x, delta * Patate1->speedEnemy * directionPatate1.y);
                Patate2->move(delta * Patate2->speedEnemy * directionPatate2.x, delta * Patate2->speedEnemy * directionPatate2.y);

                if (Patate1->collideSprite(Patate1->Bounds(Patate1->spritePatate), player.Bounds(player.spritePlayer)))
                {
                    if (!takeDamage) {
                        // Le joueur perd de la vie
                        player.mCurrentHealth--;

                        // Activer l'invincibilité
                        takeDamage = true;
                        invincibilityClock.restart();
                    }

                    if (takeDamage && invincibilityClock.getElapsedTime() > invincibilityDuration) {
                        takeDamage = false; // Fin de l'invincibilité
                    }
                }

                if (Patate2->collideSprite(Patate2->Bounds(Patate2->spritePatate), player.Bounds(player.spritePlayer)))
                {
                    if (!takeDamage) {
                        // Le joueur perd de la vie
                        player.mCurrentHealth--;

                        // Activer l'invincibilité
                        takeDamage = true;
                        invincibilityClock.restart();
                    }

                    if (takeDamage && invincibilityClock.getElapsedTime() > invincibilityDuration) {
                        takeDamage = false; // Fin de l'invincibilité
                    }
                }

                if (enemyShootClock.getElapsedTime().asSeconds() > enemyShootInterval)
                {
                    //std::cout << "Temps écoulé : " << enemyShootClock.getElapsedTime().asSeconds() << " secondes." << std::endl;

                    ProjectileEnemy* newProjectile = new ProjectileEnemy();
                    if (!newProjectile)
                    {
                        std::cerr << "Erreur : impossible de créer un projectile !" << std::endl;
                        return -1;
                    }

                    sf::Vector2f v = player.getPosition() - Patate1->getPosition();

                    float d = sqrt(v.x * v.x + v.y * v.y);
                    v.x = d > 0 ? v.x / d : 0;
                    v.y = d > 0 ? v.y / d : 0;

                    newProjectile->setPosition(Patate1->getPosition()); // Exemple de position fixe
                    newProjectile->directionLarve = v; // Direction du projectile

                    proenemy.push_back(newProjectile);


                    newProjectile = new ProjectileEnemy();
                    if (!newProjectile)
                    {
                        std::cerr << "Erreur : impossible de créer un projectile !" << std::endl;
                        return -1;
                    }

                    v = player.getPosition() - Patate2->getPosition();

                    d = sqrt(v.x * v.x + v.y * v.y);
                    v.x = d > 0 ? v.x / d : 0;
                    v.y = d > 0 ? v.y / d : 0;

                    newProjectile->setPosition(Patate2->getPosition()); // Exemple de position fixe
                    newProjectile->directionLarve = v; // Direction du projectile

                    proenemy.push_back(newProjectile);
                    //std::cout << "Projectile ennemi ajouté au vecteur. Taille actuelle : " << proenemy.size() << std::endl;


                    for (auto it = proenemy.begin(); it != proenemy.end(); )
                    {
                        bool collisionDetected = false;
                        // Vérifier la collision avec chaque mur (ou autre objet)
                        for (auto& wall : walls)
                        {
                            if (player.WallCollision(wall, (*it)->Bounds((*it)->spriteLarve)) && player.collideSprite(player.Bounds(player.spritePlayer), (*it)->Bounds((*it)->spriteLarve)))
                            {
                                collisionDetected = true;
                                break;  // On arrête dès qu'une collision est trouvée
                            }
                            
                        }

                        if (player.collideSprite(player.Bounds(player.spritePlayer), (*it)->Bounds((*it)->spriteLarve)))
                        {
                            player.mCurrentHealth -= Patate1->mAttack;
                        }
                        // Si une collision a été détectée, on supprime le projectile du vecteur
                        if (collisionDetected)
                        {
                            it = proenemy.erase(it);  // Supprimer le projectile
                        }
                        else
                        {
                            ++it;  // Passer au projectile suivant si pas de collision
                        }
                    }

                    enemyShootClock.restart();
                }


                for (auto it = proenemy.begin(); it != proenemy.end();)
                {
                    ProjectileEnemy* proj = *it;
                    proj->move(deltaTime, 300.f);

                    if (proj->getPosition().y > 1000) // Suppression hors de l'écran
                    {
                        delete proj;
                        it = proenemy.erase(it);
                    }
                    else
                    {
                        ++it;
                    }
                }

                for (auto it = proenemy.begin(); it != proenemy.end();)
                {
                    if ((*it)->Bounds((*it)->spriteLarve).intersects(player.Bounds(player.spritePlayer)))
                    {
                        it = proenemy.erase(it);
                        player.mCurrentHealth -= Patate1->mAttack;
                    }
                    else
                    {
                        ++it;
                    }
                }

                for (auto it = projectiles.begin(); it != projectiles.end();)
                {
                    if ((*it)->Bounds((*it)->spriteLarmeBase).intersects(Patate1->Bounds(Patate1->spritePatate)))
                    {
                        if ((*it)->direction.x > 0)
                        {
                            Patate1->setPosition(Patate1->getPosition().x + 30, Patate1->getPosition().y);
                        }
                        else if ((*it)->direction.x < 0)
                        {
                            Patate1->setPosition(Patate1->getPosition().x - 30, Patate1->getPosition().y);
                        }
                        else if ((*it)->direction.y > 0)
                        {
                            Patate1->setPosition(Patate1->getPosition().x, Patate1->getPosition().y + 30);
                        }
                        else if ((*it)->direction.y < 0)
                        {
                            Patate1->setPosition(Patate1->getPosition().x, Patate1->getPosition().y - 30);
                        }

                        // Collision détectée, supprimer le projectile
                        it = projectiles.erase(it);
                        Patate1->mCurrentHealth -= player.mAttack;
                    }

                    else
                    {
                        ++it;
                    }
                }

                for (auto it = projectiles.begin(); it != projectiles.end(); )
                {
                    if ((*it)->Bounds((*it)->spriteLarmeBase).intersects(Patate2->Bounds(Patate2->spritePatate)))
                    {
                        if ((*it)->direction.x > 0)
                        {
                            Patate2->setPosition(Patate2->getPosition().x + 30, Patate2->getPosition().y);
                        }
                        else if ((*it)->direction.x < 0)
                        {
                            Patate2->setPosition(Patate2->getPosition().x - 30, Patate2->getPosition().y);
                        }
                        else if ((*it)->direction.y > 0)
                        {
                            Patate2->setPosition(Patate2->getPosition().x, Patate2->getPosition().y + 30);
                        }
                        else if ((*it)->direction.y < 0)
                        {
                            Patate2->setPosition(Patate2->getPosition().x, Patate2->getPosition().y - 30);
                        }

                        // Collision détectée, supprimer le projectile
                        it = projectiles.erase(it);
                        Patate2->mCurrentHealth -= player.mAttack;

                    }

                    else
                    {
                        ++it;
                    }
                }

                for (auto it = enemyPatate.begin(); it != enemyPatate.end(); )
                {
                    // Si un ennemi est mort, le retirer
                    if ((*it)->isDead())
                    {
                        delete* it;
                        it = enemyPatate.erase(it); // Retourne le nouvel itérateur
                    }
                    else
                    {
                        ++it;
                    }
                }
            }

            if (currentRoom == 4)
            {
                if (player.DoorsCollision(door4, player.Bounds(player.spritePlayer)) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    const auto& currentSheetsRoom = scene.sheetsRoom;
                    totalRoom = currentSheetsRoom.size();
                    currentRoom = 3;

                    player.setPosition(door2.getPosition().x + 70, door2.getPosition().y + 180);
                    scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                    player.Bounds(player.spritePlayer) = player.spritePlayer.getGlobalBounds();

                    player.Bounds(player.spritePlayer) = player.getTransform().transformRect(player.Bounds(player.spritePlayer));
                    for (auto it = projectiles.begin(); it != projectiles.end(); )
                    {
                        it = projectiles.erase(it);
                    }
                }
            }

            if (currentRoom == 12)
            {
                txtgo.setFont(font);
                txtgo.setString("Cliquez sur l'enveloppe ouverte..");
                txtgo.setCharacterSize(60);
                txtgo.setFillColor(sf::Color::Red);
                txtgo.setPosition(300, 925);

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    sf::FloatRect letterBounds = letter.getGlobalBounds();

                    if (letterBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                    {
                        const auto& currentSheetsRoom = scene.sheetsRoom;
                        totalRoom = currentSheetsRoom.size();
                        currentRoom = 13;
                        scene.room.setTexture(*currentSheetsRoom[currentRoom]);

                        scene.room.setPosition(100, 25);
                        scene.room.setTextureRect(sf::IntRect(0, 0, 610, 706));
                        scene.room.setScale(3, 3);
                    }
                }
            }

            if (currentRoom == 9 || currentRoom == 11)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))
                {
                    music.setVolume(0.f);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
                {
                    music.setVolume(10.f);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
                {
                    music.setVolume(20.f);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
                {
                    music.setVolume(30.f);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
                {
                    music.setVolume(40.f);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
                {
                    music.setVolume(50.f);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
                {
                    music.setVolume(60.f);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))
                {
                    music.setVolume(70.f);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
                {
                    music.setVolume(85.f);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))
                {
                    music.setVolume(100.f);
                }
            }

            if (player.mCurrentHealth == 11)
            {
                heart.Heart3.setTexture(heart.quartHeart);
            }
            else if (player.mCurrentHealth == 10)
            {
                heart.Heart3.setTexture(heart.middleHeart);
            }
            else if (player.mCurrentHealth == 9)
            {
                heart.Heart3.setTexture(heart.unQuartHeart);
            }
            else if (player.mCurrentHealth == 8)
            {
                heart.Heart3.setTexture(heart.emptyHeart);
            }
            else if (player.mCurrentHealth == 7)
            {
                heart.Heart2.setTexture(heart.quartHeart);
                heart.Heart3.setTexture(heart.emptyHeart);
            }
            else if (player.mCurrentHealth == 6)
            {
                heart.Heart2.setTexture(heart.middleHeart);
                heart.Heart3.setTexture(heart.emptyHeart);
            }
            else if (player.mCurrentHealth == 5)
            {
                heart.Heart2.setTexture(heart.unQuartHeart);
                heart.Heart3.setTexture(heart.emptyHeart);
            }
            else if (player.mCurrentHealth == 4)
            {
                heart.Heart2.setTexture(heart.emptyHeart);
                heart.Heart3.setTexture(heart.emptyHeart);
            }
            else if (player.mCurrentHealth == 3)
            {
                heart.Heart1.setTexture(heart.quartHeart);
                heart.Heart2.setTexture(heart.emptyHeart);
                heart.Heart3.setTexture(heart.emptyHeart);
            }
            else if (player.mCurrentHealth == 2)
            {
                heart.Heart1.setTexture(heart.middleHeart);
                heart.Heart2.setTexture(heart.emptyHeart);
                heart.Heart3.setTexture(heart.emptyHeart);
            }
            else if (player.mCurrentHealth == 1)
            {
                heart.Heart1.setTexture(heart.unQuartHeart);
                heart.Heart2.setTexture(heart.emptyHeart);
                heart.Heart3.setTexture(heart.emptyHeart);
            }
            else if (player.mCurrentHealth == 0)
            {
                heart.Heart1.setTexture(heart.emptyHeart);
                heart.Heart2.setTexture(heart.emptyHeart);
                heart.Heart3.setTexture(heart.emptyHeart);
                const auto& currentSheetsRoom = scene.sheetsRoom;
                totalRoom = currentSheetsRoom.size();
                currentRoom = 12;
                scene.room.setTexture(*currentSheetsRoom[currentRoom]);

                scene.room.setPosition(300, 0);
                scene.room.setScale(1.f, 1.f);
                scene.room.setTextureRect(sf::IntRect(0, 0, 1024, 1024));
            }
        }
        window.clear();

        window.draw(scene);
        if (isPaused)
        {
            const auto& currentSheetsRoom = scene.sheetsRoom;
            totalRoom = currentSheetsRoom.size();
            scene.room.setTexture(*currentSheetsRoom[8]);

            scene.room.setPosition(400, 150);
            scene.room.setTextureRect(sf::IntRect(0, 0, 239, 229));
            scene.room.setScale(3, 3);

            //takeDamage = true;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                const auto& currentSheetsRoom = scene.sheetsRoom;
                totalRoom = currentSheetsRoom.size();
                currentRoom = 6;
                scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                isPaused = false;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
            {
                const auto& currentSheetsRoom = scene.sheetsRoom;
                totalRoom = currentSheetsRoom.size();
                currentRoom = 11;
                scene.room.setTexture(*currentSheetsRoom[currentRoom]);

                scene.room.setPosition(400, 150);
                scene.room.setTextureRect(sf::IntRect(0, 0, 263, 225));
                scene.room.setScale(3, 3);
                isPaused = false;
            }
        }

        else
        {
            if (currentRoom == 5)
            {
                window.draw(start);
            }

            if (currentRoom == 7 || currentRoom == 9 || currentRoom == 10)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    const auto& currentSheetsRoom = scene.sheetsRoom;
                    totalRoom = currentSheetsRoom.size();
                    currentRoom = 6;
                    scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                }
            }

            if (currentRoom == 11)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    const auto& currentSheetsRoom = scene.sheetsRoom;
                    totalRoom = currentSheetsRoom.size();
                    currentRoom = 8;
                    scene.room.setTexture(*currentSheetsRoom[currentRoom]);

                    scene.room.setPosition(400, 150);
                    scene.room.setTextureRect(sf::IntRect(0, 0, 239, 229));
                    scene.room.setScale(3, 3);
                    isPaused = true;
                }
            }

            else if (currentRoom == 6)
            {
                scene.room.setPosition(0, 100);
                scene.room.setScale(3, 3);
                scene.room.setTextureRect(sf::IntRect(0, 0, 510, 596));

                window.draw(jouer);
                window.draw(options);
                window.draw(aide);
                window.draw(credits);
                window.draw(quit);
            }

            else if (currentRoom == 12)
            {
                window.draw(txtgo);
                window.draw(letter);
            }

            else if (currentRoom == 1)
            {
                const auto& currentSheetsRoom = scene.sheetsRoom;
                totalRoom = currentSheetsRoom.size();
                scene.room.setTexture(*currentSheetsRoom[currentRoom]);

                scene.room.setPosition(100, 25);//400 50
                scene.room.setTextureRect(sf::IntRect(0, 0, 460, 305));
                scene.room.setScale(3, 3);

                for (Poop* po : enemyPoop)
                {
                    window.draw(*po);
                }

                window.draw(player);
                window.draw(heart);

                const sf::Texture* currentTexture = object.item.getTexture();

                if (!itemKey && currentTexture == &object.goldKey)
                {
                    window.draw(object);
                }

                for (projectil* proj : projectiles)
                {
                    window.draw(*proj);
                }
            }

            else if (currentRoom == 3)
            {
                const auto& currentSheetsRoom = scene.sheetsRoom;
                totalRoom = currentSheetsRoom.size();
                scene.room.setTexture(*currentSheetsRoom[currentRoom]);

                scene.room.setPosition(100, 25);//400 50
                scene.room.setTextureRect(sf::IntRect(0, 0, 460, 305));
                scene.room.setScale(3, 3);

                for (Patate* pa : enemyPatate)
                {
                    window.draw(*pa);
                }
                window.draw(player);
                window.draw(heart);

                for (projectil* proj : projectiles)
                {
                    window.draw(*proj);
                }

                for (ProjectileEnemy* proj : proenemy)
                {
                    window.draw(*proj);
                }
            }

            else if (currentRoom == 2)
            {
                const auto& currentSheetsRoom = scene.sheetsRoom;
                totalRoom = currentSheetsRoom.size();
                scene.room.setTexture(*currentSheetsRoom[currentRoom]);

                scene.room.setPosition(100, 25);//400 50
                scene.room.setTextureRect(sf::IntRect(0, 0, 460, 305));
                scene.room.setScale(3, 3);

                window.draw(door1);
                window.draw(door2);
                window.draw(door3);
                window.draw(door4);
                window.draw(wall1);
                window.draw(wall2);
                window.draw(wall3);
                window.draw(wall4);
                window.draw(shopik);
                window.draw(HangingMan);

                if (!itemCoin)
                {
                    window.draw(object);
                }

                window.draw(heart);

                window.draw(player);

                for (projectil* proj : projectiles)
                {
                    window.draw(*proj);
                }
            }
            else if (currentRoom == 0 || currentRoom == 2 || currentRoom == 4)
            {
                const auto& currentSheetsRoom = scene.sheetsRoom;
                totalRoom = currentSheetsRoom.size();
                scene.room.setTexture(*currentSheetsRoom[currentRoom]);

                scene.room.setPosition(100, 25);//400 50
                scene.room.setTextureRect(sf::IntRect(0, 0, 460, 305));
                scene.room.setScale(3, 3);

                window.draw(door1);
                window.draw(door2);
                window.draw(door3);
                window.draw(door4);
                window.draw(wall1);
                window.draw(wall2);
                window.draw(wall3);
                window.draw(wall4);
                window.draw(shopik);
                window.draw(HangingMan);

                window.draw(heart);

                window.draw(player);

                for (projectil* proj : projectiles)
                {
                    window.draw(*proj);
                }
            }
        }

        window.display();
    }
	return 0;
}
