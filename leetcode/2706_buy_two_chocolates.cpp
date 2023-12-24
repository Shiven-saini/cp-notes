/* Approach-1 : Sorting
* Time-complexity : O(nlogn)
* Space-complexity : O(1)
*
*/

int buyChoco(vector<int>& prices, int money) {
    sort(prices.begin(), prices.end());
    int sum = prices[0] + prices[1];
    return sum > money ? money : money - sum;
}

int buyChoco(vector<int>& prices, int money) {
    for(int i=0; i<2; i++) {
        for (int i=0; i<prices.size(); i++) {

        }
    }
    
    
    int sum = prices[0] + prices[1];
    return sum > money ? money : money - sum;
}


void selectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}
