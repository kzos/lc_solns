#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
    std::vector<int> a = { 7, 3, 2, 8, 4};
    std::unordered_map<int, int> visited;
    int target = 5;
    std::vector<int> result;
    result.resize(2);

    if(a.size() == 0)
        std::cout << "input error \n";
        //return result;

    for (int i = 0; i < a.size(); i++)
    {
        int temp = 0;
        //temp = visited.at(target - a[i]);
        auto it = visited.find(target - a[i]);
        std::cout << temp << std::endl;
        //if(temp)
        if(it != visited.end())
        {
            result[0] = visited.at(target-a[i]);//result[0] = temp;
            result[1] = i;
            std::cout << "Results are: \n";
            std::cout << result[0] << " ";
            std::cout << result[1] << "\n";
            break;
        }
        
        visited.insert(std::make_pair(a.at(i), i));
    }
    return 0;
}
