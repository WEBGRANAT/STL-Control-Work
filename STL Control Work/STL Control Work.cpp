#include <iostream>
#include <string>
#include <list>
#include <fstream>

class Country
{
private:
	std::string m_name;
	long int m_area;
	long int m_population;
	long int m_population_denisty;

	void setPopulationDenisty()
	{
		m_population_denisty = m_population / m_area;
	}

public:
	Country()
		: m_name(""), m_area(1), m_population(0) {}

	Country(std::string name, long int area, long int population)
		: m_name(name), m_area(area), m_population(population) {}

	std::string getName()
	{
		return m_name;
	}

	long int getArea()
	{
		return m_area;
	}

	long int getPopulation()
	{
		return m_population;
	}
	
	long int getPopulationDenisty()
	{
		return m_population_denisty;
	}

};

void sortCountry()
{

}

int main()
{
	std::list<Country> country {Country("Ukraine", 603628, 41858000), Country("Poland", 312679, 38433600)};

	std::ofstream fout;
	fout.open("country.txt", std::ofstream::app);

	/*
	if (!fout.is_open())
	{
		std::cout << "Error" << '\n';
	}
	else
	{
		std::cout << "File open" << '\n';
		fout.write((char*)&country.front(), sizeof(Country));
	}
	fout.close();
	*/

	std::ifstream fin;
	fin.open("country.txt");

	if (!fin.is_open())
	{
		std::cout << "Error" << '\n';
	}
	else
	{
		std::cout << "File open" << '\n';
		Country ukraine;
		fin.read((char*)&ukraine, sizeof(Country));

		ukraine.getName();
		ukraine.getArea();
	}
	fin.close();

	return 0;
}