class Singleton {
    static Singleton* instance;
    string value;
private:

    Singleton() {}

public:

    static Singleton *getInstance() {
        if(instance == NULL)
        {
            instance = new Singleton();
        }
        return instance;
    }

    string getValue() {
        return value;
    }

    void setValue(string &value) {
        this->value = value;
    }
};

Singleton* Singleton ::instance = NULL;
