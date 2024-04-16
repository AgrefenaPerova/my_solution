#include<iostream>
#include <string>

template <typename T>
bool Compare_Cats(const T& cat1, const T& cat2) {
	if (cat1.name != cat2.name) {
		return cat1.name < cat2.name;
	}
	else if (cat1.weight != cat2.weight) {
		return cat1.weight < cat2.weight;
	}
	else {
		return cat1.age < cat2.age;
	}
}

template <typename T>
void Cats_Sort(T* cats, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (!Compare_Cats(cats[i], cats[j])) {
				std::swap(cats[i], cats[j]);
			}
		}
	}
}

class Cat {
private:
	std::string name;
	double weight;
	int age;
public:
	Cat() {};
	Cat(std::string n, double w, int a) : name(n), weight(w), age(a) {}

	friend std::istream& operator>>(std::istream& in, Cat& cat)
	{
		in >> cat.name >> cat.weight >> cat.age;
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const Cat& cat)
	{
		out << "Name: " << cat.name << " , Weight: " << cat.weight << " , Age: " << cat.age;
		return out;
	}
	//bool Inequality_Of_Cats(const Cat& b);
};
/*
bool Cat::Inequality_Of_Cats(const Cat& b)
{
	if (name != b.name)
	{
		return name < b.name;
	}
	else if (weight != b.weight)
	{
		return weight < b.weight;
	}
	else
	{
		return age < b.age;
	}
}
bool Compare_Cats(Cat& cat1, Cat& cat2) 
{
	return cat1.Inequality_Of_Cats(cat2);

}
void Cats_Sort(Cat* cats, int n) 
{
	for (int i = 0; i < n; ++i) 
	{
		for (int j = i + 1; j < n; ++j) 
		{
			if (!Compare_Cats(cats[i], cats[j])) 
			{
				std::swap(cats[i], cats[j]);
			}
		}
	}
}
*/
int main()
{
	int n;
	std::cin >> n;
	Cat* cats = new Cat[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> cats[i];
	}
	Cats_Sort(cats, n);
	for (int i = 0; i < n; ++i)
	{
		std::cout << cats[i] << std::endl;
	}
	return 0;
}