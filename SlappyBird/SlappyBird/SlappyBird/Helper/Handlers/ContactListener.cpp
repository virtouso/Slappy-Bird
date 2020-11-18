#include "ContactListener.h"



void ContactListener::BeginContact(b2Contact* contact)
{
	if (GameState::Lost)return;
	std::cout << "contact started"<<"\n";
	GameState::Lost = true;
	std::cout << "you lost buddy"<<"\n";

}

void  ContactListener::EndContact(b2Contact* contact)
{

	if (GameState::Lost)return;
	std::cout << "contact finished"<<"\n";

}

