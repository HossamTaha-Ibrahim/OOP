#include <iostream>
#include <vector>
using namespace std;

void jumpIt(vector<int>, int , int&);
int main()
{
    vector <int> numbers ;
    numbers.push_back(0);
    numbers.push_back(3);
    numbers.push_back(2);
    numbers.push_back(57);
    numbers.push_back(6);
    numbers.push_back(10);
    numbers.push_back(10);
    numbers.push_back(15);
    numbers.push_back(0);
    numbers.push_back(1);
    numbers.push_back(10);
    numbers.push_back(1);
    numbers.push_back(100);
    numbers.push_back(1);

    int res = 0;
    jumpIt(numbers, 0, res);
    cout << "The minimum path will cost: " << res << endl;
    return 0;
}
void jumpIt(vector<int> nums, int startIndex, int &result){

    /** Base Condition **/
    if (startIndex == nums.size()-1 ){
        return;
    }
    else if(startIndex == nums.size() - 2){
        result += nums.at(nums.size()-1);
        return;
    }
    else if(startIndex == nums.size() - 3){
        result += nums.at(nums.size()-1);
        return;
    }

    if ((result + nums.at(startIndex+1)) < (result + nums.at(startIndex+2))){
        result += nums.at(startIndex+1);
        return jumpIt(nums, startIndex+1, result);
    }

    result += nums.at(startIndex+2);
    return jumpIt(nums, startIndex+2, result);
}
