#include <iostream>
#include <vector>
using namespace std;

// O(n) time | O(1) space
void reverseShirtOrder(vector<int> &array) {
    int left = 0;
    int right = array.size() - 1;
    while(left < right) {// O(n) time
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++;
        right--;
    }
}

// O(nLog(n)) time | O(1) space
int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds, bool fastest) {
    sort(redShirtSpeeds.begin(), redShirtSpeeds.end());// O(nLog(n)) time
    sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());// O(nLog(n)) time
    if(fastest) {
        reverseShirtOrder(redShirtSpeeds);// O(n) time | O(1) space
    }
    int totalSpeed = 0;
    for(int i = 0; i < redShirtSpeeds.size(); i++) {// O(n) time
        totalSpeed += max(redShirtSpeeds[i], blueShirtSpeeds[i]);
    }
    return totalSpeed;
}

int main() {
    auto redShirtSpeeds = {5, 5, 3, 9, 2};
    auto blueShirtSpeeds = {3, 6, 7, 2, 1};
    auto fastest = true;
    cout << tandemBicycle(redShirtSpeeds, blueShirtSpeeds, fastest);
    return 0;
}
