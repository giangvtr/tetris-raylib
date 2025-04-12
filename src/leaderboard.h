#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <string>
#include <vector>
#include "raylib.h"

struct PlayerScore {
    std::string playerName;
    int score;
    PlayerScore(std::string name, int points);
};

class Leaderboard {
private:
    std::vector<PlayerScore> scores;
    const int maxLeaderboardSize = 10;

public:
    Leaderboard();
    void AddScore(const std::string& playerName, int points);
    void SaveLeaderboardToFile(const std::string& filename) const;
    void LoadLeaderboardFromFile(const std::string& filename);
    void DrawLeaderboard(Font font, int x, int y, int lineSpacing, Color color) const;
    bool IsHighScore(int score) const;
};

#endif
