#pragma once

class student {
private:
	int scores;
public:
	student(int scores) { this->scores = scores; };
	int getscore();
};