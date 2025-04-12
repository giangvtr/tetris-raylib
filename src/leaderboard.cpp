#include "leaderboard.h"

#include <fstream>
#include <algorithm>
#include <sstream>
#include <iomanip>

// PlayerScore constructor
PlayerScore::PlayerScore(std::string name, int points) : playerName(name), score(points) {}

Leaderboard::Leaderboard() {
    LoadLeaderboardFromFile("../../resources/score.txt");
}

void Leaderboard::AddScore(const std::string& playerName, int points) {
    PlayerScore newScore(playerName, points);
    scores.push_back(newScore);

    std::sort(scores.begin(), scores.end(), [](const PlayerScore& a, const PlayerScore& b) {
        return a.score > b.score;
    });

    if (scores.size() > maxLeaderboardSize) {
        scores.pop_back();
    }

    SaveLeaderboardToFile("../../resources/score.txt");
}

void Leaderboard::SaveLeaderboardToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    for (const auto& score : scores) {
        outFile << score.playerName << "," << score.score << "\n";  // comma separator
    }
}

void Leaderboard::LoadLeaderboardFromFile(const std::string& filename) {
    scores.clear();
    std::ifstream inFile(filename);
    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string name;
        int score;
        if (std::getline(ss, name, ',') && ss >> score) {
            scores.push_back(PlayerScore(name, score));
        }
    }
}

void Leaderboard::DrawLeaderboard(Font font, int x, int y, int lineSpacing, Color color) const {
    // Draw the header
    y += lineSpacing * 2; // Add space after title

    const int rankWidth = 2;      // Width for rank column (digits only)
    const int nameWidth = 12;     // Width for name column
    const int scoreColumnX = x + rankWidth*15 + nameWidth*12;  // Position where score column starts

    for (int i = 0; i < scores.size(); ++i) {
        std::string rank = std::to_string(i + 1) + ".";
        std::string name = scores[i].playerName;
        std::string score = std::to_string(scores[i].score);

        // Calculate positions for well-spaced columns
        float rankX = x;
        float nameX = x + rankWidth*15;

        // Draw each component separately for proper alignment
        DrawTextEx(font, rank.c_str(), {rankX, (float)(y + i * lineSpacing)}, 22, 2, color);
        DrawTextEx(font, name.c_str(), {nameX, (float)(y + i * lineSpacing)}, 22, 2, color);

        // Right-align the score by calculating its width
        float scoreWidth = MeasureTextEx(font, score.c_str(), 22, 2).x;
        DrawTextEx(font, score.c_str(), {scoreColumnX - scoreWidth, (float)(y + i * lineSpacing)}, 22, 2, color);
    }
}


bool Leaderboard::IsHighScore(int score) const {
    if (scores.size() < maxLeaderboardSize) return true;
    return score > scores.back().score;
}
