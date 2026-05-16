class Observer {
public:
    virtual void notify(string& itemName) = 0;
};

class Customer : public Observer {
private:
    string name;
    int notifications;

public:
    Customer(string& name) : name(name), notifications(0) {}

    void notify(string& itemName) override {
        notifications += 1;
    }

    int countNotifications() {
        return notifications;
    }
};

class OnlineStoreItem {
private:
    string itemName;
    int stock;
    unordered_set<Observer*>observers;

public:
    OnlineStoreItem(string& itemName, int stock) : itemName(itemName), stock(stock) {}

    void subscribe(Observer* observer) {
        observers.insert(observer);
    }

    void unsubscribe(Observer* observer) {
        observers.erase(observer);
    }

    void updateStock(int newStock) {
        if(newStock > stock)
        {
            for(auto obs : observers)
            {
                obs->notify(itemName);
            }
        }
        stock = newStock;

    }
};
