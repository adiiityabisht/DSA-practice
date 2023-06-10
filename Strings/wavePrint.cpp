#include <iostream>
#include <vector>

using namespace std;

vector<int> wavePrint(vector<vector<int>>& arr) {
    int row=arr.size();
    int col=arr[0].size();
    vector<int> wave;
    for(int j=0; j<col; j++){
        if (j%2==0){
            for(int i=0; i<row;i++){
                wave.push_back(arr[i][j]);
            }
        }
        else{
            for(int i=row-1;i>=0;i--){
                wave.push_back(arr[i][j]);
            }
        }
    }
    return wave;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Create a 2D vector and populate it with user input
    vector<vector<int>> arr(rows, vector<int>(cols));
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    // Call the wavePrint function to get the wave print result
    vector<int> waveResult = wavePrint(arr);

    // Print the wave print result
    cout << "Wave Print Result:" << endl;
    for (int i = 0; i < waveResult.size(); i++) {
        cout << waveResult[i] << " ";
    }
    cout << endl;

    return 0;
}
