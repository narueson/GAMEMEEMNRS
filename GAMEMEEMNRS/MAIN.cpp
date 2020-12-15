
#include<SFML/Graphics.hpp>
#include<sstream>
#include <SFML/Audio.hpp>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<thread>
#include<time.h>



using namespace sf;
using namespace std;



void mood();
void level2();
void mainGame();
void stoneMovement();
void scor();
int settings();
void death(int);
bool k = 1;
int goingDown[27][48];
int goDownAfter = 7;

SoundBuffer sound1Buffer;
Sound sound1;

void monstermotion(Sprite& smonster, Sprite& smonster1, Sprite& smonster2, Sprite& smonster3);

int score, x, y;
bool checkbrightness = 1;
int gameMap[27][48];


int main()
{
	int pressCounter = 0;


	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 48; j++)
			goingDown[i][j] = goDownAfter;
	}


	RenderWindow window(VideoMode(1920, 1080), "GAMEMEEMNRS",Style::Fullscreen);
	Font fo;
	Texture background;
	background.loadFromFile("graphics/score.png");
	fo.loadFromFile("font/font1.ttf");
	Sprite backg(background);


	Text play, setting, score, checkedplay, checkedsettings, checkedscore, exit, checkedexit;


	play.setFont(fo);
	play.setString("play");
	play.setCharacterSize(120);
	play.setFillColor(Color::Red);
	play.setPosition(770, 100);

	checkedplay.setFont(fo);
	checkedplay.setString("play");
	checkedplay.setCharacterSize(120);
	checkedplay.setFillColor(Color::Yellow);
	checkedplay.setPosition(770, 100);

	setting.setFont(fo);
	setting.setString("setings");
	setting.setCharacterSize(120);
	setting.setFillColor(Color::Red);
	setting.setPosition(770, 300);

	checkedsettings.setFont(fo);
	checkedsettings.setString("setings");
	checkedsettings.setCharacterSize(120);
	checkedsettings.setFillColor(Color::Yellow);
	checkedsettings.setPosition(770, 300);

	score.setFont(fo);
	score.setString("score");
	score.setCharacterSize(120);
	score.setFillColor(Color::Red);
	score.setPosition(770, 500);

	checkedscore.setFont(fo);
	checkedscore.setString("score");
	checkedscore.setCharacterSize(120);
	checkedscore.setFillColor(Color::Yellow);
	checkedscore.setPosition(770, 500);

	exit.setFont(fo);
	exit.setString("exit");
	exit.setCharacterSize(120);
	exit.setFillColor(Color::Red);
	exit.setPosition(770, 700);

	checkedexit.setFont(fo);
	checkedexit.setString("exit");
	checkedexit.setCharacterSize(120);
	checkedexit.setFillColor(Color::Yellow);
	checkedexit.setPosition(770, 700);
	
	
	//prepare the sound
	sound1Buffer.loadFromFile("sound/sound1.wav");
	sound1.setBuffer(sound1Buffer);
	sound1.setLoop(true);
	sound1.play();
	if (k == 0) {
		sound1.stop();
	}


	while (window.isOpen())
	{


		if (pressCounter > 3 || pressCounter < 0)
			pressCounter = 0;


		Event chose;
		while (window.pollEvent(chose))
		{

			switch (chose.type) {
			case Event::KeyPressed:
				switch (chose.key.code)
				{
				case Keyboard::Down:
					pressCounter++; break;
				case Keyboard::Up:
					pressCounter--; break;


				default:
					break;
				}
			}
		}
		window.clear();

		switch (pressCounter)
		{
		case 0:
			window.draw(backg);
			window.draw(checkedplay);
			window.draw(setting);
			window.draw(score);
			window.draw(exit);
			break;
		case 1:
			window.draw(backg);
			window.draw(play);
			window.draw(checkedsettings);
			window.draw(score);
			window.draw(exit);
			break;
		case 2:
			window.draw(backg);
			window.draw(play);
			window.draw(setting);
			window.draw(checkedscore);
			window.draw(exit);
			break;
		case 3:
			window.draw(backg);
			window.draw(play);
			window.draw(setting);
			window.draw(score);
			window.draw(checkedexit);
			break;
		}
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			switch (pressCounter)
			{
			case 0:
				window.close();
				mood();
				break;
			case 1:   window.close();
				settings(); break;
			case 2:
				window.close();
				scor();
				break;
			case 3:
				window.close();
			}
		}





		window.display();



	}


}

void mood()

{

	sound1.play();
	if (k == 0) {
		sound1.stop();
	}
	int pressCounter = 0;
	cout << '+';
	RenderWindow WINDOW(VideoMode(1920, 1080), "GAMEMEEMNRS",Style::Fullscreen);
	Font fo;
	Texture background, sannd, seea;
	background.loadFromFile("graphics/score.png");
	fo.loadFromFile("font/font1.ttf");
	Sprite backg(background), sea(seea), sand(sannd);
	Text insand, insea, checkedinsea, checkedinsand;
	insand.setFont(fo);
	insand.setString("LET'S GO!!");
	sannd.loadFromFile("graphics/sand.jpg");
	insand.setCharacterSize(120);
	insand.setFillColor(Color::Red);
	insand.setPosition(700, 500);
	insea.setFont(fo);
	insea.setString("");

	insea.setCharacterSize(120);
	insea.setFillColor(Color::Yellow);
	insea.setPosition(1500, 250);



	checkedinsea.setFont(fo);
	checkedinsea.setString("");
	checkedinsea.setCharacterSize(120);
	checkedinsea.setFillColor(Color::Red);
	checkedinsea.setPosition(1500, 250);

	checkedinsand.setFont(fo);
	checkedinsand.setString("LET'S GO!!");
	checkedinsand.setCharacterSize(120);
	checkedinsand.setFillColor(Color::Yellow);
	checkedinsand.setPosition(700, 500);

	while (WINDOW.isOpen()) {
		Event even;
		while (WINDOW.pollEvent(even)) {

			if (pressCounter > 2 || pressCounter < 0)
				pressCounter = 0;


			switch (even.type) {
			case Event::KeyPressed:
				switch (even.key.code)
				{
				case Keyboard::Right:
					pressCounter++; break;
				case Keyboard::Left:
					pressCounter--; break;


				default:
					break;
				}
			}




			switch (pressCounter)
			{
			case 0:
				WINDOW.draw(backg);
				WINDOW.draw(checkedinsand);
				WINDOW.draw(insea);


				break;
			case 1:
				WINDOW.draw(backg);
				WINDOW.draw(insand);
				WINDOW.draw(checkedinsea);

				break;


			}
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				switch (pressCounter)
				{
				case 0:WINDOW.close();
					mainGame();

					break;
				case 1:   WINDOW.close();
					level2(); break;

				default:
					break;
				}
			}



			WINDOW.display();



		}

	}


}


void scor()
{
	sound1.play();
	if (k == 0) {
		sound1.stop();
	}

	RenderWindow window(VideoMode(1920, 1080), "GAMEMEEMNRS", Style::Fullscreen);
	Font fo;
	Texture background;
	background.loadFromFile("graphics/1111.jpg");
	Sprite sbackground;
	sbackground.setTexture(background);
	fo.loadFromFile("font/font1.ttf");
	SoundBuffer sound2Buffer;
	sound2Buffer.loadFromFile("sound/sound4.wav");
	Sound sound2;
	sound2.setBuffer(sound2Buffer);
	if (k == 1)
		sound2.play();
	Text score, player, high;
	int cameray = 0, y = 15;
	View view(FloatRect(0, 0, 1920, 1080));



	int i, max = 0;
	string numscore, maxscore;
	string content;
	ifstream scoregame("numberscore.txt");

	while (getline(scoregame, numscore))
	{

		content += numscore + "\n";

	}

	scoregame.close();
	istringstream ssi(content);
	while (ssi >> i) {
		if (i >= max)
			max = i;
		ifstream highscore("name score.txt");
		highscore >> maxscore;
		highscore.close();
	}
	high.setFont(fo);
	//high.setString(max);
	high.setCharacterSize(100);
	high.setFillColor(Color::Magenta);
	high.setPosition(1000, 120);
	stringstream d;
	d << "high score : " << max << endl << "name : " << maxscore;
	high.setString(d.str());


	score.setFont(fo);
	//score.setString(content);
	score.setCharacterSize(30);
	score.setFillColor(Color::Magenta);
	score.setPosition(630, 120);
	stringstream s;
	s << "score : " << endl << content;
	score.setString(s.str());



	string namescore;

	string content2;
	ifstream scoreplayer("nameplayer.txt");

	while (getline(scoreplayer, namescore))
	{
		content2 += namescore + "\n";
	}
	scoreplayer.close();


	player.setFont(fo);
	//player.setString(content2);
	player.setCharacterSize(30);
	player.setFillColor(Color::Magenta);
	player.setPosition(230, 120);
	stringstream p;
	p << "name : " << endl << content2;
	player.setString(p.str());



	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
				window.close();



			if (event.type == Event::KeyPressed) {

				if (Keyboard::isKeyPressed(Keyboard::Key::Up))
				{
					if (cameray > 0) {
						view.move(Vector2f(0, -y));
						cameray -= y;
					}

				}
				if (Keyboard::isKeyPressed(Keyboard::Key::Down))
				{
					if (cameray <= 1300) {
						view.move(Vector2f(0, +y));
						cameray += y;
					}

				}
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
			main();
		}


		window.setView(view);

		window.clear();
		window.draw(sbackground);
		window.draw(score);
		window.draw(player);
		window.draw(high);
		window.display();

	}
}



int settings() {
	RenderWindow win(VideoMode(500, 600), "GAMEMEEMNRS", Style::Default);
	RectangleShape shape1(Vector2f(70, 20));
	RectangleShape turn(Vector2f(35, 25));
	turn.setFillColor(Color::Black);
	turn.setPosition(Vector2f(350, 220));
	shape1.setPosition(Vector2f(350, 222.5));


	double r = 100, g = 100, b = 100;
	Texture tex;
	tex.loadFromFile("graphics/score.png");
	Sprite background(tex);
	Font fo;
	fo.loadFromFile("font/font1.ttf");

	Text option;
	Text sound;
	Text brightness;
	Text light;
	Text dark;
	Text aboutas;
	brightness.setFont(fo);
	brightness.setFillColor(Color::White);
	brightness.setString("brightness");
	brightness.setCharacterSize(40);
	brightness.setPosition(Vector2f(50, 300));
	sound.setFont(fo);
	sound.setString("sound");
	sound.setPosition(Vector2f(50, 200));
	sound.setCharacterSize(40);
	sound.setFillColor(Color::White);
	option.setFont(fo);
	option.setString("option");
	option.setPosition(Vector2f(180, 50));
	option.setCharacterSize(50);
	option.setFillColor(Color::White);

	aboutas.setFont(fo);
	aboutas.setFillColor(Color::White);
	aboutas.setString("about as");
	aboutas.setCharacterSize(40);
	aboutas.setPosition(Vector2f(50, 400));

	light.setFont(fo);
	light.setString("light");
	light.setPosition(Vector2f(350, 300));
	light.setCharacterSize(25);
	light.setFillColor(Color::White);
	dark.setFont(fo);
	dark.setString("Dark");
	dark.setPosition(Vector2f(350, 335));
	dark.setCharacterSize(25);

	dark.setFillColor(Color::White);

	sound1.play();
	while (win.isOpen())
	{
		Sleep(600);
		if (k == 1)
			sound1.play();

		Event even;
		while (win.pollEvent(even)) {
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				Sleep(100);
				k = 0;
				sound1.stop();

				turn.setPosition(Vector2f(400, 220));
				turn.setFillColor(Color::Red);
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				Sleep(100);
				if (k == false) {
					k = 1;
					sound1.play();

				}
				turn.setPosition(Vector2f(350, 220));
				turn.setFillColor(Color::Blue);

			}
		}

		background.setColor(Color(r, g, b));
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			checkbrightness = 1;
			r = 250;
			g = 250;
			b = 250;
			light.setFillColor(Color::Red);
			dark.setFillColor(Color::Black);
		}


		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			checkbrightness = false;
			r = 100;
			g = 100;
			b = 100;
			light.setFillColor(Color::Black);
			dark.setFillColor(Color::Red);
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Escape)) 
		{
			win.clear();
			return main();
		}
		win.clear();
		win.draw(background);
		win.draw(option);
		win.draw(sound);
		win.draw(brightness);
		win.draw(light);
		win.draw(dark);
		win.draw(shape1);
		win.draw(turn);
		win.display();
		win.clear();
	}
} 

int Mode1level = 1;
void mainGame()
{
	SoundBuffer sound2Buffer;
	sound2Buffer.loadFromFile("sound/sound4.wav");
	Sound sound2;
	sound2.setBuffer(sound2Buffer);
	if (k == 1) {
		//sound2.play();
		sound1.play();
	}

	if (k == 0) {
		sound1.stop();
		sound2.stop();
	}


	clock_t cl2;
	clock_t cl;
	clock_t base;
	clock_t runner;
	int seconds = clock();
	seconds = seconds / 1000;
	int timecounter1 = 2000, timecounter2 = 4000, x = 250, y = 500;
	bool entrance = 0, move = 1;
	double r = 250, g = 250, b = 250;
	if (checkbrightness)  r = 250, g = 250, b = 250;
	else  r = 100, g = 100, b = 100;



	bool deathflag = 0;

	




	int randx = 12;
	int randy = 1;
	


	VideoMode vm(1920, 1080);

	RenderWindow Window(vm, "GAMEMEEMNRS", Style::Fullscreen);
	Window.setFramerateLimit(120);

	int score = 0;
	



	//background
	Texture textureBackground, textureiron, textureblock, texturediamond, texturescorebar, door, texturesquares, monster, monster1, monster2, monster3;
	Sprite spritebackground, spriteiron, spriteblock, spritediamond, spritescorebar, dooor, spritesquares, smonster, smonster1, smonster2, smonster3;
	//background
	textureBackground.loadFromFile("graphics/sand.jpg");
	door.loadFromFile("graphics/door.jpg");
	dooor.setTexture(door);
	spritebackground.setTexture(textureBackground);
	spritebackground.setColor(Color(r, g, b));
	//frame
	textureiron.loadFromFile("graphics/iron.jpg");
	spriteiron.setTexture(textureiron);
	spriteiron.setColor(Color(r, g, b));
	//block
	textureblock.loadFromFile("graphics/rock.jpg");
	spriteblock.setTexture(textureblock);
	spriteblock.setColor(Color(r, g, b));
	//diamond
	texturediamond.loadFromFile("graphics/diamond.jpg");
	spritediamond.setTexture(texturediamond);
	spritediamond.setColor(Color(r, g, b));
	//scorebar
	texturescorebar.loadFromFile("graphics/scorebar.jpg");
	spritescorebar.setTexture(texturescorebar);
	//squares
	texturesquares.loadFromFile("graphics/squares.jpg");
	spritesquares.setTexture(texturesquares);


	monster.loadFromFile("graphics/monster.png");
	smonster.setTexture(monster);
	monster1.loadFromFile("graphics/monster.png");
	smonster1.setTexture(monster1);
	monster2.loadFromFile("graphics/monster.png");
	smonster2.setTexture(monster2);
	monster3.loadFromFile("graphics/monster.png");
	smonster3.setTexture(monster3);
	Texture Tcharc;
	Tcharc.loadFromFile("graphics/charc.png");

	Sprite Scharc(Tcharc);
	Scharc.setColor(Color(r, g, b));

	Texture Tbomb;
	Tbomb.loadFromFile("graphics/smash.png");

	Sprite Sbomb(Tbomb);
	Sbomb.setColor(Color(r, g, b));
	Text  Score, score2, timer, timer2, steps;
	Font fo;
	fo.loadFromFile("font/font1.ttf");
	Score.setFont(fo);
	Score.setString("Score :");
	Score.setCharacterSize(80);
	Score.setFillColor(Color::Cyan);
	steps.setFont(fo);
	steps.setString("steps ");
	steps.setCharacterSize(29);
	steps.setFillColor(Color::Cyan);
	timer.setFont(fo);
	timer.setString("Timer:");
	timer.setCharacterSize(80);
	timer.setFillColor(Color::Cyan);
	steps.setPosition(33 * 40, 24 * 40);
	timer.setPosition(15 * 40, 22.75 * 40);
	Score.setPosition(1 * 40, 22.75 * 40);
	stringstream pi;
	pi << score;

	gameMap[5][47] = 9;
	score2.setString(pi.str());
	score2.setPosition(8.50 * 40, 22.75 * 40);
	score2.setFont(fo);
	score2.setCharacterSize(80);
	score2.setFillColor(Color::Cyan);
	stringstream pi2;
	pi2 << seconds;
	timer2.setString(pi2.str());
	timer2.setFont(fo);
	timer2.setPosition(21 * 40, 22.75 * 40);
	timer2.setCharacterSize(80);
	timer2.setFillColor(Color::Cyan);

	//	score = 19;

	switch (Mode1level)
	{
	case 1:for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 47; ++j)
		{
			gameMap[i][j] = 1;
		}
	}

		  srand(time(0));


		  for (int i = 0; i <= 7; i++) {

			  for (int j = 0; j <= 7; j++) {

				  int x = 4 + rand() % 19;
				  int y = 4 + rand() % 44;
				  gameMap[x][y] = 2;

			  }
		  }



		  for (int i = 0; i <= 5; i++) {

			  for (int j = 0; j <= 5; j++) {

				  int x = 4 + rand() % 19;
				  int y = 4 + rand() % 44;
				  gameMap[x][y] = 3;

			  }
		  }
		  for (int i = 0; i <= 26; i++)
		  {
			  gameMap[i][0] = 4;
			  gameMap[i][47] = 4;
		  }
		  for (int i = 0; i <= 47; i++)
		  {
			  gameMap[0][i] = 4;
			  gameMap[26][i] = 4;
		  }
		  for (int i = 1; i < 47; i++) {
			  for (int j = 22; j <= 25; j++) {
				  gameMap[j][i] = 0;
			  }
		  }

		  for (int j = 1; j < 47; j++) {
			  gameMap[22][j] = 7;
		  }
		  for (int j = 1; j < 47; j++) {
			  gameMap[25][j] = 7;
		  }
		  gameMap[23][13] = 7;
		  gameMap[24][14] = 7;
		  gameMap[23][31] = 7;
		  gameMap[24][32] = 7;

		  for (int i = 1; i < 47; i++) {
			  for (int j = 22; j <= 25; j++) {
				  gameMap[j][i] = 0;
			  }
		  }

		  for (int j = 1; j < 47; j++) {
			  gameMap[22][j] = 7;
		  }
		  for (int j = 1; j < 47; j++) {
			  gameMap[25][j] = 7;
		  }
		  gameMap[23][13] = 7;
		  gameMap[24][14] = 7;
		  gameMap[23][31] = 7;
		  gameMap[24][32] = 7;
		  gameMap[24][13] = 7;
		  gameMap[24][12] = 7;
		  gameMap[24][11] = 7;
		  gameMap[23][12] = 7;
		  gameMap[23][30] = 7;
		  gameMap[23][32] = 7;
		  gameMap[23][33] = 7;
		  gameMap[24][31] = 7;
		  for (int j = 37; j < 47; j++) {
			  gameMap[24][j] = 11;
		  }
		  for (int j = 34; j < 47; j++) {
			  gameMap[23][j] = 7;
		  }


		  gameMap[randy][randx] = 5;
		  break;






		  //level 2 watch out ! 
	case 2:
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < 47; ++j)
			{
				gameMap[i][j] = 1;
			}
		}
		for (int i = 0; i <= 23; i++)
		{
			for (int j = 0; j <= 26; j++)
			{
				if (i != 12 && j > 0 && j < 26)
					gameMap[j][i] = 4;
				else {
					gameMap[j][i] = 0;
				}
			}
		}
		for (int i = 0; i <= 26; i++)
		{
			gameMap[i][0] = 4;
			gameMap[i][47] = 4;
		}
		for (int i = 0; i <= 47; i++)
		{
			gameMap[0][i] = 4;
			gameMap[26][i] = 4;
		}

		gameMap[randy][randx] = 5;

		for (int i = 7; i < 16; i++) {
			for (int j = 3; j < 20; j++) {
				if (i == 7 || i == 15)
					gameMap[i][j] = 0;
			}
		}
		for (int i = 11; i < 20; i++) {
			for (int j = 6; j < 18; j++) {
				if (i == 11 || i == 19)
					gameMap[i][j] = 0;
			}
		}
		gameMap[11][11] = 3; gameMap[15][15] = 3;

		for (int i = 1; i < 24; i++) {
			for (int j = 21; j < 22; j++) {
				gameMap[j][i] = 0;
			}
		}
		for (int i = 0; i <= 4; i++) {

			for (int j = 0; j <= 4; j++) {

				int y = 1 + rand() % 25;
				int x = 46 - rand() % 22;
				gameMap[y][x] = 2;

			}
		}




		for (int i = 0; i <= 3; i++) {

			for (int j = 0; j <= 3; j++) {

				int x = 46 - rand() % 22;
				int y = 1 + rand() % 25;
				gameMap[y][x] = 3;

			}
		}
		for (int i = 1; i < 47; i++) {
			for (int j = 22; j <= 25; j++) {
				gameMap[j][i] = 0;
			}
		}

		for (int j = 1; j < 47; j++) {
			gameMap[22][j] = 7;
		}
		for (int j = 1; j < 47; j++) {
			gameMap[25][j] = 7;
		}
		gameMap[23][13] = 7;
		gameMap[24][14] = 7;
		gameMap[23][31] = 7;
		gameMap[24][32] = 7;
		gameMap[24][13] = 7;
		gameMap[24][12] = 7;
		gameMap[24][11] = 7;
		gameMap[23][12] = 7;
		gameMap[23][30] = 7;
		gameMap[23][32] = 7;
		gameMap[23][33] = 7;
		gameMap[24][31] = 7;

		break;
	default:
		break;
	}

	while (Window.isOpen())
	{
		//clear everything
		Window.clear();


		stringstream pi;
		pi << score;

		score2.setString(pi.str());
		score2.setPosition(8.50 * 40, 22.75 * 40);
		score2.setFont(fo);
		score2.setCharacterSize(80);
		score2.setFillColor(Color::Cyan);

		seconds = clock();
		stringstream pi2;
		pi2 << seconds;
		timer2.setString(pi2.str());
		timer2.setPosition(21 * 40, 22.75 * 40);
		timer2.setCharacterSize(80);
		timer2.setFont(fo);
		timer2.setFillColor(Color::Cyan);



		b = 2;
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{

			Window.close();
			main();
		}


		for (int i = 0; i <= 26; ++i)
		{
			for (int j = 0; j <= 47; ++j)
			{
				switch (gameMap[i][j])
				{
				case 1:	spritebackground.setPosition(j * 40, i * 40);
					Window.draw(spritebackground);  break;
				case 2: spriteblock.setPosition(j * 40, i * 40);
					Window.draw(spriteblock);       break;
				case 3: spritediamond.setPosition(j * 40, i * 40);
					Window.draw(spritediamond);     break;
				case 4: spriteiron.setPosition(j * 40, i * 40);
					Window.draw(spriteiron); break;
				case 5:
					Scharc.setPosition(j * 40, i * 40);
					Window.draw(Scharc); break;
				case 10:Sbomb.setPosition(j * 40, i * 40);
					Window.draw(Sbomb); break;
				case 7:
					spritescorebar.setPosition(j * 40, i * 40);
					Window.draw(spritescorebar); break;
				case 9:dooor.setPosition(j * 40, i * 40);
					Window.draw(dooor); break;
				case 11:
					spritesquares.setPosition(j * 40, i * 40);
					Window.draw(spritesquares); break;
				default:
					break;
				}
			}
		}

		if (Mode1level == 2)
		{
			stoneMovement();
			monstermotion(smonster, smonster1, smonster2, smonster3);
			Window.draw(smonster);	Window.draw(smonster1);	Window.draw(smonster2);	Window.draw(smonster3);
		}
		else if (Mode1level == 1)
		{
			stoneMovement();
		}


		Vector2f pos = smonster.getPosition();
		int c = pos.x;
		if (gameMap[7][c / 40] == 5) {
			cout << "yes";
			death(25);

		}
		Vector2f pos1 = smonster1.getPosition();
		int b = pos1.x;
		if (gameMap[11][b / 40] == 5) {
			cout << "yes";
			death(25);

		}
		Vector2f pos2 = smonster2.getPosition();
		int d = pos2.x;
		d = d / 40;
		if (gameMap[15][d] == 5) {
			cout << "yes";
			death(25);
		}
		Vector2f pos3 = smonster3.getPosition();
		int a = pos3.x;
		a = a / 40;
		if (gameMap[19][a] == 5) {
			cout << "yes";
			death(25);
		}




		if (deathflag == 0)
		{
			Event move;
			while (Window.pollEvent(move))
			{
				b = 2;
				int k, d;

				switch (move.type) {
				case Event::KeyPressed:
					switch (move.key.code)
					{
					case Keyboard::Right:
						if (gameMap[randy][randx + 1] == 2 || gameMap[randy][randx + 1] == 4 || gameMap[randy][randx + 1] == 7)break;
						if (gameMap[randy][randx + 1] == 3) {
							score++; sound2.play();
						}

						gameMap[randy][randx] = 0;
						randx++;
						gameMap[randy][randx] = 5;

						/*		k = randy - 1;
						while (k >= 0 && (gameMap[k][randx - 1] == 2 || gameMap[k][randx - 1] == 3))
						{
						d = k + 1;
						while (d < 26 && gameMap[d][randx - 1] == 0)
						{
						swap(gameMap[d - 1][randx - 1], gameMap[d][randx - 1]);
						d++;
						}
						k--;
						}
						*/

						break;

					case Keyboard::Left:
						if (gameMap[randy][randx - 1] == 2 || gameMap[randy][randx - 1] == 4)break;
						if (gameMap[randy][randx - 1] == 3) { score++; sound2.play(); }

						gameMap[randy][randx] = 0;
						randx--; gameMap[randy][randx] = 5;


						k = randy - 1;
						while (k >= 0 && (gameMap[k][randx + 1] == 2 || gameMap[k][randx + 1] == 3))
						{
							d = k + 1;
							while (d < 26 && gameMap[d][randx + 1] == 0)
							{
								swap(gameMap[d - 1][randx + 1], gameMap[d][randx + 1]);
								d++;
							}

							k--;
						}


						break;
					case Keyboard::Up:
						if (gameMap[randy - 1][randx] == 2 || gameMap[randy - 1][randx] == 4)
							break;
						if (gameMap[randy - 1][randx] == 3) {
							score++; sound2.play();
						}

						gameMap[randy][randx] = 0;
						randy--; gameMap[randy][randx] = 5;

						break;
					case Keyboard::Down:
						if (gameMap[randy + 1][randx] == 2 || gameMap[randy + 1][randx] == 4 || gameMap[randy + 1][randx] == 7)break;
						if (gameMap[randy + 1][randx] == 3) {
							score++; sound2.play();
						}
						gameMap[randy][randx] = 0;
						randy++;
						gameMap[randy][randx] = 5;



						/*	k = randy - 2;
						while (k >= 0 && (gameMap[k][randx] == 2 || gameMap[k][randx] == 3))
						{
						d = k + 1;
						while (d < 26 && gameMap[d][randx] == 0)
						{
						swap(gameMap[d - 1][randx], gameMap[d][randx]);
						d++;
						}
						k--;
						}
						*/

						break;

					}

					//score = 20;
				case Event::KeyReleased:
					switch (move.key.code)
					{
					case Keyboard::Down:
						if (gameMap[randy][randx] == 5 && gameMap[randy - 1][randx] == 3 || gameMap[randy - 1][randx] == 2)
						{
							gameMap[randy][randx] = 10;
							gameMap[randy + 1][randx] = 10;
							gameMap[randy - 1][randx] = 10;
							gameMap[randy][randx + 1] = 10;
							gameMap[randy][randx - 1] = 10;
							gameMap[randy + 1][randx - 1] = 10;
							gameMap[randy - 1][randx + 1] = 10;
							gameMap[randy - 1][randx - 1] = 10;
							gameMap[randy + 1][randx + 1] = 10;
							death(score); deathflag = 1;
							Window.close();
						}
					}

				}

			}
		}




		//only one time entrance
		if (score == 20 && entrance == 0) {
			gameMap[5][47] = 9;
			cl = clock();


			for (int i = 0; i < 19; i++)
			{
				gameMap[i][46] = 0;
			}

			entrance = 1;

		}



		if (entrance) {
			cl2 = clock();

			if (cl2 - cl >= timecounter1 && cl2 - cl <= timecounter2)
			{
				gameMap[0][46] = 2;
				timecounter1 += 2000; timecounter2 += 2000;
			}
			cout << cl2 << "  " << cl << endl;
		}


		/*
		if (move)
		{
		base = clock(); move = 0;
		}
		runner = clock();
		if (runner - base >= x&&runner - base <= y) {
		x += 250; y += 250;
		stoneMovement();
		}
		*/

		switch (score) {
		case 2:
			gameMap[24][46] = 0;
			break;
		case 4:
			gameMap[24][45] = 0;
			break;
		case 6:
			gameMap[24][44] = 0;
			break;
		case 8:
			gameMap[24][43] = 0;
			break;
		case 10:
			gameMap[24][42] = 0;
			break;
		case 12:
			gameMap[24][41] = 0;
			break;
		case 14:
			gameMap[24][40] = 0;
			break;

		case 16:
			gameMap[24][39] = 0;
			break;
		case 18:
			gameMap[24][38] = 0;
			break;
		case 20:
			gameMap[24][37] = 0;
			break;
		default: break;


		}
		if (gameMap[5][47] == 5) { Window.close(); Mode1level = 2; mainGame(); }

		Window.draw(Score);
		Window.draw(score2);
		Window.draw(timer);
		Window.draw(timer2);
		Window.draw(steps);





		Window.display();




	}

}
int x1 = 3 * 40;
int y2 = 17 * 40;
bool arrive1 = 0, arrive = 0;

void monstermotion(Sprite& smonster, Sprite& smonster1, Sprite& smonster2, Sprite& smonster3)

{


	if (arrive == 0) {

		x1 += 2;
		smonster.setPosition(x1, 7 * 40); smonster1.setPosition(x1, 15 * 40);
		if (x1 >= 40 * 19)
		{
			arrive = 1;
		}

	}
	else if (arrive == 1)
	{
		x1 -= 2;
		smonster.setPosition(x1, 7 * 40);
		smonster1.setPosition(x1, 15 * 40);
		if (x1 < 3 * 40) arrive = 0;

	}

	if (arrive1 == 0)
	{
		y2 -= 2;
		smonster2.setPosition(y2, 11 * 40); smonster3.setPosition(y2, 19 * 40);
		if (y2 <= 6 * 40) arrive1 = 1;
	}
	else if (arrive1 == 1)
	{
		y2 += 2;
		smonster2.setPosition(y2, 11 * 40); smonster3.setPosition(y2, 19 * 40);
		if (y2 > 17 * 40) arrive1 = 0;


	}


}



void stoneMovement() {


	for (int i = 0; i <= 24; ++i)
	{
		for (int j = 0; j <= 47; ++j)
		{
			if (gameMap[i][j] == 2 && gameMap[i + 1][j] == 0)
			{
				gameMap[i][j] = 0;
				gameMap[i + 1][j] = 2;
				break;
			}
			else if (gameMap[i][j] == 3 && gameMap[i + 1][j] == 0)
			{
				gameMap[i][j] = 0;
				gameMap[i + 1][j] = 3;
				break;
			}



		}
	}

	for (int j = 47; j >= 2; j--)
	{
		for (int i = 24; i >= 2; i--)
		{
			if ((gameMap[i][j] == 2 || gameMap[i][j] == 3) && (gameMap[i - 1][j] == 3 || gameMap[i - 1][j] == 2))
			{
				if (gameMap[i][j - 1] == 0 && gameMap[i - 1][j - 1] == 0) {
					swap(gameMap[i][j - 1], gameMap[i - 1][j]); break;
				}
				else if (gameMap[i][j + 1] == 0 && gameMap[i - 1][j + 1] == 0) {
					swap(gameMap[i][j + 1], gameMap[i - 1][j]); break;
				}

			}


		}
	}





}



void death(int score) {

	SoundBuffer sound3Buffer;
	sound3Buffer.loadFromFile("sound/sound4.wav");
	Sound sound3;
	sound3.setBuffer(sound3Buffer);

	VideoMode vm(526, 296);
	RenderWindow window(vm, "GAMEMEEMNRS", Style::None);
	Texture background;
	background.loadFromFile("graphics/shfeq.png");
	Sprite sbackground;
	sbackground.setTexture(background);
	Font fo;
	fo.loadFromFile("font/font1.ttf");
	string display;

	Text text, text1, text2;
	text1.setFont(fo);
	text1.setCharacterSize(20);
	text1.setStyle(Text::Bold);
	text1.setFillColor(Color::Black);
	text1.setPosition(40, 150);
	text1.setStyle(Text::Bold);
	text1.setString("ENTER YOUR NAME : ");

	text.setFont(fo);
	text.setCharacterSize(20);
	text.setFillColor(Color::Red);
	text.setPosition(280, 150);
	text.setStyle(Text::Underlined);


	text2.setFont(fo);
	text2.setCharacterSize(20);
	text2.setStyle(Text::Bold);
	text2.setFillColor(Color::Black);
	text2.setPosition(40, 220);
	text2.setStyle(Text::Bold);
	stringstream p;
	p << "score : " << score;
	text2.setString(p.str());


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::TextEntered)
			{

				if (Keyboard::isKeyPressed(Keyboard::Return))
				{
					if (display.size() > 0)
						window.close();
				}

				stringstream p;
				p << "score : " << score;
				text2.setString(p.str());

				if (event.text.unicode >= 32 && event.text.unicode <= 126)
					display += (char)event.text.unicode;

				else if (event.text.unicode == 8 && display.size() > 0)
					display.erase(display.size() - 1);
				stringstream s;
				s << "ENTER YOUR NAME : ";
				text1.setString(s.str());
				text.setString(display);
			}
		}



		window.clear();
		window.draw(sbackground);
		window.draw(text2);
		window.draw(text);
		window.draw(text1);

		window.display();

	}

	ofstream name("nameplayer.txt", ios::app);
	name << display << endl;
	name.close();

	ofstream in("numberscore.txt", ios::app);
	in << score << endl;
	in.close();

	int i, max = 0;
	string numscore;
	string content;
	ifstream scoregame("numberscore.txt");

	while (getline(scoregame, numscore))
	{

		content += numscore + "\n";

	}

	scoregame.close();
	istringstream ssi(content);
	while (ssi >> i) {
		if (i >= max)
			max = i;

	}
	if (score >= max) {
		ofstream highscore("name score.txt");
		highscore << display;
		highscore.close();
	}
	main();





}


void level2() {

	int k = 24;
	bool attacks = 0;
	int x, y, starpos = 0, stars = 11, posx = 34, posy = 14, posx1 = 18, posy1 = 14;
	VideoMode vm(1920, 1080);
	RenderWindow Window(vm, "GAMEMEEMNRS", Style::Fullscreen);
	//background
	Texture textureBackground, grass, bubble, texturediamond, deadchar, star1, star2, star3, door, shell, attack;
	Sprite spritebackground, spritegrass, spritebubble, spritediamond, notchar, sstar1, sstar2, sstar3, dooor, sshell, sattack;
	//background
	textureBackground.loadFromFile("graphics/waterbackground1.png");
	spritebackground.setTexture(textureBackground);
	//frame
	grass.loadFromFile("graphics/grass4.png");
	spritegrass.setTexture(grass);
	//block
	bubble.loadFromFile("graphics/bubble1.png");
	spritebubble.setTexture(bubble);
	//diamond
	texturediamond.loadFromFile("graphics/diamond.jpg");
	spritediamond.setTexture(texturediamond);
	//star
	star1.loadFromFile("graphics/star.jpg");
	sstar1.setTexture(star1);
	star2.loadFromFile("graphics/star1.jpg");
	sstar2.setTexture(star2);
	star3.loadFromFile("graphics/star2.jpg");
	sstar3.setTexture(star3);
	door.loadFromFile("graphics/door.jpg");
	dooor.setTexture(door);
	Texture Tcharc;
	Tcharc.loadFromFile("graphics/char4.png");
	Sprite Scharc(Tcharc);
	deadchar.loadFromFile("graphics/notchar.png");
	notchar.setTexture(deadchar);

	Text steps;
	int randx = 3, randy = 3;
	Font fo;
	fo.loadFromFile("font/font1.ttf");
	steps.setFont(fo);
	steps.setString("steps ");
	steps.setCharacterSize(29);
	steps.setPosition(33 * 40, 24 * 40);
	steps.setFillColor(Color::Red);
	Texture Tbomb;
	Tbomb.loadFromFile("graphics/smash.png");
	Sprite Sbomb(Tbomb);
	shell.loadFromFile("graphics/shell.jpg");
	sshell.setTexture(shell);
	attack.loadFromFile("graphics/openshell.jpg");
	sattack.setTexture(attack);

	int deathsteps = 10;
	bool deathflag = 0;

	//puting the background in the array
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 48; ++j)
		{
			gameMap[i][j] = 1;
		}
	}



	//frame 

	for (int i = 0; i <= 47; i++)
	{
		//gameMap[0][i] = 4;
		gameMap[26][i] = 4;
	}
	// the maze !

	gameMap[9][2] = 6; gameMap[13][6] = 6; gameMap[20][8] = 6;
	gameMap[20][17] = 6; gameMap[24][22] = 6; gameMap[14][18] = 6;
	gameMap[17][27] = 6; gameMap[14][34] = 6; gameMap[10][22] = 6;
	gameMap[9][13] = 6; gameMap[11][30] = 6; gameMap[17][42] = 6;
	gameMap[3][29] = 6; gameMap[1][42] = 6; gameMap[5][35] = 6;
	gameMap[4][22] = 6; gameMap[2][12] = 6; gameMap[7][40] = 6;

	gameMap[26][16] = 14;

	int score = 0;
	int base = clock(), base1 = clock();
	int runner, runner1;
	int green = 250, green1 = 5000, red1 = 10000, red = 500;
	while (Window.isOpen())
	{

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{

			Window.close();
			main();
		}
		//clear everything
		Window.clear();


		for (int i = 0; i <= 26; ++i)
		{
			for (int j = 0; j <= 47; ++j)
			{
				switch (gameMap[i][j])
				{
				case 1:	spritebackground.setPosition(j * 40, i * 40);
					Window.draw(spritebackground);  break;

				case 3: spritediamond.setPosition(j * 40, i * 40);
					Window.draw(spritediamond);     break;
				case 4: spritegrass.setPosition(j * 40, i * 40);
					Window.draw(spritegrass); break;
				case 5:
					if (deathsteps)
					{
						Scharc.setPosition(j * 40, i * 40);
						Window.draw(Scharc); break;
					}
					else
					{
						notchar.setPosition(j * 40, i * 40);
						Window.draw(notchar); break;
					}
				case 9:dooor.setPosition(j * 40, i * 40);
					Window.draw(dooor); break;

				case 10:Sbomb.setPosition(j * 40, i * 40);
					Window.draw(Sbomb); break;
				case 6:spritebubble.setPosition(j * 40, i * 40);
					Window.draw(spritebubble);
					break;
				case 11:sstar1.setPosition(j * 40, i * 40);
					Window.draw(sstar1);
					break;
				case 12:sstar2.setPosition(j * 40, i * 40);
					Window.draw(sstar2);
					break;
				case 13: sstar3.setPosition(j * 40, i * 40);
					Window.draw(sstar3);
					break;
				case 14: sshell.setPosition(j * 40, i * 40);
					Window.draw(sshell); break;
				case 15:sattack.setPosition(j * 40, i * 40);
					Window.draw(sattack); break;
				default:
					break;
				}

			}
		}


		for (int j = 37; j < 47; j++) {
			gameMap[24][j] = 11;
		}

		switch (deathsteps) {
		case 9:
			gameMap[24][46] = 0;
			break;
		case 8:
			gameMap[24][45] = 0;
			break;
		case 7:
			gameMap[24][44] = 0;
			break;
		case 6:
			gameMap[24][43] = 0;
			break;
		case 5:
			gameMap[24][42] = 0;
			break;
		case 4:
			gameMap[24][41] = 0;
			break;
		case 3:
			gameMap[24][40] = 0;
			break;

		case 2:
			gameMap[24][39] = 0;
			break;
		case 1:
			gameMap[24][38] = 0;
			break;
		case 10:

			for (int j = 37; j < 47; j++) {
				gameMap[24][j] = 11;
			}

		default: break;


		}





		runner = clock();
		if (runner - base >= green && runner - base <= red)
		{
			green += 250; red += 250;

			switch (starpos)
			{
			case 0:
				gameMap[posy + 1][posx + 1] = 1; gameMap[posy1 + 1][posx1 + 1] = 1;
				starpos++; gameMap[posy][posx + 1] = stars; gameMap[posy1][posx1 + 1] = stars; stars++;
				if (stars >= 13)stars = 11; break;
			case 1: gameMap[posy][posx + 1] = 1; gameMap[posy1][posx1 + 1] = 1;
				starpos++; gameMap[posy - 1][posx + 1] = stars; gameMap[posy1 - 1][posx1 + 1] = stars; stars++;
				if (stars >= 13)stars = 11; break;
			case 2:  gameMap[posy - 1][posx + 1] = 1; gameMap[posy1 - 1][posx1 + 1] = 1;
				starpos++; gameMap[posy - 1][posx] = stars; gameMap[posy1 - 1][posx1] = stars;
				stars++;
				if (stars >= 13)stars = 11; break;
			case 3:gameMap[posy - 1][posx] = 1; gameMap[posy1 - 1][posx1] = 1;
				starpos++; gameMap[posy - 1][posx - 1] = stars; gameMap[posy1 - 1][posx1 - 1] = stars;
				stars++;
				if (stars >= 13)stars = 11; break;
			case 4: gameMap[posy - 1][posx - 1] = 1; gameMap[posy1 - 1][posx1 - 1] = 1;
				starpos++; gameMap[posy][posx - 1] = stars; gameMap[posy1][posx1 - 1] = stars;
				stars++;
				if (stars >= 13)stars = 11; break;
			case 5:gameMap[posy][posx - 1] = 1; gameMap[posy1][posx1 - 1] = 1;
				starpos++; gameMap[posy + 1][posx - 1] = stars; gameMap[posy1 + 1][posx1 - 1] = stars;
				stars++;
				if (stars >= 13)stars = 11; break;
			case 6: gameMap[posy + 1][posx - 1] = 1; gameMap[posy1 + 1][posx1 - 1] = 1;
				starpos++; gameMap[posy + 1][posx] = stars; gameMap[posy1 + 1][posx1] = stars; stars++;
				if (stars >= 13)stars = 11; break;
			case 7: gameMap[posy + 1][posx] = 1; gameMap[posy1 + 1][posx1] = 1;
				starpos++; gameMap[posy + 1][posx + 1] = stars; gameMap[posy1 + 1][posx1 + 1] = stars; stars++;
				if (stars >= 13)stars = 11;
				starpos = 0; break;
			default:
				break;
			}


			while (k >= -1 && attacks == 1)
			{
				gameMap[k + 1][16] = 1;
				gameMap[k][16] = 10;
				k--;
				break;
			}


			if (k < -1)
			{
				k = 24;
				attacks = 0;

			}


		}





		runner1 = clock();
		if (runner1 - base1 >= green1 && runner1 - base1 <= red1)
		{
			base1 += 5000; runner1 += 5000;
			if (gameMap[26][16] == 14)
			{
				gameMap[26][16] = 15;
				attacks = 1;
			}
			else
				gameMap[26][16] = 14;





		}
		if (deathflag == 0)
		{
			Event move;
			while (Window.pollEvent(move))
			{


				switch (move.type) {
				case Event::KeyPressed:
					switch (move.key.code)
					{
					case Keyboard::Right:
						if (gameMap[randy][randx + 1] == 2 || gameMap[randy][randx + 1] == 4)break;
						if (gameMap[randy][randx + 1] == 3) score++;
						if (gameMap[randy][randx + 1] == 6)deathsteps = 10;
						if (gameMap[randy][randx + 1] == 11 || gameMap[randy][randx + 1] == 10)deathflag = 1;
						gameMap[randy][randx] = 0;
						randx++; gameMap[randy][randx] = 5;
						x = randx; y = randy;
						deathsteps--;


						break;

					case Keyboard::Left:
						if (gameMap[randy][randx - 1] == 2 || gameMap[randy][randx - 1] == 4)break;
						if (gameMap[randy][randx - 1] == 3) score++;
						if (gameMap[randy][randx - 1] == 6)deathsteps = 10;
						if (gameMap[randy][randx - 1] == 11 || gameMap[randy][randx - 1] == 10)deathflag = 1;
						gameMap[randy][randx] = 0;
						randx--; gameMap[randy][randx] = 5;
						deathsteps--;
						x = randx; y = randy;



						break;
					case Keyboard::Up:
						if (gameMap[randy - 1][randx] == 2 || gameMap[randy - 1][randx] == 4)break;
						if (gameMap[randy - 1][randx] == 3) score++;
						if (gameMap[randy - 1][randx] == 6)deathsteps = 10;
						if (gameMap[randy - 1][randx] == 11 || gameMap[randy - 1][randx] == 10)deathflag = 1;
						gameMap[randy][randx] = 0;
						randy--; gameMap[randy][randx] = 5;
						deathsteps--; x = randx; y = randy;
						break;
					case Keyboard::Down:
						if (gameMap[randy + 1][randx] == 2 || gameMap[randy + 1][randx] == 4)break;
						if (gameMap[randy + 1][randx] == 3) score++;
						if (gameMap[randy + 1][randx] == 6)deathsteps = 10;
						if (gameMap[randy + 1][randx] == 11 || gameMap[randy + 1][randx] == 10)deathflag = 1;
						gameMap[randy][randx] = 0;
						randy++; gameMap[randy][randx] = 5;
						deathsteps--;
						x = randx; y = randy;


						break;

					}

				}

			}
		}
		//if (score == 50)gameMap[5][47] = 0;

		if (gameMap[5][47] == 5) { Window.close(); }

		if (deathsteps == 0)
		{
			deathflag = 1;
			//notchar.setPosition(x * 40, y * 40);
		//	gameMap[y - 1][x - 1] = 1;
		

		}

		gameMap[5][47] = 9; gameMap[4][47] = 4;
		Window.draw(steps);

		Window.display();

		if (deathflag)
		{
			Sleep(1500);
			Window.close();
			death(score);
		}
	}
}
