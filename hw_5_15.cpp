#include <iostream>
#include <cstdlib> // 包含rand()和srand()
#include <ctime>   // 包含time()
#include <string>
#include <map>

// 生成随机映射的函数
std::map<char, char> generateRandomMapping() {
    std::map<char, char> mapping;
    srand(time(0)); // 使用当前时间作为随机数生成的种子
    for (char digit = '0'; digit <= '9'; ++digit) {
        char randomNum = '1' + rand() % 3; // 生成1到3的随机数
        mapping[digit] = randomNum;
    }
    return mapping;
}

// 显示映射和读取用户输入的函数
std::string getUserResponse(const std::map<char, char>& mapping) {
    std::string response;
    // 显示PIN和NUM的对应关系
    std::cout << "PIN: ";
    for (int i = 0; i <= 9; ++i) std::cout << i << " ";
    std::cout << "\nNUM: ";
    for (int i = 0; i <= 9; ++i) std::cout << mapping.at('0' + i) << " ";
    std::cout << "\n请输入响应：";
    std::cin >> response;
    return response;
}

// 验证用户输入的函数
bool verifyResponse(const std::string& userResponse, const std::string& actualPIN, const std::map<char, char>& mapping) {
    std::string expectedResponse;
    for (char digit : actualPIN) {
        expectedResponse.push_back(mapping.at(digit));
    }
    return expectedResponse == userResponse;
}

// 主函数
int main() {
    std::string actualPIN = "12345"; // 实际的PIN码
    auto mapping = generateRandomMapping(); // 生成随机映射
    std::string userResponse = getUserResponse(mapping); // 获取用户响应

    // 验证用户输入
    if (verifyResponse(userResponse, actualPIN, mapping)) {
        std::cout << "认证成功！" << std::endl;
    }
    else {
        std::cout << "认证失败！" << std::endl;
    }

    return 0;
}
