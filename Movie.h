#pragma once
#include <string>
#include <vector>

enum type
{
	ACTION,
	COMEDY,
	DRAMA,
	FANTASY,
	ADVENTURE,
	HISTORICAL,
	HORROR,
	SCIENCE_FICTION
};

class Movie
{
	double ranking;
	int ticket_price;
	int character_number;
	std::string title;
	time_t release_date;
	type genre;

public:
	Movie(int id, std::string title, type genre, int ticket_price, int character_number, double ranking, std::vector<std::string> days);
	Movie();

	void set_date();
	void print();

	time_t get_date();
	std::string get_title();
	std::string get_comment();
	int get_ranking();
	int get_ticket_price();
	int get_character_number();
	std::string get_genre();

	std::vector<std::string> days;
	std::string comment;
	int id;
};

