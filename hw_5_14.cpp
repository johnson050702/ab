#include <iostream>
#include <cmath>
#include <limits>

int main() {
    // 步骤一：定义和存储数据
    // Define and store the movie ratings data in a 2D array.
    int reviews[4][6] = {
        {0, 3, 1, 5, 2, 1},
        {1, 4, 2, 1, 4, 2},
        {2, 3, 1, 2, 4, 4},
        {3, 5, 1, 4, 2, 4}
    };

    // 步骤二：获取用户评分
    // Create an array to store user ratings and initialize with -1 (indicating no rating).
    int userRatings[6];
    for (int i = 0; i < 6; ++i) {
        userRatings[i] = -1;
    }

    // Prompt the user to input their ratings for three movies.
    std::cout << "Enter your ratings (1-5) for three movies (100-105):\n";
    for (int i = 0; i < 3; ++i) {
        int movieNumber, rating;
        std::cout << "Enter movie number and rating: ";
        std::cin >> movieNumber >> rating;
        if (movieNumber >= 100 && movieNumber <= 105 && rating >= 1 && rating <= 5) {
            userRatings[movieNumber - 100] = rating;
        }
        else {
            std::cout << "Invalid input, please try again.\n";
            --i;
        }
    }

    // 步骤三：计算距离，找到最相似的评论家
    // Calculate the Euclidean distance to find the most similar reviewer.
    int closestReviewer = -1;
    double minDistance = std::numeric_limits<double>::max();
    for (int i = 0; i < 4; ++i) {
        double distance = 0.0;
        for (int j = 0; j < 6; ++j) {
            if (userRatings[j] != -1) {
                distance += std::pow(userRatings[j] - reviews[i][j], 2);
            }
        }
        distance = std::sqrt(distance);
        if (distance < minDistance) {
            minDistance = distance;
            closestReviewer = i;
        }
    }

    // 步骤四：预测用户对其他电影的评分
    // Predict the user's interest in the other movies.
    std::cout << "Based on your ratings, the closest match is reviewer " << closestReviewer << " with a distance of " << minDistance << ".\n";
    std::cout << "Predicted ratings for the movies you haven't rated:\n";
    for (int i = 0; i < 6; ++i) {
        if (userRatings[i] == -1) {
            std::cout << "Movie " << 100 + i << ": " << reviews[closestReviewer][i] << "\n";
        }
    }

    return 0;
}
