#include <cstdlib>
#include <ctime>

class dice
{
private:
    int sides = 6;

public:
    dice(/* args */);

    dice(int c);

    int roll();
};

dice::dice(int c)
{   
    std::srand(std::time(nullptr));
    this->sides = c;
}

int dice::roll(){
    return (rand() % (sides - 1 + 1) + 1);
}
