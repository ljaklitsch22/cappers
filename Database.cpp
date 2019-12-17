//
// Created by Lukas Jaklitsch on 12/16/19.
//

class Database
{
private:
    static Database obj;

    // private constructor to force use of
    // getInstance() to create Singleton object
    Database() {};

public:
    /*
    static Database getInstance()
    {
        if (obj == null)
            obj = new Database();
        return obj;
    }
     */
};

