class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_map<int, unordered_map<string, int>> table;
        set<string> foodItem;
        set<int> tableNumber;
        for (auto order: orders) {
            foodItem.insert(order[2]);
            tableNumber.insert(stoi(order[1]));
            table[stoi(order[1])][order[2]] += 1;
        }
        vector<string> food;
        for (auto item: foodItem)
            food.push_back(item);
        vector<int> tableNo;
        for (auto no: tableNumber)
            tableNo.push_back(no);
        sort(food.begin(), food.end());
        sort(tableNo.begin(), tableNo.end());
        vector<vector<string>> result;
        vector<string> header;
        header.push_back("Table");
        for (auto item: food)
            header.push_back(item);
        result.push_back(header);
        for (auto number: tableNo) {
            vector<string> row;
            row.push_back(to_string(number));
            for (auto item: food) {
                row.push_back(to_string(table[number][item]));                
            }
            result.push_back(row);
        }
        return result;
    }
};