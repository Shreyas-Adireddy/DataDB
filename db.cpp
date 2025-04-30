#include <iostream>
#include <string>
#include <map>
#include <optional>

using namespace std;

class InMemoryDB {
private:
    map<string, int> db_map;
    map<string, int> tx_map;
    bool transaction_started = false;

public:
    optional<int> get(string key) {
        if (transaction_started && tx_map.find(key) != tx_map.end()) {
            return tx_map[key];
        }
        
        if (db_map.find(key) != db_map.end()) {
            return db_map[key];
        }
        
        return nullopt;
    }
    
    void put(string key, int val) {
        if (!transaction_started)
            throw runtime_error("No transaction in progress");
        
        tx_map[key] = val;
    }
    
    void begin_transaction() {
        if (transaction_started)
            throw runtime_error("Transaction already in progress");
            
        transaction_started = true;
        tx_map = db_map;
    }
    
    void commit() {
        if (!transaction_started)
            throw runtime_error("No transaction in progress");
        
        db_map = tx_map;
        transaction_started = false;
    }
    
    void rollback() {
        if (!transaction_started)
            throw runtime_error("No transaction in progress");
        
        transaction_started = false;
    }
};

void printResult(optional<int> result) {
    if (result.has_value()) {
        cout << "Value: " << result.value() << endl;
    } else {
        cout << "Value: null" << endl;
    }
}

int main() {
    InMemoryDB db;
    
    cout << "Test Case 1: Get non-existent key" << endl;
    printResult(db.get("A"));
    
    cout << "\nTest Case 2: Put without transaction" << endl;
    try {
        db.put("A", 5);
    } catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    cout << "\nTest Case 3: Begin transaction and put" << endl;
    db.begin_transaction();
    db.put("A", 5);
    cout << "After put A=5 within transaction, get(A): ";
    printResult(db.get("A"));
    
    cout << "\nTest Case 4: Update within transaction" << endl;
    db.put("A", 6);
    cout << "After updating A=6 within transaction, get(A): ";
    printResult(db.get("A"));
    
    cout << "\nTest Case 5: Commit transaction" << endl;
    db.commit();
    cout << "After commit, get(A): ";
    printResult(db.get("A"));
    
    cout << "\nTest Case 6: Commit without transaction" << endl;
    try {
        db.commit();
    } catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    cout << "\nTest Case 7: Rollback without transaction" << endl;
    try {
        db.rollback();
    } catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    cout << "\nTest Case 8: Transaction with rollback" << endl;
    printResult(db.get("B"));
    db.begin_transaction();
    db.put("B", 10);
    cout << "Within transaction after put B=10, get(B): ";
    printResult(db.get("B"));
    db.rollback();
    cout << "After rollback, get(B): ";
    printResult(db.get("B"));
    
    cout << "\nTest Case 9: Multiple operations in single transaction" << endl;
    db.begin_transaction();
    db.put("C", 100);
    db.put("D", 200);
    db.put("A", 7); 
    cout << "Within transaction: get(C)=";
    printResult(db.get("C"));
    cout << "Within transaction: get(D)=";
    printResult(db.get("D"));
    cout << "Within transaction: get(A)=";
    printResult(db.get("A"));
    db.commit();
    cout << "After commit: get(C)=";
    printResult(db.get("C"));
    cout << "After commit: get(D)=";
    printResult(db.get("D"));
    cout << "After commit: get(A)=";
    printResult(db.get("A"));
    
    return 0;
}