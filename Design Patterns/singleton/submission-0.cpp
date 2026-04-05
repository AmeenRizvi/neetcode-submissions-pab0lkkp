class Singleton {
private:
    static Singleton *uniqueInstance;
    string value;
    Singleton() {}

public:

    static Singleton *getInstance() {
        if(uniqueInstance == NULL)
        {
            uniqueInstance = new Singleton();
        }
        return uniqueInstance;
    }

    string getValue() {
        return value;
    }

    void setValue(string &value) {
        this->value = value;

    }
};

Singleton* Singleton :: uniqueInstance = NULL;
