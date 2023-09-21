class player
{
private:
    int score = 0;
    int wins = 0;
    
public:
    player();
    ~player();

    player();

    bool setScore(int s);
    int getScore();

    bool setWins(int w);
    int getWins();
};

player::player(/* args */)
{
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