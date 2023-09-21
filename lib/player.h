class player
{
private:
    int score = 0;
    int wins = 0;
    string name = "Name";

public:
    player();
    ~player();

    player(string n);

    bool setName(string s);
    string getName();

    bool setScore(int s);
    int getScore();

    bool setWins(int w);
    int getWins();

    bool Passed = false;
    bool Lost = false;
    int diff = 0;
};

player::player(string n)
{
    this->name = n;
}

player::~player()
{
}

bool player::setScore(int s)
{
    this->score = s;
    return true;
}

int player::getScore()
{
    return this->score;
}

bool player::setWins(int w)
{
    this->wins = w;
    return true;
}

int player::getWins()
{
    return this->wins;
}

bool player::setName(string n)
{
    this->name = n;
    return true;
}

string player::getName()
{
    return this->name;
}