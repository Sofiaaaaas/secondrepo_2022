#include "Cinema.h"
#include <ctime>
#include <iostream>

Cinema::Cinema(std::string name, std::string location, int avarage_visiters, std::vector<Movie> movies)
{
    this->name = name;
    this->location = location;
    this->avarage_visiters = avarage_visiters;
    this->movies = movies;
}

int Cinema::calculate_profit(std::string day)
{
    int profit = 0;
    for (int i = 0; i < movies.size(); i++)
    {
        Movie movie = movies[i];
        for (int j = 0; j < movie.days.size(); j++)
        {
            if (movie.days[j] == day)
            {
                profit += movie.get_ticket_price() * avarage_visiters;
            }
        }
    }
    return profit;
}

void Cinema::add_movie(Movie movie)
{
    this->movies.push_back(movie);
}

void Cinema::sort_by_date()
{
    Movie tmp;

    int x = 1;
    for (int i = movies.size() - 1; i >= 1; i--)
    {
        for (int j = movies.size() - 1; j >= x; j--)
        {
            time_t time1 = movies[j].get_date();
            time_t time2 = movies[j - 1].get_date();

            if (time1 < time2)
            {
                tmp = movies[j];
                this->movies[j] = movies[j - 1];
                this->movies[j - 1] = tmp;
            }
        }

        x++;
    }
}

Movie Cinema::get_movie(std::string title)
{
    for (int i = 0; i < movies.size(); i++)
    {
        if (movies[i].get_title() == title)
        {
            return movies[i];
        }
    }
    return Movie();
}

Movie Cinema::get_movie()
{
    Movie tmp = movies[0];
    for (int i = 1; i < movies.size(); i++)
    {
        if (movies[i].get_ranking() > tmp.get_ranking())
        {
            tmp = movies[i];
        }
    }
    return tmp;
}

void Cinema::print_films()
{
    std::cout << "\nCinema " << name << " in " << location << ": " << std::endl;
    for (size_t i = 0; i < movies.size(); i++)
    {
        std::cout << "\nFilm " << i + 1 << ":" << std::endl;
        movies[i].print();
    }
}
