#include <iostream>
#include <string>
using namespace std;

class Robot
{
	private:
    	string name;
    	int hits;

	public:
    	Robot(const string& name)
    	{
    		this->name = name;
    		hits = 0;
		}

    	void hitBall(int& ballX, int& ballY, const string& direction)
		{
        	if (direction == "up")
			{
            	ballY += 1;
        	}
			else if (direction == "down")
			{
           		ballY -= 1;
        	}
			else if (direction == "left")
			{
           		ballX -= 1;
        	}
			else if (direction == "right")
			{
            	ballX += 1;
        	}
        	hits++;
    	}

    	string getName() const
		{
        	return name;
    	}
    	int getHits() const
		{
        	return hits;
    	}
};

class Ball
{
	private:
    	int x, y;
	public:
    	Ball(int x = 0, int y = 0)
    	{
    		this->x = x;
    		this->y = y;
		}
    	void move(int dx, int dy)
		{
        	x += dx;
        	y += dy;
    	}

    	int getX() const
		{
        	return x;
    	}

    	int getY() const
		{
        	return y;
    	}
};


class Goal
{
	private:
    	int goalX, goalY;
	public:
    	Goal(int x = 3, int y = 3)
    	{
    		goalX = x;
    		goalY = y;
		}

    	bool isGoalReached(int ballX, int ballY) const
		{
        	return (ballX == goalX && ballY == goalY);
    	}
};

class Team
{
	private:
    	string teamName;
    	Robot* robot;

	public:
    	Team(const string& name, Robot* robot)
    	{
    		teamName = name;
    		this->robot = robot;
		}

    	string getTeamName() const
		{
        	return teamName;
    	}

    	Robot* getRobot() const
		{
        	return robot;
    	}
};


class Game
{
	private:
    	Team* teamOne;
    	Team* teamTwo;
    	Ball ball;
    	Goal goal;
	public:
    	Game(Team* teamOne, Team* teamTwo)
    	{
    		this->teamOne = teamOne;
    		this->teamTwo = teamTwo;
    		Ball(0,0);
		}

    	void startGame() 
		{
        	play(teamOne);
        	play(teamTwo);
        	declareWinner();
    	}

    	void play(Team* team) 
		{
        	Robot* robot = team->getRobot();
        	int ballX = ball.getX(), ballY = ball.getY();
        	string direction;
        	cout << team->getTeamName() << "'s turn:" << endl;
        	while (!goal.isGoalReached(ballX, ballY))
			{
            	cout << "Ball Position: (" << ballX << ", " << ballY << ")" << endl;
            	cout << robot->getName() << ", choose direction (up, down, left, right): ";
            	cin >> direction;
            	robot->hitBall(ballX, ballY, direction);
        	}
        	cout << robot->getName() << " reached the goal with " << robot->getHits() << " hits!" << endl;
    	}

    	void declareWinner()
		{
        	int teamOneHits = teamOne->getRobot()->getHits();
        	int teamTwoHits = teamTwo->getRobot()->getHits();
        	if (teamOneHits < teamTwoHits)
			{
            	cout << teamOne->getTeamName() << " wins!" << endl;
        	}
			else if (teamTwoHits < teamOneHits)
			{
            	cout << teamTwo->getTeamName() << " wins!" << endl;
        	}
			else
			{
            	cout << "It's a draw!" << endl;
        	}
    	}
};

int main()
{
	cout<<"Nafees Uddin 24K-2526"<<endl;
    Robot robot1("Robot1");
    Robot robot2("Robot2");

    Team teamOne("Team One", &robot1);
    Team teamTwo("Team Two", &robot2);

    Game game(&teamOne, &teamTwo);
    game.startGame();

    return 0;
}