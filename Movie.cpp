#include "Movie.h"
#include <iostream>
#include <ctime>

Movie::Movie(int id, std::string title, type genre, int ticket_price, int character_number, double ranking, std::vector<std::string> days)
{
	this->id = id;
	this->title = title;
	this->genre = genre;
	this->ticket_price = ticket_price;
	this->days = days;
	this->character_number = character_number;
	this->ranking = ranking;
	this->comment = "";

	this->set_date();
}

Movie::Movie()
{
	this->id = 0;
	this->title = "";
	this->ticket_price = 1;
	this->days = {};
	this->character_number = 0;
	this->ranking = 0;
	this->comment = "";
	//this->release_date = localtime(&t);
}

void Movie::set_date()
{
	int year;
	int mon;
	int day;

	time_t t = 0;
	tm* tmp = localtime(&t);

	std::cout << "Enter release date for " << this->title << " (year mounth day) : " << std::endl;
	std::cin >> year >> mon >> day;

	tmp->tm_year = year - 1900;
	tmp->tm_mon = mon - 1;
	tmp->tm_mday = day;

	this->release_date = mktime(tmp);
}

void Movie::print()
{
	std::cout << "Title - " << this->title << std::endl;
	std::cout << "Genre - " << this->get_genre() << std::endl;
	std::cout << "Ranking - " << this->ranking << std::endl;
	std::cout << "Character number - " << this->character_number << std::endl;
	std::cout << "Ticket price - " << this->ticket_price << std::endl;
	std::cout << "Comment - " << this->comment << std::endl;
	time_t t = this->release_date;
	tm* tmp = localtime(&t);
	std::cout << "Release date - " << tmp->tm_mday << "/" << tmp->tm_mon + 1 << "/" << tmp->tm_year + 1900 << std::endl;
}

int Movie::get_ticket_price()
{
	return ticket_price;
}

time_t Movie::get_date()
{
	return this->release_date;
}

std::string Movie::get_title()
{
	return title;
}

std::string Movie::get_comment()
{
	return comment;
}

int Movie::get_ranking()
{
	return ranking;
}

int Movie::get_character_number()
{
	return character_number;
}

std::string Movie::get_genre()
{
	switch (this->genre)
	{
	case(ACTION):
		return "action";
	case(COMEDY):
		return "comedy";
	case(DRAMA):
		return "drama";
	case(ADVENTURE):
		return "adventure";
	case(HISTORICAL):
		return "historical";
	case(HORROR):
		return "horror";
	case(SCIENCE_FICTION):
		return "science fiction";
	default:
		break;
	}
}
