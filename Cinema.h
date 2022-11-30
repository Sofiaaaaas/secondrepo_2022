#pragma once
#include <string>
#include <vector>
#include "Movie.h"

class Cinema
{
	int avarage_visiters;
	std::string name;
	std::string location;
	std::vector<Movie> movies;

public:
	Cinema(std::string name, std::string location, int avarage_visiters, std::vector<Movie> movies);

	int calculate_profit(std::string day);
	void add_movie(Movie movie);
	void sort_by_date();
	Movie get_movie(std::string);
	Movie get_movie();

	void print_films();
};

