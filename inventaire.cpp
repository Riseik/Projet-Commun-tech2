#include "inventaire.h"


inventaire::inventaire()
{
	this->x = SIZE_TILE * 2;
	this->y = WINDOW_HEIGHT - SIZE_TILE * 4;
	this->current_item = 0;

	if (!this->hud_texture.loadFromFile("texture/inventaire_hud.png"))
	{
		std::cout << "erreur d'image" << std::endl;
	}
	this->hud_sprite.setPosition(this->x, this->y);
	this->hud_sprite.setTexture(this->hud_texture);
	this->hud_sprite.setScale(0.7f, 0.7f);
}
inventaire::~inventaire()
{

}
int inventaire::ajout(int num)
{
	for (int l = 0; l <= 8 ; l++)
	{
		if (this->inv[l] == 0)
		{
			this->inv[l] = num;
			return 1;
		}

		if (this->inv[l] == num)
		{
			return 0;
		}
	}
	return 0;
	
}
void inventaire::selection()
{

}
void inventaire::affichage(sf::RenderWindow* window)
{
	window->draw(this->hud_sprite);
	for (int l = 0; l <= 8; l++)
	{
		//std::cout << "rang =" << inv[l] << std::endl;
		switch (this->inv[l])
		{
		case 1:
			if (!this->obj_texture.loadFromFile("texture/poing1.png"))
			{
				std::cout << "erreur d'image" << std::endl;
				break;
			}
			this->obj_sprite.setPosition(l * 50 + 92, this->y + SIZE_TILE- 8);
			this->obj_sprite.setTexture(this->obj_texture);
			window->draw(this->obj_sprite);
			break;

		case 2:
			if (!this->obj_texture.loadFromFile("texture/conserve.png"))
			{
				std::cout << "erreur d'image" << std::endl;
				break;
			}
			this->obj_sprite.setPosition(l * 50 + 88, this->y + SIZE_TILE - 15);
			this->obj_sprite.setTexture(this->obj_texture);
			this->obj_sprite.setScale(1.2f, 1.2f);
			window->draw(this->obj_sprite);
			this->obj_sprite.setScale(1.0f, 1.0f);
			break;

		case 3:
			if (!this->obj_texture.loadFromFile("texture/knife2.png"))
			{
				std::cout << "erreur d'image" << std::endl;
				break;
			}
			this->obj_sprite.setPosition(l * 50 + 85, this->y + SIZE_TILE - 17);
			this->obj_sprite.setTexture(this->obj_texture);
			this->obj_sprite.setScale(1.4f, 1.4f);
			window->draw(this->obj_sprite);
			this->obj_sprite.setScale(1.0f, 1.0f);
			break;

		case 4:
			if (!this->obj_texture.loadFromFile("texture/axe.png"))
			{
				std::cout << "erreur d'image" << std::endl;
				break;
			}
			this->obj_sprite.setPosition(l * 50 + 90, this->y + SIZE_TILE - 15);
			this->obj_sprite.setTexture(this->obj_texture);
			this->obj_sprite.setScale(1.2f, 1.2f);
			window->draw(this->obj_sprite);
			this->obj_sprite.setScale(1.0f, 1.0f);
			break;

		case 5:
			if (!this->obj_texture.loadFromFile("texture/gas_masque.png"))
			{
				std::cout << "erreur d'image" << std::endl;
				break;
			}
			this->obj_sprite.setPosition(l * 50 + 90, this->y + SIZE_TILE - 15);
			this->obj_sprite.setTexture(this->obj_texture);
			this->obj_sprite.setScale(1.2f, 1.2f);
			window->draw(this->obj_sprite);
			this->obj_sprite.setScale(1.0f, 1.0f);
			break;

		default:
			break;
		}
	}
}
void inventaire::select(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Num1)
	{
		this->current_item = 0;
	}
	if (event.key.code == sf::Keyboard::Num2)
	{
		this->current_item = 1;
	}
	if (event.key.code == sf::Keyboard::Num3)
	{
		this->current_item = 2;
	}
	if (event.key.code == sf::Keyboard::Num4)
	{
		this->current_item = 3;
	}
	if (event.key.code == sf::Keyboard::Num5)
	{
		this->current_item = 4;
	}
	if (event.key.code == sf::Keyboard::Num6)
	{
		this->current_item = 5;
	}
	if (event.key.code == sf::Keyboard::Num7)
	{
		this->current_item = 6;
	}
	if (event.key.code == sf::Keyboard::Num8)
	{
		this->current_item = 7;
	}
	if (event.key.code == sf::Keyboard::Num9)
	{
		this->current_item = 8;
	}
	std::cout << "item selectionné : " << this->current_item << std::endl;
}