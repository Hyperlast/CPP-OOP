#pragma once
int my_strlen(const char* str);
class Drink {
public:
    Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price);
    Drink(const Drink&);
    Drink& operator=(const Drink&);
    Drink();
    const char* get_name() const;
    int get_calories() const;
    double get_quantity() const;
    double get_price() const;

    void set_name(const char* new_name);
    void set_calories(int);
    void set_quantity(double);
    void set_price(double);

    void get_Drink();
    ~Drink();
    // Add whatever you deem needed here
private:
    char* Name;
    int Calories;
    double Quantity;
    double Price;
};